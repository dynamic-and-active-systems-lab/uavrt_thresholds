//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_thresholdGeneratorPost_api.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:54:21
//

#ifndef _CODER_THRESHOLDGENERATORPOST_API_H
#define _CODER_THRESHOLDGENERATORPOST_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void thresholdGeneratorPost(coder::array<real_T, 1U> *scores, real_T *mu,
                            real_T *sigma);

void thresholdGeneratorPost_api(const mxArray *prhs, int32_T nlhs,
                                const mxArray *plhs[2]);

void thresholdGeneratorPost_atexit();

void thresholdGeneratorPost_initialize();

void thresholdGeneratorPost_terminate();

void thresholdGeneratorPost_xil_shutdown();

void thresholdGeneratorPost_xil_terminate();

#endif
//
// File trailer for _coder_thresholdGeneratorPost_api.h
//
// [EOF]
//
