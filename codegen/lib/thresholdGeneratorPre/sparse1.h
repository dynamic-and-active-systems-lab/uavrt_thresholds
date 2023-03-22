//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sparse1.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

#ifndef SPARSE1_H
#define SPARSE1_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class sparse {
public:
  static void assertValidIndexArg(const ::coder::array<double, 1U> &s,
                                  ::coder::array<int, 1U> &sint);
  sparse();
  ~sparse();
  array<double, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
  int m;
  int n;
  int maxnz;
};

} // namespace coder

#endif
//
// File trailer for sparse1.h
//
// [EOF]
//
