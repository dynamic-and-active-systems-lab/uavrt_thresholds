//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sparse.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:59
//

#ifndef SPARSE_H
#define SPARSE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class sparse {
public:
  void init(const ::coder::array<double, 1U> &b_d,
            const ::coder::array<int, 1U> &b_colidx,
            const ::coder::array<int, 1U> &b_rowidx, int b_m, int b_n);
  sparse();
  ~sparse();
  array<double, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
  int m;
  int n;
};

} // namespace coder

#endif
//
// File trailer for sparse.h
//
// [EOF]
//
