//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: stft.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

#ifndef STFT_H
#define STFT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void stft(const ::coder::array<creal_T, 2U> &x, double varargin_1,
          const ::coder::array<double, 1U> &varargin_3, double varargin_5,
          double varargin_7, ::coder::array<creal_T, 3U> &varargout_1,
          ::coder::array<double, 1U> &varargout_2,
          ::coder::array<double, 1U> &varargout_3);

}

#endif
//
// File trailer for stft.h
//
// [EOF]
//
