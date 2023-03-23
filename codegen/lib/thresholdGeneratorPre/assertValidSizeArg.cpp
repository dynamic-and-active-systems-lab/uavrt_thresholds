//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: assertValidSizeArg.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "assertValidSizeArg.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_data.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double varargin_1
// Return Type  : void
//
namespace coder {
namespace internal {
void assertValidSizeArg(double varargin_1)
{
  double b_varargin_1;
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
}

} // namespace internal
} // namespace coder

//
// File trailer for assertValidSizeArg.cpp
//
// [EOF]
//
