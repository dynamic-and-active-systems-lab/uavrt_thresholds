//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colon.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "colon.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double a
//                double b
//                ::coder::array<double, 2U> &y
// Return Type  : void
//
namespace coder {
void eml_float_colon(double a, double b, ::coder::array<double, 2U> &y)
{
  static rtRunTimeErrorInfo e_emlrtRTEI{
      419,              // lineNo
      "assert_pmaxsize" // fName
  };
  double apnd;
  double cdiff;
  double ndbl;
  int n;
  ndbl = std::floor((b - a) + 0.5);
  apnd = a + ndbl;
  cdiff = apnd - b;
  if (std::abs(cdiff) <
      4.4408920985006262E-16 * std::fmax(std::abs(a), std::abs(b))) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = a + (ndbl - 1.0);
  } else {
    ndbl++;
  }
  if (ndbl >= 0.0) {
    n = static_cast<int>(ndbl);
  } else {
    n = 0;
  }
  if (ndbl > 2.147483647E+9) {
    e_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  y.set_size(1, n);
  if (n > 0) {
    y[0] = a;
    if (n > 1) {
      int nm1d2;
      y[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (int k{0}; k <= nm1d2 - 2; k++) {
        y[k + 1] = a + (static_cast<double>(k) + 1.0);
        y[(n - k) - 2] = apnd - (static_cast<double>(k) + 1.0);
      }
      if (nm1d2 << 1 == n - 1) {
        y[nm1d2] = (a + apnd) / 2.0;
      } else {
        y[nm1d2] = a + static_cast<double>(nm1d2);
        y[nm1d2 + 1] = apnd - static_cast<double>(nm1d2);
      }
    }
  }
}

} // namespace coder

//
// File trailer for colon.cpp
//
// [EOF]
//
