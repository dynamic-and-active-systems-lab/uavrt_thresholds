//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: introsort.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

#ifndef INTROSORT_H
#define INTROSORT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class anonymous_function;

}

// Function Declarations
namespace coder {
namespace internal {
void introsort(::coder::array<int, 1U> &x, int xend,
               const anonymous_function *cmp);

}
} // namespace coder

#endif
//
// File trailer for introsort.h
//
// [EOF]
//
