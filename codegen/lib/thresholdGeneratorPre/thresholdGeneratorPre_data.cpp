//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorPre_data.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "thresholdGeneratorPre_data.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_types.h"
#include <string.h>

// Variable Definitions
unsigned int state[625];

rtRunTimeErrorInfo b_emlrtRTEI{
    64,                  // lineNo
    "assertValidSizeArg" // fName
};

rtRunTimeErrorInfo c_emlrtRTEI{
    58,                  // lineNo
    "assertValidSizeArg" // fName
};

rtRunTimeErrorInfo d_emlrtRTEI{
    37,   // lineNo
    "fft" // fName
};

rtDoubleCheckInfo emlrtDCI{
    33,                     // lineNo
    28,                     // colNo
    "bluestein_setup_impl", // fName
    "C:\\Program "
    "Files\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\bluesteinSetup.m", // pName
    4 // checkKind
};

boolean_T isInitialized_thresholdGeneratorPre{false};

//
// File trailer for thresholdGeneratorPre_data.cpp
//
// [EOF]
//
