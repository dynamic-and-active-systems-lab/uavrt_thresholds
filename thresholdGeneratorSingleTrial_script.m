% THRESHOLDGENERATORSINGLETRIAL_SCRIPT   Generate MEX-function
%  thresholdGeneratorSingleTrial_mex from thresholdGeneratorSingleTrial.
% 
% Script generated from project 'thresholdGeneratorSingleTrial.prj' on
%  22-Mar-2023.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;
cfg.EnableJIT = true;
cfg.EnableJITSilentBailOut = true;

%% Define argument types for entry-point 'thresholdGeneratorSingleTrial'.
ARGS = cell(1,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(1i,[Inf Inf],[1 1]);
ARGS{1}{2} = coder.typeof(1i,[Inf Inf Inf],[1 1 1]);
ARGS{1}{3} = coder.typeof(sparse(0),[Inf Inf],[1 1]);
ARGS{1}{4} = coder.typeof(0);

%% Invoke MATLAB Coder.
codegen -config cfg thresholdGeneratorSingleTrial -args ARGS{1}

