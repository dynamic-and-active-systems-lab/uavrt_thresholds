//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorPre_terminate.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "thresholdGeneratorPre_terminate.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_data.h"
#include "omp.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void thresholdGeneratorPre_terminate()
{
  omp_destroy_nest_lock(&thresholdGeneratorPre_nestLockGlobal);
  isInitialized_thresholdGeneratorPre = false;
}

//
// File trailer for thresholdGeneratorPre_terminate.cpp
//
// [EOF]
//
