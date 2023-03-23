//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: buildtimecorrelatormatrix.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

#ifndef BUILDTIMECORRELATORMATRIX_H
#define BUILDTIMECORRELATORMATRIX_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class sparse;

}

// Function Declarations
void buildtimecorrelatormatrix(double pri, double priUncert, double priJtr,
                               double reps, coder::sparse *Wq);

#endif
//
// File trailer for buildtimecorrelatormatrix.h
//
// [EOF]
//
