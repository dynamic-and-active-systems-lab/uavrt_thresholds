//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_thresholdGeneratorPre_api.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "_coder_thresholdGeneratorPre_api.h"
#include "_coder_thresholdGeneratorPre_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131626U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "thresholdGeneratorPre",                              // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static const mxArray *b_emlrt_marshallOut(const boolean_T u);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *Fs,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const sparse *u);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const coder::array<creal_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const coder::array<creal_T, 3U> &u);

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const boolean_T u
// Return Type  : const mxArray *
//
static const mxArray *b_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *Fs
//                const char_T *identifier
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *Fs,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(Fs), &thisId);
  emlrtDestroyArray(&Fs);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const sparse *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const sparse *u)
{
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateSparse(
                      &(((coder::array<real_T, 1U> *)&u->d)->data())[0],
                      &(((coder::array<int32_T, 1U> *)&u->colidx)->data())[0],
                      &(((coder::array<int32_T, 1U> *)&u->rowidx)->data())[0],
                      u->m, u->n, u->maxnz, mxDOUBLE_CLASS, mxREAL));
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const coder::array<creal_T, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const coder::array<creal_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b((emlrtCTX)sp, m, &u[0], 8);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const coder::array<creal_T, 3U> &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const coder::array<creal_T, 3U> &u)
{
  const mxArray *m;
  const mxArray *y;
  int32_T iv[3];
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = u.size(1);
  iv[2] = u.size(2);
  m = emlrtCreateNumericArray(3, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b((emlrtCTX)sp, m, &u[0], 8);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const mxArray * const prhs[6]
//                int32_T nlhs
//                const mxArray *plhs[4]
// Return Type  : void
//
void thresholdGeneratorPre_api(const mxArray *const prhs[6], int32_T nlhs,
                               const mxArray *plhs[4])
{
  coder::array<creal_T, 3U> Ssynth;
  coder::array<creal_T, 2U> W;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  sparse Wq;
  real_T Fs;
  real_T K;
  real_T t_ip;
  real_T t_ipj;
  real_T t_ipu;
  real_T t_p;
  boolean_T success;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  Fs = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "Fs");
  t_p = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "t_p");
  t_ip = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "t_ip");
  t_ipu = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "t_ipu");
  t_ipj = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "t_ipj");
  K = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "K");
  // Invoke the target function
  thresholdGeneratorPre(Fs, t_p, t_ip, t_ipu, t_ipj, K, W, Ssynth, &Wq,
                        &success);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&st, W);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(&st, Ssynth);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(&Wq);
  }
  if (nlhs > 3) {
    plhs[3] = b_emlrt_marshallOut(success);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void thresholdGeneratorPre_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  thresholdGeneratorPre_xil_terminate();
  thresholdGeneratorPre_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void thresholdGeneratorPre_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void thresholdGeneratorPre_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// File trailer for _coder_thresholdGeneratorPre_api.cpp
//
// [EOF]
//
