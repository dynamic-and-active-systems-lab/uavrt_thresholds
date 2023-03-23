//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: buildtimecorrelatormatrix.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "buildtimecorrelatormatrix.h"
#include "assembleWq.h"
#include "assertValidSizeArg.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "minOrMax.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "sparse1.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "unique.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Dimensions of arrays being concatenated are not consistent.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// UNTITLED Summary of this function goes here
//    Detailed explanation goes here
//
// Arguments    : double pri
//                double priUncert
//                double priJtr
//                double reps
//                coder::sparse *Wq
// Return Type  : void
//
void buildtimecorrelatormatrix(double pri, double priUncert, double priJtr,
                               double reps, coder::sparse *Wq)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      42,                                                            // lineNo
      42,                                                            // colNo
      "PRI_mean_value",                                              // aName
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      42,                                                            // lineNo
      69,                                                            // colNo
      "PRI_jitter_value",                                            // aName
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      41,                                                            // lineNo
      35,                                                            // colNo
      "pulse_position_value",                                        // aName
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      41,                                                            // lineNo
      38,                                                            // colNo
      "pulse_position_value",                                        // aName
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      31,                                                            // lineNo
      27,                                                            // colNo
      "pulse_position_matrix",                                       // aName
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      41,                                                            // lineNo
      48,                                                            // colNo
      "pulse_position_value",                                        // aName
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      71,                                                            // lineNo
      75,                                                            // colNo
      "pulse_position_value",                                        // aName
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,                                                  // iFirst
      -1,                                                  // iLast
      31,                                                  // lineNo
      32,                                                  // colNo
      "C",                                                 // aName
      "cartesian_prod_func",                               // fName
      "H:\\repos\\uavrt_detection\\cartesian_prod_func.m", // pName
      0                                                    // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,                                                  // iFirst
      -1,                                                  // iLast
      31,                                                  // lineNo
      9,                                                   // colNo
      "A",                                                 // aName
      "cartesian_prod_func",                               // fName
      "H:\\repos\\uavrt_detection\\cartesian_prod_func.m", // pName
      0                                                    // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,                                                  // iFirst
      -1,                                                  // iLast
      31,                                                  // lineNo
      12,                                                  // colNo
      "C",                                                 // aName
      "cartesian_prod_func",                               // fName
      "H:\\repos\\uavrt_detection\\cartesian_prod_func.m", // pName
      0                                                    // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,                                                  // iFirst
      -1,                                                  // iLast
      31,                                                  // lineNo
      17,                                                  // colNo
      "C",                                                 // aName
      "cartesian_prod_func",                               // fName
      "H:\\repos\\uavrt_detection\\cartesian_prod_func.m", // pName
      0                                                    // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      72,                                                            // lineNo
      30,                                                            // colNo
      "pulse_position_matrix",                                       // aName
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      72,                                                            // lineNo
      55,                                                            // colNo
      "pulse_position_matrix",                                       // aName
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      0 // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      15,                                                        // lineNo
      24,                                                        // colNo
      "buildtimecorrelatormatrix",                               // fName
      "H:\\repos\\uavrt_detection\\buildtimecorrelatormatrix.m", // pName
      4                                                          // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      15,                                                        // lineNo
      24,                                                        // colNo
      "buildtimecorrelatormatrix",                               // fName
      "H:\\repos\\uavrt_detection\\buildtimecorrelatormatrix.m", // pName
      1                                                          // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      16,                                                        // lineNo
      24,                                                        // colNo
      "buildtimecorrelatormatrix",                               // fName
      "H:\\repos\\uavrt_detection\\buildtimecorrelatormatrix.m", // pName
      4                                                          // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      16,                                                        // lineNo
      24,                                                        // colNo
      "buildtimecorrelatormatrix",                               // fName
      "H:\\repos\\uavrt_detection\\buildtimecorrelatormatrix.m", // pName
      1                                                          // checkKind
  };
  static rtDoubleCheckInfo f_emlrtDCI{
      29,                                                            // lineNo
      32,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      4 // checkKind
  };
  static rtDoubleCheckInfo g_emlrtDCI{
      29,                                                            // lineNo
      32,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo h_emlrtDCI{
      29,                                                            // lineNo
      50,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      4 // checkKind
  };
  static rtDoubleCheckInfo i_emlrtDCI{
      29,                                                            // lineNo
      50,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo j_emlrtDCI{
      31,                                                            // lineNo
      39,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo k_emlrtDCI{
      35,                                                            // lineNo
      31,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo l_emlrtDCI{
      35,                                                            // lineNo
      1,                                                             // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo m_emlrtDCI{
      59,                                                            // lineNo
      32,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      4 // checkKind
  };
  static rtDoubleCheckInfo n_emlrtDCI{
      59,                                                            // lineNo
      32,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo o_emlrtDCI{
      5,                                          // lineNo
      1,                                          // colNo
      "assembleWq",                               // fName
      "H:\\repos\\uavrt_detection\\assembleWq.m", // pName
      1                                           // checkKind
  };
  static rtDoubleCheckInfo p_emlrtDCI{
      13,                                                  // lineNo
      12,                                                  // colNo
      "cartesian_prod_func",                               // fName
      "H:\\repos\\uavrt_detection\\cartesian_prod_func.m", // pName
      1                                                    // checkKind
  };
  static rtDoubleCheckInfo q_emlrtDCI{
      71,                                                            // lineNo
      5,                                                             // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo r_emlrtDCI{
      31,                                                  // lineNo
      12,                                                  // colNo
      "cartesian_prod_func",                               // fName
      "H:\\repos\\uavrt_detection\\cartesian_prod_func.m", // pName
      1                                                    // checkKind
  };
  static rtDoubleCheckInfo s_emlrtDCI{
      31,                                                  // lineNo
      17,                                                  // colNo
      "cartesian_prod_func",                               // fName
      "H:\\repos\\uavrt_detection\\cartesian_prod_func.m", // pName
      1                                                    // checkKind
  };
  static rtDoubleCheckInfo t_emlrtDCI{
      72,                                                            // lineNo
      30,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo u_emlrtDCI{
      72,                                                            // lineNo
      55,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo v_emlrtDCI{
      75,                                                            // lineNo
      20,                                                            // colNo
      "generate_pulse_positions_func",                               // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m", // pName
      1 // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      -1,                                                       // nDims
      25,                                                       // lineNo
      5,                                                        // colNo
      "buildtimecorrelatormatrix",                              // fName
      "H:\\repos\\uavrt_detection\\buildtimecorrelatormatrix.m" // pName
  };
  static rtEqualityCheckInfo c_emlrtECI{
      -1,                                                           // nDims
      31,                                                           // lineNo
      1,                                                            // colNo
      "generate_pulse_positions_func",                              // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m" // pName
  };
  static rtEqualityCheckInfo d_emlrtECI{
      -1,                                                           // nDims
      72,                                                           // lineNo
      5,                                                            // colNo
      "generate_pulse_positions_func",                              // fName
      "H:\\repos\\uavrt_detection\\generate_pulse_positions_func.m" // pName
  };
  static rtEqualityCheckInfo e_emlrtECI{
      1,                                         // nDims
      55,                                        // lineNo
      15,                                        // colNo
      "assembleWq",                              // fName
      "H:\\repos\\uavrt_detection\\assembleWq.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      -1,                                                       // nDims
      24,                                                       // lineNo
      5,                                                        // colNo
      "buildtimecorrelatormatrix",                              // fName
      "H:\\repos\\uavrt_detection\\buildtimecorrelatormatrix.m" // pName
  };
  static rtEqualityCheckInfo f_emlrtECI{
      2,                                         // nDims
      55,                                        // lineNo
      15,                                        // colNo
      "assembleWq",                              // fName
      "H:\\repos\\uavrt_detection\\assembleWq.m" // pName
  };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      275,                  // lineNo
      "check_non_axis_size" // fName
  };
  coder::array<double, 3U> pulse_position_value;
  coder::array<double, 2U> WqRowInds;
  coder::array<double, 2U> pattern_matrix;
  coder::array<double, 2U> priJtrList;
  coder::array<double, 2U> priMeansList;
  coder::array<double, 2U> pulsePositionMatrix;
  coder::array<double, 2U> shiftermat;
  coder::array<double, 1U> b_WqRowInds;
  coder::array<double, 1U> b_priMeansList;
  coder::array<double, 1U> r;
  double d;
  double d1;
  double n_rows;
  double num_PRI_patterns;
  double num_position_patterns;
  double num_rows_C;
  double star;
  int sizes[2];
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int ibmat;
  int jcol;
  int ncols;
  int nrows;
  int ntilerows;
  int num_members_per_set;
  signed char input_sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  // First check to make sure all inputs contain the same number of
  // elements
  d = 2.0 * priUncert + 1.0;
  if (!(d >= 0.0)) {
    rtNonNegativeError(d, &b_emlrtDCI);
  }
  if (d != static_cast<int>(std::floor(d))) {
    rtIntegerError(d, &c_emlrtDCI);
  }
  d1 = 2.0 * priJtr + 1.0;
  if (!(d1 >= 0.0)) {
    rtNonNegativeError(d1, &d_emlrtDCI);
  }
  if (d1 != static_cast<int>(std::floor(d1))) {
    rtIntegerError(d1, &e_emlrtDCI);
  }
  // Change names to align with other code.
  if (std::isnan(-priUncert) || std::isnan(priUncert)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (priUncert < -priUncert) {
    priJtrList.set_size(1, 0);
  } else if ((std::isinf(-priUncert) || std::isinf(priUncert)) &&
             (-priUncert == priUncert)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (std::floor(-priUncert) == -priUncert) {
    ncols = static_cast<int>(priUncert - (-priUncert));
    priJtrList.set_size(1, ncols + 1);
    for (i = 0; i <= ncols; i++) {
      priJtrList[i] = -priUncert + static_cast<double>(i);
    }
  } else {
    coder::eml_float_colon(-priUncert, priUncert, priJtrList);
  }
  if (static_cast<int>(d) != priJtrList.size(1)) {
    rtSizeEq1DError(static_cast<int>(d), priJtrList.size(1), &emlrtECI);
  }
  priMeansList.set_size(1, priJtrList.size(1));
  ncols = priJtrList.size(1);
  for (i = 0; i < ncols; i++) {
    priMeansList[i] = pri + priJtrList[i];
  }
  if (std::isnan(-priJtr) || std::isnan(priJtr)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (priJtr < -priJtr) {
    priJtrList.set_size(1, 0);
  } else if ((std::isinf(-priJtr) || std::isinf(priJtr)) &&
             (-priJtr == priJtr)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (std::floor(-priJtr) == -priJtr) {
    ncols = static_cast<int>(priJtr - (-priJtr));
    priJtrList.set_size(1, ncols + 1);
    for (i = 0; i <= ncols; i++) {
      priJtrList[i] = -priJtr + static_cast<double>(i);
    }
  } else {
    coder::eml_float_colon(-priJtr, priJtr, priJtrList);
  }
  if (static_cast<int>(d1) != priJtrList.size(1)) {
    rtSizeEq1DError(static_cast<int>(d1), priJtrList.size(1), &b_emlrtECI);
  }
  // PPM Contains the column positions (time windows) in the S matrix to search
  // for the K pulses assuming the first pulse arrives at window 1.
  //  INPUTS:
  //    PRI_mean_value          row vector of PRI means (scale/index is STFT
  //    step
  //                            size)
  //
  //    PRI_jitter_value        row vector of jitter values (scale/index is STFT
  //    step
  //                            size)
  //
  //    K                       number of pulses forming the pattern
  //
  //  OUTPUTS:
  //    pulse_position_matrix   row is a pattern; each pattern has K pulse
  //                            position values
  //
  //  CALLS:
  //                            cartesion_prod_func()
  //
  //  generate_pulse_positions_func.m
  //  Author: Paul G. Flikkema
  //  Date:   1 Oct 2021
  num_PRI_patterns =
      static_cast<double>(priMeansList.size(1)) *
      rt_powd_snf(static_cast<double>(priJtrList.size(1)), reps - 1.0);
  if (!(num_PRI_patterns >= 0.0)) {
    rtNonNegativeError(rtNaN, &f_emlrtDCI);
  }
  i = static_cast<int>(std::floor(num_PRI_patterns));
  if (num_PRI_patterns != i) {
    rtIntegerError(num_PRI_patterns, &g_emlrtDCI);
  }
  if (!(reps >= 0.0)) {
    rtNonNegativeError(reps, &h_emlrtDCI);
  }
  i1 = static_cast<int>(std::floor(reps));
  if (reps != i1) {
    rtIntegerError(reps, &i_emlrtDCI);
  }
  //  place first pulse at pulse position q = 1
  if (reps < 1.0) {
    rtDynamicBoundsError(1, 1, 0, &emlrtBCI);
  }
  ntilerows = static_cast<int>(num_PRI_patterns);
  if (ntilerows != i) {
    rtIntegerError(num_PRI_patterns, &j_emlrtDCI);
  }
  rtSubAssignSizeCheck(&ntilerows, 1, &ntilerows, 1, &c_emlrtECI);
  //  based on the model, generate all the pulse position values in a 3D matrix
  //  pulse_position_value(k, i_position, i_mean )
  i = static_cast<int>(reps);
  if (i != i1) {
    rtIntegerError(reps, &k_emlrtDCI);
  }
  pulse_position_value.set_size(i, priJtrList.size(1), priMeansList.size(1));
  if (i != i1) {
    rtIntegerError(reps, &l_emlrtDCI);
  }
  ncols = i * priJtrList.size(1) * priMeansList.size(1);
  for (i1 = 0; i1 < ncols; i1++) {
    pulse_position_value[i1] = 0.0;
  }
  ncols = priMeansList.size(1);
  for (i1 = 0; i1 < ncols; i1++) {
    ntilerows = priJtrList.size(1);
    for (jcol = 0; jcol < ntilerows; jcol++) {
      pulse_position_value[pulse_position_value.size(0) * jcol +
                           pulse_position_value.size(0) *
                               pulse_position_value.size(1) * i1] = 1.0;
    }
  }
  //  first pulse is always in position 1
  //  loop through the mean PRI values
  i1 = priMeansList.size(1);
  for (ntilerows = 0; ntilerows < i1; ntilerows++) {
    jcol = i + -1;
    for (ncols = 0; ncols < jcol; ncols++) {
      i2 = priJtrList.size(1);
      for (ibmat = 0; ibmat < i2; ibmat++) {
        if (ntilerows + 1 > priMeansList.size(1)) {
          rtDynamicBoundsError(ntilerows + 1, 1, priMeansList.size(1),
                               &b_emlrtBCI);
        }
        if (ibmat + 1 > priJtrList.size(1)) {
          rtDynamicBoundsError(ibmat + 1, 1, priJtrList.size(1), &c_emlrtBCI);
        }
        if (static_cast<int>(ncols + 2U) > pulse_position_value.size(0)) {
          rtDynamicBoundsError(static_cast<int>(ncols + 2U), 1,
                               pulse_position_value.size(0), &d_emlrtBCI);
        }
        if (ibmat + 1 > pulse_position_value.size(1)) {
          rtDynamicBoundsError(ibmat + 1, 1, pulse_position_value.size(1),
                               &e_emlrtBCI);
        }
        if (ntilerows + 1 > pulse_position_value.size(2)) {
          rtDynamicBoundsError(ntilerows + 1, 1, pulse_position_value.size(2),
                               &f_emlrtBCI);
        }
        pulse_position_value[((ncols + pulse_position_value.size(0) * ibmat) +
                              pulse_position_value.size(0) *
                                  pulse_position_value.size(1) * ntilerows) +
                             1] = (((static_cast<double>(ncols) + 2.0) - 1.0) *
                                       priMeansList[ntilerows] +
                                   1.0) +
                                  priJtrList[ibmat];
      }
    }
  }
  //  generate the pulse_position_matrix by considering
  //  all possible combinations of the values;
  //  each row is for one pattern, there are K columns;
  //  pulse_position_matrix( i_pattern, k)
  //
  //  The number of columns is the number of possible positions
  //
  //  we generate a num_PRI_jitters^(K-1) x K matrix
  //  using the function cartesian_prod_func
  //
  //  we stack matrices vertically into the pulse_position_matrix
  num_position_patterns =
      static_cast<double>(priMeansList.size(1)) *
      rt_powd_snf(static_cast<double>(priJtrList.size(1)), reps - 1.0);
  if (!(num_position_patterns >= 0.0)) {
    rtNonNegativeError(rtNaN, &m_emlrtDCI);
  }
  d = static_cast<int>(std::floor(num_position_patterns));
  if (num_position_patterns != d) {
    rtIntegerError(num_position_patterns, &n_emlrtDCI);
  }
  pulsePositionMatrix.set_size(static_cast<int>(num_position_patterns),
                               pulsePositionMatrix.size(1));
  pulsePositionMatrix.set_size(pulsePositionMatrix.size(0), i - 1);
  if (num_position_patterns != d) {
    rtIntegerError(num_position_patterns, &o_emlrtDCI);
  }
  ncols =
      static_cast<int>(num_position_patterns) * (static_cast<int>(reps) - 1);
  for (i = 0; i < ncols; i++) {
    pulsePositionMatrix[i] = 0.0;
  }
  n_rows = rt_powd_snf(static_cast<double>(priJtrList.size(1)), reps - 1.0);
  //  number of rows per PRI mean
  i = priMeansList.size(1);
  if (priMeansList.size(1) - 1 >= 0) {
    if (pulse_position_value.size(0) < 2) {
      i3 = -1;
      i4 = -1;
    } else {
      i3 = 0;
      i4 = pulse_position_value.size(0) - 1;
    }
    num_members_per_set = pulse_position_value.size(1);
    ntilerows = i4 - i3;
    num_rows_C = rt_powd_snf(static_cast<double>(pulse_position_value.size(1)),
                             static_cast<double>(ntilerows));
    i5 = ntilerows - 1;
  }
  for (int i_set{0}; i_set < i; i_set++) {
    //      % DEBUG
    //      a = [ 1 1 1 ]; b = [ 309 310 311 ]; c = [ 618 619 620 ];
    //      A = [ a; b; c ];
    //  since pattern is "fundamental" pattern starting with a pulse in the
    //  first STFT window, we only need to look at combinations
    //  rows 2:end, and then add the column of ones
    if (i_set + 1 > pulse_position_value.size(2)) {
      rtDynamicBoundsError(i_set + 1, 1, pulse_position_value.size(2),
                           &g_emlrtBCI);
    }
    //    returns the Cartesian product C of the (values in the) rows
    //    of the input matrix A.
    //    Each row of A is taken as a set to draw from
    //    Assumes all sets have the same number of members
    i1 = static_cast<int>(std::floor(num_rows_C));
    if (num_rows_C != i1) {
      rtIntegerError(num_rows_C, &p_emlrtDCI);
    }
    jcol = i4 - i3;
    i2 = static_cast<int>(num_rows_C);
    pattern_matrix.set_size(i2, jcol);
    if (i2 != i1) {
      rtIntegerError(num_rows_C, &q_emlrtDCI);
    }
    ncols = i2 * jcol;
    for (i1 = 0; i1 < ncols; i1++) {
      pattern_matrix[i1] = 0.0;
    }
    //  loop through columns of C
    for (ibmat = 0; ibmat <= i5; ibmat++) {
      unsigned int i_col_A;
      //  fill the column (aka fill the elements in the column)
      //  stride is number of elements to repeat in a column
      //  num_strides is number of strides per column
      ntilerows = i4 - i3;
      num_PRI_patterns =
          rt_powd_snf(static_cast<double>(num_members_per_set),
                      static_cast<double>((ntilerows - ibmat) - 1));
      i_col_A = 0U;
      //  the column in A that we use
      i1 = static_cast<int>(num_rows_C / num_PRI_patterns);
      for (nrows = 0; nrows < i1; nrows++) {
        i_col_A++;
        if (i_col_A > static_cast<unsigned int>(num_members_per_set)) {
          i_col_A = 1U;
        }
        star =
            ((static_cast<double>(nrows) + 1.0) - 1.0) * num_PRI_patterns + 1.0;
        //  column of C gets elements from row of A
        d1 = (star + num_PRI_patterns) - 1.0;
        if (star > d1) {
          jcol = 0;
          i2 = 0;
        } else {
          if (star != static_cast<int>(std::floor(star))) {
            rtIntegerError(star, &r_emlrtDCI);
          }
          if ((static_cast<int>(star) < 1) ||
              (static_cast<int>(star) > pattern_matrix.size(0))) {
            rtDynamicBoundsError(static_cast<int>(star), 1,
                                 pattern_matrix.size(0), &j_emlrtBCI);
          }
          jcol = static_cast<int>(star) - 1;
          if (d1 != static_cast<int>(std::floor(d1))) {
            rtIntegerError(d1, &s_emlrtDCI);
          }
          if ((static_cast<int>(d1) < 1) ||
              (static_cast<int>(d1) > pattern_matrix.size(0))) {
            rtDynamicBoundsError(static_cast<int>(d1), 1,
                                 pattern_matrix.size(0), &k_emlrtBCI);
          }
          i2 = static_cast<int>(d1);
        }
        if (ibmat + 1 > pattern_matrix.size(1)) {
          rtDynamicBoundsError(ibmat + 1, 1, pattern_matrix.size(1),
                               &h_emlrtBCI);
        }
        ncols = i2 - jcol;
        for (i2 = 0; i2 < ncols; i2++) {
          if (ibmat + 1 > ntilerows) {
            rtDynamicBoundsError(ibmat + 1, 1, ntilerows, &i_emlrtBCI);
          }
          if ((static_cast<int>(i_col_A) < 1) ||
              (static_cast<int>(i_col_A) > pulse_position_value.size(1))) {
            rtDynamicBoundsError(static_cast<int>(i_col_A), 1,
                                 pulse_position_value.size(1), &i_emlrtBCI);
          }
          pattern_matrix[(jcol + i2) + pattern_matrix.size(0) * ibmat] =
              pulse_position_value[(((i3 + ibmat) +
                                     pulse_position_value.size(0) *
                                         (static_cast<int>(i_col_A) - 1)) +
                                    pulse_position_value.size(0) *
                                        pulse_position_value.size(1) * i_set) +
                                   1];
        }
      }
    }
    d1 = ((static_cast<double>(i_set) + 1.0) - 1.0) * n_rows + 1.0;
    num_PRI_patterns = (static_cast<double>(i_set) + 1.0) * n_rows;
    if (d1 > num_PRI_patterns) {
      i1 = 0;
      jcol = 0;
    } else {
      if (d1 != static_cast<int>(std::floor(d1))) {
        rtIntegerError(d1, &t_emlrtDCI);
      }
      if ((static_cast<int>(d1) < 1) ||
          (static_cast<int>(d1) > pulsePositionMatrix.size(0))) {
        rtDynamicBoundsError(static_cast<int>(d1), 1,
                             pulsePositionMatrix.size(0), &l_emlrtBCI);
      }
      i1 = static_cast<int>(d1) - 1;
      if (num_PRI_patterns != static_cast<int>(std::floor(num_PRI_patterns))) {
        rtIntegerError(num_PRI_patterns, &u_emlrtDCI);
      }
      if ((static_cast<int>(num_PRI_patterns) < 1) ||
          (static_cast<int>(num_PRI_patterns) > pulsePositionMatrix.size(0))) {
        rtDynamicBoundsError(static_cast<int>(num_PRI_patterns), 1,
                             pulsePositionMatrix.size(0), &m_emlrtBCI);
      }
      jcol = static_cast<int>(num_PRI_patterns);
    }
    sizes[0] = jcol - i1;
    sizes[1] = pulsePositionMatrix.size(1);
    rtSubAssignSizeCheck(&sizes[0], 2, pattern_matrix.size(), 2, &d_emlrtECI);
    ncols = pattern_matrix.size(1);
    for (jcol = 0; jcol < ncols; jcol++) {
      ntilerows = pattern_matrix.size(0);
      for (i2 = 0; i2 < ntilerows; i2++) {
        pulsePositionMatrix[(i1 + i2) + pulsePositionMatrix.size(0) * jcol] =
            pattern_matrix[i2 + pattern_matrix.size(0) * jcol];
      }
    }
  }
  if (num_position_patterns != d) {
    rtIntegerError(num_position_patterns, &v_emlrtDCI);
  }
  if (static_cast<int>(num_position_patterns) != 0) {
    ntilerows = static_cast<int>(num_position_patterns);
  } else if ((pulsePositionMatrix.size(0) != 0) &&
             (pulsePositionMatrix.size(1) != 0)) {
    ntilerows = pulsePositionMatrix.size(0);
  } else {
    ntilerows = static_cast<int>(num_position_patterns);
    if (pulsePositionMatrix.size(0) > ntilerows) {
      ntilerows = pulsePositionMatrix.size(0);
    }
  }
  if ((static_cast<int>(num_position_patterns) != ntilerows) &&
      (static_cast<int>(num_position_patterns) != 0)) {
    d_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  if ((pulsePositionMatrix.size(0) != ntilerows) &&
      ((pulsePositionMatrix.size(0) != 0) &&
       (pulsePositionMatrix.size(1) != 0))) {
    d_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  empty_non_axis_sizes = (ntilerows == 0);
  if (empty_non_axis_sizes || (static_cast<int>(num_position_patterns) != 0)) {
    input_sizes_idx_1 = 1;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || ((pulsePositionMatrix.size(0) != 0) &&
                               (pulsePositionMatrix.size(1) != 0))) {
    sizes[1] = pulsePositionMatrix.size(1);
  } else {
    sizes[1] = 0;
  }
  //  remove duplicate patterns
  pattern_matrix.set_size(ntilerows, input_sizes_idx_1 + sizes[1]);
  ncols = input_sizes_idx_1;
  for (i = 0; i < ncols; i++) {
    for (i1 = 0; i1 < ntilerows; i1++) {
      pattern_matrix[i1] = 1.0;
    }
  }
  ncols = sizes[1];
  for (i = 0; i < ncols; i++) {
    for (i1 = 0; i1 < ntilerows; i1++) {
      pattern_matrix[i1 + pattern_matrix.size(0) * (i + input_sizes_idx_1)] =
          pulsePositionMatrix[i1 + ntilerows * i];
    }
  }
  coder::unique_rows(pattern_matrix, pulsePositionMatrix);
  //  if K>1
  //      %n_shifts = min(pulsePositionMatrix(:,2))-1;   %The number of shifts
  //      necessary.
  //
  //  else
  //      n_shifts = max(PRI_means_q)+max(PRI_jitters_q);
  //  end
  // The max element of the ppm for K>1 is (K-1)*(N+M)+J+1 which is the latest
  // possible index of the Kth pulse if the first arrived at n = 1.
  //
  // The max element of the ppm for K=1 is 1 which is the first possible index
  // of the 1st pulse.
  //
  // The size of the STFT matrix is the latest possible location of the Kth
  // pulse which is equal to K*(N+M)+J+1
  //
  // We want to take the PPM matrix that contains the the time locations for
  // the search if the first pulse is at n=1 and shift them to do the search if
  // the first pulse arrives and n = 2,..., N+M+J+1 which is the latest
  // possible location of the pulse pulse. The difference is N+M+J+1-1 = N+M+J
  // This is the max number we need to add the the PPM matrix.
  //
  // For the K = 1 case, the PPM is simply 1 and we add N+M+J which generates a
  // Wq matrix with a dimension of 1+N+M+J. This is equivalent to the STFT
  // size definition for K = 1, which is K(N+M)+J+1 = N+M+J+1, so the sizes
  // will be compatible.
  //
  // For the K > 1 case however the maximum element of the PPM is
  // (K-1)(N+M)+J+1. Adding N+M+J to this will result in a Wq with a dimension
  // of (K-1)(N+M)+J+1+N+M+J = K(N+M)+2J+1. This will be J elements larger than
  // the STFT definitions of K(N+M)+J+1. This extra J comes from the fact that
  // the max element of the PPM include the jitter of the final pulse and we
  // also include the jitter in the shifting. Because jitter is stochastic and
  // zero mean, we don't sum jitter over multiple pulses. We need to remove the
  // extra jitter when shifting for K>1.
  //
  if (reps > 1.0) {
    ibmat = priMeansList.size(1);
    b_priMeansList = priMeansList.reshape(ibmat);
    num_PRI_patterns = coder::internal::maximum(b_priMeansList);
    // Equivalent to N+M+J-J
  } else {
    ibmat = priMeansList.size(1);
    b_priMeansList = priMeansList.reshape(ibmat);
    num_PRI_patterns = coder::internal::maximum(b_priMeansList);
    ntilerows = priJtrList.size(1);
    b_priMeansList = priJtrList.reshape(ntilerows);
    star = coder::internal::maximum(b_priMeansList);
    num_PRI_patterns += star;
    // Equivalent to N+M+J
  }
  // Number of rows in pulse_position_matrix
  // Number of cols in pulse_position_matrix --- should always be K
  coder::repmat(pulsePositionMatrix, num_PRI_patterns + 1.0, pattern_matrix);
  // Create multiple copies of the PPM matrix. Each copy will eventually be
  // shifted. The second copy will get a 1 added to it, the third a 2 added, and
  // so on up to n_shifts. Use n_shifts+1 to account for the first one that
  // receives no shifting. Get the number of rows in the big PPM matrix
  if (std::isnan(num_PRI_patterns)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (num_PRI_patterns < 0.0) {
    priJtrList.set_size(1, 0);
  } else {
    priJtrList.set_size(1, static_cast<int>(num_PRI_patterns) + 1);
    ncols = static_cast<int>(num_PRI_patterns);
    for (i = 0; i <= ncols; i++) {
      priJtrList[i] = i;
    }
  }
  coder::internal::assertValidSizeArg(
      static_cast<double>(pulsePositionMatrix.size(0)));
  shiftermat.set_size(pulsePositionMatrix.size(0), priJtrList.size(1));
  ncols = priJtrList.size(1);
  ntilerows = pulsePositionMatrix.size(0);
  if (priJtrList.size(1) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (jcol = 0; jcol < ncols; jcol++) {
    ibmat = jcol * ntilerows;
    if (ntilerows > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (nrows = 0; nrows < ntilerows; nrows++) {
      shiftermat[ibmat + nrows] = priJtrList[jcol];
    }
  }
  // Create a matrix of the shifts needed for each copy of the PPM matrix
  coder::internal::assertValidSizeArg(
      static_cast<double>(pulsePositionMatrix.size(1)));
  WqRowInds.set_size(shiftermat.size(0) * shiftermat.size(1),
                     pulsePositionMatrix.size(1));
  nrows = shiftermat.size(0) * shiftermat.size(1);
  ntilerows = pulsePositionMatrix.size(1);
  if (pulsePositionMatrix.size(1) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (int i_set{0}; i_set < ntilerows; i_set++) {
    ibmat = i_set * nrows;
    if (nrows > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (ncols = 0; ncols < nrows; ncols++) {
      WqRowInds[ibmat + ncols] = shiftermat[ncols];
    }
  }
  if ((WqRowInds.size(0) != pattern_matrix.size(0)) &&
      ((WqRowInds.size(0) != 1) && (pattern_matrix.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(WqRowInds.size(0), pattern_matrix.size(0),
                                &e_emlrtECI);
  }
  if ((WqRowInds.size(1) != pattern_matrix.size(1)) &&
      ((WqRowInds.size(1) != 1) && (pattern_matrix.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(WqRowInds.size(1), pattern_matrix.size(1),
                                &f_emlrtECI);
  }
  if ((WqRowInds.size(0) == pattern_matrix.size(0)) &&
      (WqRowInds.size(1) == pattern_matrix.size(1))) {
    ncols = WqRowInds.size(0) * WqRowInds.size(1);
    for (i = 0; i < ncols; i++) {
      WqRowInds[i] = WqRowInds[i] + pattern_matrix[i];
    }
  } else {
    plus(WqRowInds, pattern_matrix);
  }
  if (pattern_matrix.size(0) < 1) {
    priJtrList.set_size(1, 0);
  } else {
    priJtrList.set_size(1, pattern_matrix.size(0));
    ncols = pattern_matrix.size(0) - 1;
    for (i = 0; i <= ncols; i++) {
      priJtrList[i] = static_cast<double>(i) + 1.0;
    }
  }
  coder::internal::assertValidSizeArg(
      static_cast<double>(pulsePositionMatrix.size(1)));
  priMeansList.set_size(1, priJtrList.size(1) * pulsePositionMatrix.size(1));
  ncols = priJtrList.size(1);
  ntilerows = pulsePositionMatrix.size(1);
  for (int i_set{0}; i_set < ntilerows; i_set++) {
    ibmat = i_set * ncols;
    if (ncols > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (jcol = 0; jcol < ncols; jcol++) {
      priMeansList[ibmat + jcol] = priJtrList[jcol];
    }
  }
  nrows = WqRowInds.size(0) * WqRowInds.size(1);
  ibmat = priMeansList.size(1);
  ntilerows = WqRowInds.size(0) * WqRowInds.size(1);
  r.set_size(ntilerows);
  for (i = 0; i < ntilerows; i++) {
    r[i] = 1.0;
  }
  b_WqRowInds = WqRowInds.reshape(nrows);
  b_priMeansList = priMeansList.reshape(ibmat);
  coder::b_sparse(b_WqRowInds, b_priMeansList, r, Wq);
  // , obj.reps(i));
}

//
// File trailer for buildtimecorrelatormatrix.cpp
//
// [EOF]
//
