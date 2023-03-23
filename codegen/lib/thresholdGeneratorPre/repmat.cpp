//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: repmat.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "repmat.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_data.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &a
//                double varargin_1
//                ::coder::array<double, 2U> &b
// Return Type  : void
//
namespace coder {
void repmat(const ::coder::array<double, 2U> &a, double varargin_1,
            ::coder::array<double, 2U> &b)
{
  static rtDoubleCheckInfo
      b_emlrtDCI{
          31,       // lineNo
          14,       // colNo
          "repmat", // fName
          "C:\\Program "
          "Files\\MATLAB\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m", // pName
          4 // checkKind
      };
  double b_varargin_1;
  int ncols;
  int nrows;
  int ntilerows;
  if ((varargin_1 != std::floor(varargin_1)) || std::isinf(varargin_1) ||
      (varargin_1 < -2.147483648E+9) || (varargin_1 > 2.147483647E+9)) {
    rtErrorWithMessageID(MIN_int32_T, c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
  }
  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }
  if (!(b_varargin_1 <= 2.147483647E+9)) {
    e_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
  if (!(varargin_1 >= 0.0)) {
    rtNonNegativeError(varargin_1, &b_emlrtDCI);
  }
  b.set_size(a.size(0) * static_cast<int>(varargin_1), a.size(1));
  nrows = a.size(0);
  ncols = a.size(1);
  ntilerows = static_cast<int>(varargin_1);
  if (a.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int jcol{0}; jcol < ncols; jcol++) {
    int iacol;
    int ibmat;
    iacol = jcol * nrows;
    ibmat = jcol * (nrows * static_cast<int>(varargin_1)) - 1;
    if (static_cast<int>(varargin_1) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int itilerow{0}; itilerow < ntilerows; itilerow++) {
      int ibcol;
      ibcol = ibmat + itilerow * nrows;
      if (nrows > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int k{0}; k < nrows; k++) {
        b[(ibcol + k) + 1] = a[iacol + k];
      }
    }
  }
}

} // namespace coder

//
// File trailer for repmat.cpp
//
// [EOF]
//
