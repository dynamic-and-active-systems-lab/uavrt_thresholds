//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorPre_internal_types.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

#ifndef THRESHOLDGENERATORPRE_INTERNAL_TYPES_H
#define THRESHOLDGENERATORPRE_INTERNAL_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"

// Type Definitions
struct struct_T {
  int xstart;
  int xend;
  int depth;
};

struct b_struct_T {
  coder::array<int, 1U> a;
  coder::array<int, 1U> b;
};

struct c_struct_T {
  double DataLength;
  double NumChannels;
  double TimeAxisLength;
  boolean_T IsSingle;
  char TimeMode[2];
  double EffectiveFs;
  boolean_T IsNormalizedFreq;
  coder::array<double, 1U> Window;
  double WindowLength;
  double OverlapLength;
  double FFTLength;
  char FreqRange[8];
  boolean_T ConjugateSymmetric;
  char TimeDimension[13];
  double NumFreqSamples;
};

struct emxArray_struct_T_120 {
  struct_T data[120];
};

#endif
//
// File trailer for thresholdGeneratorPre_internal_types.h
//
// [EOF]
//
