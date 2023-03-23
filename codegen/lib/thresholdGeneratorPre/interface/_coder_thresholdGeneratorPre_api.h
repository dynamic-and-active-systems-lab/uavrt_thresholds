//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_thresholdGeneratorPre_api.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

#ifndef _CODER_THRESHOLDGENERATORPRE_API_H
#define _CODER_THRESHOLDGENERATORPRE_API_H

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
  int32_T maxnz;
};
using sparse = sparse_tag_0;

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void thresholdGeneratorPre(real_T Fs, real_T t_p, real_T t_ip, real_T t_ipu,
                           real_T t_ipj, real_T K, coder::array<creal_T, 2U> *W,
                           coder::array<creal_T, 3U> *Ssynth, sparse *Wq,
                           boolean_T *success);

void thresholdGeneratorPre_api(const mxArray *const prhs[6], int32_T nlhs,
                               const mxArray *plhs[4]);

void thresholdGeneratorPre_atexit();

void thresholdGeneratorPre_initialize();

void thresholdGeneratorPre_terminate();

void thresholdGeneratorPre_xil_shutdown();

void thresholdGeneratorPre_xil_terminate();

#endif
//
// File trailer for _coder_thresholdGeneratorPre_api.h
//
// [EOF]
//
