//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorPre_initialize.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "thresholdGeneratorPre_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_data.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void thresholdGeneratorPre_initialize()
{
  eml_rand_mt19937ar_stateful_init();
  isInitialized_thresholdGeneratorPre = true;
}

//
// File trailer for thresholdGeneratorPre_initialize.cpp
//
// [EOF]
//
