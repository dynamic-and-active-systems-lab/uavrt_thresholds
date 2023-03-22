% THRESHOLDGENERATORPRE_SCRIPT   Generate static library thresholdGeneratorPre
%  from thresholdGeneratorPre.
% 
% Script generated from project 'thresholdGeneratorPre.prj' on 22-Mar-2023.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.EmbeddedCodeConfig'.
cfg = coder.config('lib','ecoder',true);
cfg.HardwareImplementation.ProdEqTarget = false;
cfg.TargetLang = 'C++';
cfg.GenCodeOnly = true;
cfg.GenerateMakefile = false;
cfg.GenerateReport = false;
cfg.MaxIdLength = 1024;
cfg.ReportPotentialDifferences = false;
cfg.TargetLangStandard = 'C++11 (ISO)';
cfg.RuntimeChecks = true;

ARGS = cell(1,1);
ARGS{1} = cell(6,1);
ARGS{1}{1} = coder.typeof(0);
ARGS{1}{2} = coder.typeof(0);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0);
ARGS{1}{5} = coder.typeof(0);
ARGS{1}{6} = coder.typeof(0);
codegen -config cfg thresholdGeneratorPre -args ARGS{1}

ARGS = cell(1,1);
ARGS{1} = cell(1,1);
ARGS{1}{1} = coder.typeof(0,[Inf  1],[1 0]);
codegen -config cfg thresholdGeneratorPost -args ARGS{1}

ARGS = cell(1,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(1i,[Inf Inf],[1 1]);
ARGS{1}{2} = coder.typeof(1i,[Inf Inf Inf],[1 1 1]);
ARGS{1}{3} = coder.typeof(sparse(0),[Inf Inf],[1 1]);
ARGS{1}{4} = coder.typeof(0);
codegen -config cfg thresholdGeneratorSingleTrial -args ARGS{1}



