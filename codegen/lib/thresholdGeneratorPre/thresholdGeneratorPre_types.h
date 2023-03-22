//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorPre_types.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

#ifndef THRESHOLDGENERATORPRE_TYPES_H
#define THRESHOLDGENERATORPRE_TYPES_H

// Include Files
#include "rtwtypes.h"
#define MAX_THREADS omp_get_max_threads()

// Type Definitions
struct rtEqualityCheckInfo {
  int nDims;
  int lineNo;
  int colNo;
  const char *fName;
  const char *pName;
};

struct rtBoundsCheckInfo {
  int iFirst;
  int iLast;
  int lineNo;
  int colNo;
  const char *aName;
  const char *fName;
  const char *pName;
  int checkKind;
};

struct rtDoubleCheckInfo {
  int lineNo;
  int colNo;
  const char *fName;
  const char *pName;
  int checkKind;
};

struct rtRunTimeErrorInfo {
  int lineNo;
  const char *fName;
};

#endif
//
// File trailer for thresholdGeneratorPre_types.h
//
// [EOF]
//
