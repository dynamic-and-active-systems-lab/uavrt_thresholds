//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeDFT.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

#ifndef COMPUTEDFT_H
#define COMPUTEDFT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void computeDFT(const ::coder::array<creal_T, 3U> &xin, double nfft,
                double varargin_1, ::coder::array<creal_T, 3U> &Xx,
                ::coder::array<double, 1U> &f);

}

#endif
//
// File trailer for computeDFT.h
//
// [EOF]
//
