function [mu, sigma] = thresholdgenerator(Fs, t_p, t_ip, t_ipu, t_ipj, K)
tic
OLF = 0.5;
zetas = [0 0.5];

n_p  = ceil(t_p * Fs); %Samples per pulse
n_w  = 1 * n_p;                   %Number of elements in STFT window
n_ol = floor(OLF * n_w);      %Number of elements overlap in STFT window
n_ws = n_w - n_ol;            %Number of elements in each step of STFT

n_ip  = ceil( t_ip * Fs);
n_ipu = ceil( t_ipu * Fs);
n_ipj = ceil( t_ipj * Fs);
N    = floor( n_ip / n_ws);
M    = ceil( n_ipu / n_ws);
J    = ceil( n_ipj / n_ws);

if N < M + J
    
    warning('Minimum N must be larger than max(M) + max)J). Setting mu and sigma output to 0.')
    mu = 0;
    sigma = 0;

else

    w_time_domain = ones(n_w, 1);
    wind          = rectwin(n_w);
    nFreqBins     = n_w;

%     if ~isdeployed
%         bar = waitbar(0,'N Progress');
%     end

    Wq         = buildtimecorrelatormatrix(N, M, J, K);
    nTimeWinds = size(Wq,1);
    nSamps     = (nTimeWinds+1)*n_ws+n_ol;

    [W, ~] = weightingmatrix(w_time_domain, Fs,zetas,'centered');

    powAllFreqBins = 1;

    trials       = 1000;                             %Number of sets of synthetic noise to generate
    scores       = zeros(trials,1);                 %Preallocate the scores matrix
    Psynthall    = powAllFreqBins*nFreqBins;     %Calculate the total power in the waveform for all frequency bins. Units are W/bin * # bins = W
    xsynth       = wgn(nSamps,trials,Psynthall,'linear','complex'); %Generate the synthetic data
    [Ssynth,~,~] = stft(xsynth, Fs,'Window', wind,'OverlapLength', n_ol,'FFTLength', n_w);
    Ssynth(:,nTimeWinds+1:end,:) = [];              %Trim excess so we have the correct number of windows.

    %%%DEBUGGING
    %figure;
    %%%

    for i = 1:trials
        scores(i) = max(abs(W'*Ssynth(:,:,i)).^2 * Wq, [], 'all'); %'all' call finds max across all temporal correlation sets and frequency bins just like we do in the dectection code.
%         if ~isdeployed
%             waitbar(i/trials,bar);
%         end
        
        % %%%%DEBUGGING
        % paramEstsMaxima = evfit(-scores(1:i));
        % mu              = paramEstsMaxima(1);
        % sigma           = paramEstsMaxima(2);
        % subplot(1,2,1);
        % plot(i,mu,'r.');hold on
        % subplot(1,2,2);
        % plot(i,sigma,'r.');hold on
        %%%%
    end

%     if ~isdeployed
%         delete(bar);
%     end

    paramEstsMaxima = evfit(-scores);
    mu              = paramEstsMaxima(1);
    sigma           = paramEstsMaxima(2);

end
toc
end
