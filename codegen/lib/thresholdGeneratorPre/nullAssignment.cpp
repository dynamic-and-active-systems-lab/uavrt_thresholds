//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nullAssignment.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "nullAssignment.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include "omp.h"
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Matrix index is out of range for deletion.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : ::coder::array<creal_T, 3U> &x
//                const ::coder::array<int, 2U> &idx
// Return Type  : void
//
namespace coder {
namespace internal {
void nullAssignment(::coder::array<creal_T, 3U> &x,
                    const ::coder::array<int, 2U> &idx)
{
  static rtDoubleCheckInfo
      b_emlrtDCI{
          452,                       // lineNo
          58,                        // colNo
          "general_null_assignment", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment."
          "m", // pName
          4    // checkKind
      };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      81,               // lineNo
      "validate_inputs" // fName
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      449,                      // lineNo
      "general_null_assignment" // fName
  };
  array<creal_T, 3U> b_x;
  array<boolean_T, 2U> b;
  int k;
  int nxout;
  int sz_idx_2;
  int vlen;
  int vstride;
  int xpagesize;
  boolean_T exitg1;
  boolean_T overflow;
  overflow = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx.size(1) - 1)) {
    if (idx[k] > x.size(1)) {
      overflow = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!overflow) {
    u_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  b_x.set_size(x.size(0), x.size(1), x.size(2));
  sz_idx_2 = x.size(0) * x.size(1) * x.size(2);
  for (nxout = 0; nxout < sz_idx_2; nxout++) {
    b_x[nxout] = x[nxout];
  }
  vlen = x.size(1);
  b.set_size(1, x.size(1));
  sz_idx_2 = x.size(1);
  for (nxout = 0; nxout < sz_idx_2; nxout++) {
    b[nxout] = false;
  }
  sz_idx_2 = idx.size(1);
  if (idx.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < sz_idx_2; k++) {
    b[idx[k] - 1] = true;
  }
  nxout = 0;
  sz_idx_2 = b.size(1);
  if (b.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < sz_idx_2; k++) {
    nxout += b[k];
  }
  nxout = x.size(1) - nxout;
  sz_idx_2 = x.size(2);
  if (nxout > x.size(1)) {
    rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  if (nxout < 0) {
    rtNonNegativeError(static_cast<double>(nxout), &b_emlrtDCI);
  }
  x.set_size(x.size(0), nxout, sz_idx_2);
  vstride = b_x.size(0);
  xpagesize = vlen * b_x.size(0);
  sz_idx_2 = nxout * b_x.size(0);
  nxout = b_x.size(2);
  overflow = (vlen > 2147483646);
  for (int i{0}; i < nxout; i++) {
    int ix0;
    int iy0;
    ix0 = i * xpagesize;
    iy0 = i * sz_idx_2;
    if (overflow) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < vlen; k++) {
      if ((k + 1 > b.size(1)) || (!b[k])) {
        if (vstride > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int j{0}; j < vstride; j++) {
          x[iy0 + j] = b_x[ix0 + j];
        }
        iy0 += vstride;
      }
      ix0 += vstride;
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for nullAssignment.cpp
//
// [EOF]
//
