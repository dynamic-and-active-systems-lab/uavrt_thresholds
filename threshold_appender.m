function [] = threshold_appender(detectorFs, path)

fileID   = fopen(path);

if fileID == -1
    fprintf('threshold_appender error: Error opening specified path.')
    return
end

neededParameters = [4, 6, 8, 9, 10, 11];

maxLines = 1000;

t_ip1 = zeros(maxLines,1);
t_ip2 = zeros(maxLines,1);
t_ipu = zeros(maxLines,1);
t_ipj = zeros(maxLines,1);
t_p   = zeros(maxLines,1);
K     = zeros(maxLines,1);

str2Write = cell(maxLines,1);
%Specify each element to keep coder happy. 
for i = 1:maxLines
    str2Write{i} = '';
end

done = false;
lineNum = 1;
tagInd  = 1;

while ~done
    
    lineStr = fgetl(fileID);
    %Shouldn't have a trailing comma, so remove if there
    if lineStr(end) == ','
       lineStr(end) = [];
    end
    %Shouldn't have a leading comma, so remove if there
    if lineStr(1) == ','
       lineStr(1) = [];
    end

    str2Write{lineNum} = lineStr;

    if lineStr(1) ~= '#' 

        commaLocations   = find(lineStr == ',');%note regexp is not supported for code generation
        
        commaLocations   = [0, commaLocations, numel(lineStr)+1];

        for i = neededParameters
            currText = lineStr( (commaLocations(i)+1) : (commaLocations(i+1)-1) );

            currNum = real(str2double(currText));

            if isempty(currNum) || isnan(currNum)
                error('UAVRT: A tag in the list has a missing parameter. Check tag info file.')
            end

            if (i == 4 ||  i== 8 || i == 11 ) && currNum == 0
                error('UAVRT: Neither pulse duration, interpulse duration, nor K may be zero.')
            end
            
            if i == 4
                t_ip1(tagInd) = currNum*1/1000;
            elseif i == 6
                t_ip2(tagInd) = currNum*1/1000;
            elseif i == 8
                t_p(tagInd)   = currNum*1/1000;
            elseif i == 9
                t_ipu(tagInd) = currNum*1/1000;
            elseif i == 10
                t_ipj(tagInd) = currNum*1/1000;
            elseif i == 11
                K(tagInd) = currNum;
            end
        end
        
        totalUncertainty = t_ipu(tagInd) + t_ipj(tagInd) + t_p(tagInd);

        if t_ip1(tagInd) <= totalUncertainty || t_ip2(tagInd) <= totalUncertainty
                error('UAVRT: The interpulse time of each tag must be greater than the sum of the uncertainty, jitter, and pulse duration.')
        end

        
        fprintf('Generating threshold distributions for interpulse 1 of tag %u...\n',uint32(tagInd))
        [mu1, sigma1] = thresholdgenerator(detectorFs, t_p(tagInd), t_ip1(tagInd), t_ipu(tagInd), t_ipj(tagInd), K(tagInd));
        fprintf('Generating threshold distributions for interpulse 2 of tag %u...\n',uint32(tagInd))
        [mu2, sigma2] = thresholdgenerator(detectorFs, t_p(tagInd), t_ip2(tagInd), t_ipu(tagInd), t_ipj(tagInd), K(tagInd));
        
        %num2str not supported for inputs that aren't constant
        mu1str = sprintf('%.6f',mu1);
        mu2str = sprintf('%.6f',mu2);
        sigma1str = sprintf('%.6f',sigma1);
        sigma2str = sprintf('%.6f',sigma2);

        str2Add = [ ',', mu1str, ',', sigma1str, ',', mu2str, ',', sigma2str ];
        
        str2Write{lineNum} = [str2Write{lineNum}, str2Add];

        tagInd = tagInd +1;
    end

    lineNum = lineNum + 1;
    done = feof(fileID) == 1 ;
end
fprintf('Threshold generation complete. Appending tag info file.\n')
fclose(fileID);

maxLineNum = lineNum - 1;

fileID = fopen(path, 'w');

for i = 1:maxLineNum
    fprintf(fileID,'%s\n',str2Write{i});
end

fclose(fileID);

fprintf('Process complete.\n')

end






% 
% id_Type                     = '%u';%1
% name_Type                   = '%s';%2
% freq_hz_Type                = '%f';%3
% ip_msecs_1_Type             = '%u';%4 ---
% ip_msecs_1_id_Type          = '%s';%5
% ip_msecs_2_Type             = '%u';%6 ---
% ip_msecs_2_id_Type          = '%s';%7
% pulse_width_msecs_Type      = '%u';%8 ---
% ip_uncertainty_msecs_Type   = '%u';%9 ---
% ip_jitter_msecs_Type        = '%u';%10 ---
% k_Type                      = '%u';%11 ---
% false_alarm_Type            = '%f';%12
% mu1_Type                    = '%f';%13
% sigma1_Type                 = '%f';%14
% mu2_Type                    = '%f';%15
% Sigma2_Type                 = '%f';%16
% delimiter                   = ',';


% formatSpec = [id_Type,delimiter,...
%     name_Type,delimiter,...
%     freq_hz_Type,delimiter,...
%     ip_msecs_1_Type,delimiter,...
%     ip_msecs_1_id_Type,delimiter,...
%     ip_msecs_2_Type, delimiter,...
%     ip_msecs_2_id_Type, delimiter,...
%     pulse_width_msecs_Type, delimiter,...
%     ip_uncertainty_msecs_Type, delimiter,...
%     ip_jitter_msecs_Type, delimiter,...
%     k_Type, delimiter, ...
%     false_alarm_Type, delimiter,...
%     mu1_Type, delimiter,...
%     sigma1_Type, delimiter,...
%     mu2_Type, delimiter,...
%     Sigma2_Type];
