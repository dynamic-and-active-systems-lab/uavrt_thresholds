//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorPre.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

#ifndef THRESHOLDGENERATORPRE_H
#define THRESHOLDGENERATORPRE_H

// Include Files
#include "rtwtypes.h"
#include "sparse1.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void thresholdGeneratorPre(double Fs, double t_p, double t_ip,
                                  double t_ipu, double t_ipj, double K,
                                  coder::array<creal_T, 2U> &W,
                                  coder::array<creal_T, 3U> &Ssynth,
                                  coder::sparse *Wq, boolean_T *success);

#endif
//
// File trailer for thresholdGeneratorPre.h
//
// [EOF]
//
