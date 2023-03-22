//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: evfit.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:50
//

// Include Files
#include "evfit.h"
#include "blockedSummation.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Type Definitions
struct rtEqualityCheckInfo {
  int nDims;
  int lineNo;
  int colNo;
  const char *fName;
  const char *pName;
};

// Function Declarations
static void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                        const rtEqualityCheckInfo *aInfo);

static void times(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2,
                  const coder::array<double, 1U> &in3);

// Function Definitions
//
// Arguments    : const int aDim1
//                const int aDim2
//                const rtEqualityCheckInfo *aInfo
// Return Type  : void
//
static void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                        const rtEqualityCheckInfo *aInfo)
{
  std::stringstream outStream;
  ((((((outStream << "Size mismatch error on dimension ") << aInfo->nDims)
      << ": expected ")
     << aDim1)
    << " or a singleton, but actual size is ")
   << aDim2)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo->fName) << " (line ") << aInfo->lineNo)
      << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
static void times(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2,
                  const coder::array<double, 1U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] * in3[i * stride_1_0];
  }
}

//
// Arguments    : double sigma
//                const ::coder::array<double, 1U> &x
//                double xbarWgtUnc
// Return Type  : double
//
namespace coder {
double lkeqn(double sigma, const ::coder::array<double, 1U> &x,
             double xbarWgtUnc)
{
  static rtEqualityCheckInfo emlrtECI{
      1,                                                        // nDims
      273,                                                      // lineNo
      34,                                                       // colNo
      "lkeqn",                                                  // fName
      "C:\\Program Files\\MATLAB\\toolbox\\stats\\eml\\evfit.m" // pName
  };
  array<double, 1U> b_x;
  array<double, 1U> wt;
  int nx;
  wt.set_size(x.size(0));
  nx = x.size(0);
  for (int k{0}; k < nx; k++) {
    wt[k] = x[k] / sigma;
  }
  nx = wt.size(0);
  if (wt.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nx; k++) {
    wt[k] = std::exp(wt[k]);
  }
  if ((x.size(0) != wt.size(0)) && ((x.size(0) != 1) && (wt.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(x.size(0), wt.size(0), &emlrtECI);
  }
  if (x.size(0) == wt.size(0)) {
    b_x.set_size(x.size(0));
    nx = x.size(0);
    for (int k{0}; k < nx; k++) {
      b_x[k] = x[k] * wt[k];
    }
  } else {
    times(b_x, x, wt);
  }
  return (sigma + xbarWgtUnc) -
         blockedSummation(b_x, b_x.size(0)) / blockedSummation(wt, wt.size(0));
}

} // namespace coder

//
// File trailer for evfit.cpp
//
// [EOF]
//
