//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sparse.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:59
//

// Include Files
#include "sparse.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_d
//                const ::coder::array<int, 1U> &b_colidx
//                const ::coder::array<int, 1U> &b_rowidx
//                int b_m
//                int b_n
// Return Type  : void
//
namespace coder {
void sparse::init(const ::coder::array<double, 1U> &b_d,
                  const ::coder::array<int, 1U> &b_colidx,
                  const ::coder::array<int, 1U> &b_rowidx, int b_m, int b_n)
{
  int loop_ub;
  d.set_size(b_d.size(0));
  loop_ub = b_d.size(0);
  for (int i{0}; i < loop_ub; i++) {
    d[i] = b_d[i];
  }
  colidx.set_size(b_colidx.size(0));
  loop_ub = b_colidx.size(0);
  for (int i{0}; i < loop_ub; i++) {
    colidx[i] = b_colidx[i];
  }
  rowidx.set_size(b_rowidx.size(0));
  loop_ub = b_rowidx.size(0);
  for (int i{0}; i < loop_ub; i++) {
    rowidx[i] = b_rowidx[i];
  }
  m = b_m;
  n = b_n;
}

//
// Arguments    : void
// Return Type  : sparse
//
sparse::sparse() = default;

//
// Arguments    : void
// Return Type  : void
//
sparse::~sparse() = default;

} // namespace coder

//
// File trailer for sparse.cpp
//
// [EOF]
//
