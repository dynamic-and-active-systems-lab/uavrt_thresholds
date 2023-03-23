//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_thresholdGeneratorSingleTrial_api.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:54:30
//

#ifndef _CODER_THRESHOLDGENERATORSINGLETRIAL_API_H
#define _CODER_THRESHOLDGENERATORSINGLETRIAL_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
struct sparse_tag_0 {
  coder::array<real_T, 1U> d;
  coder::array<int32_T, 1U> colidx;
  coder::array<int32_T, 1U> rowidx;
  int32_T m;
  int32_T n;
};
using sparse = sparse_tag_0;

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
real_T thresholdGeneratorSingleTrial(coder::array<creal_T, 2U> *W,
                                     coder::array<creal_T, 3U> *Ssynth,
                                     sparse *Wq, real_T i);

void thresholdGeneratorSingleTrial_api(const mxArray *const prhs[4],
                                       const mxArray **plhs);

void thresholdGeneratorSingleTrial_atexit();

void thresholdGeneratorSingleTrial_initialize();

void thresholdGeneratorSingleTrial_terminate();

void thresholdGeneratorSingleTrial_xil_shutdown();

void thresholdGeneratorSingleTrial_xil_terminate();

#endif
//
// File trailer for _coder_thresholdGeneratorSingleTrial_api.h
//
// [EOF]
//
