//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: weightingmatrix.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "weightingmatrix.h"
#include "fft.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 2U> &in2
//                int in3
//                double in4
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<creal_T, 2U> &in2, int in3, double in4)
{
  coder::array<creal_T, 1U> b_in2;
  int b_in4;
  int i;
  int loop_ub;
  i = in2.size(0);
  if (static_cast<int>(in4) == 1) {
    b_in4 = i;
  } else {
    b_in4 = static_cast<int>(in4);
  }
  b_in2.set_size(b_in4);
  b_in4 = (i != 1);
  if (static_cast<int>(in4) == 1) {
    loop_ub = i;
  } else {
    loop_ub = static_cast<int>(in4);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] = in2[i * b_in4 + in2.size(0) * in3];
  }
  coder::fft(b_in2, in1);
}

//
// File trailer for weightingmatrix.cpp
//
// [EOF]
//
