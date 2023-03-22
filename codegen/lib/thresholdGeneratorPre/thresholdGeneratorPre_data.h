//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorPre_data.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

#ifndef THRESHOLDGENERATORPRE_DATA_H
#define THRESHOLDGENERATORPRE_DATA_H

// Include Files
#include "rtwtypes.h"
#include "thresholdGeneratorPre_types.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Variable Declarations
extern unsigned int state[625];
extern omp_nest_lock_t thresholdGeneratorPre_nestLockGlobal;
extern rtRunTimeErrorInfo b_emlrtRTEI;
extern rtRunTimeErrorInfo c_emlrtRTEI;
extern rtRunTimeErrorInfo d_emlrtRTEI;
extern rtDoubleCheckInfo emlrtDCI;
extern boolean_T isInitialized_thresholdGeneratorPre;

#endif
//
// File trailer for thresholdGeneratorPre_data.h
//
// [EOF]
//
