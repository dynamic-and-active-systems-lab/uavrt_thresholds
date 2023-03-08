% TAGFILETHRESHOLDAPPENDER_CODEGEN_SCRIPT   Generate executable
%  tagFileThresholdAppender from tagFileThresholdAppender.
% 
% Script generated from project 'tagFileThresholdAppender.prj' on 08-Mar-2023.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.CodeConfig'.
cfg = coder.config('exe','ecoder',false);
cfg.CustomInclude = { '/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/uavrt_thresholds/CustomMains' };
cfg.CustomSource = { '/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/uavrt_thresholds/CustomMains/main.c' };
cfg.GenerateExampleMain = 'DoNotGenerate';
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = false;

cfg.RuntimeChecks = true;


%% Define argument types for entry-point 'tagFileThresholdAppender'.
ARGS = cell(1,1);
ARGS{1} = cell(2,1);
ARGS{1}{1} = coder.typeof(0);
ARGS{1}{2} = coder.typeof('X',[1 200],[0 1]);

%% Invoke MATLAB Coder.
codegen -config cfg threshold_appender -args ARGS{1}

