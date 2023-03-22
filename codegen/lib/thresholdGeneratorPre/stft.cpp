//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: stft.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "stft.h"
#include "FFTImplementationCallback.h"
#include "centerest.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "iseven.h"
#include "rt_nonfinite.h"
#include "stftParser.h"
#include "thresholdGeneratorPre_data.h"
#include "thresholdGeneratorPre_internal_types.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include "omp.h"
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static int div_s32(int numerator, int denominator);

static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtDivisionByZeroErrorN();

static double rt_remd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    rtDivisionByZeroErrorN();
  } else {
    unsigned int b_denominator;
    unsigned int b_numerator;
    if (numerator < 0) {
      b_numerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      b_numerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      b_denominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      b_denominator = static_cast<unsigned int>(denominator);
    }
    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int>(b_numerator);
    } else {
      quotient = static_cast<int>(b_numerator);
    }
  }
  return quotient;
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Non-singleton dimensions of the two input arrays must match "
               "each other.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : void
// Return Type  : void
//
static void rtDivisionByZeroErrorN()
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Division by zero detected.\nEarly termination due to division "
               "by zero.";
  outStream << "\n";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_remd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
    y = rtNaN;
  } else if (std::isinf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
    double q;
    q = std::abs(u0 / u1);
    if (!(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }
  return y;
}

//
// Arguments    : const ::coder::array<creal_T, 2U> &x
//                double varargin_1
//                const ::coder::array<double, 1U> &varargin_3
//                double varargin_5
//                double varargin_7
//                ::coder::array<creal_T, 3U> &varargout_1
//                ::coder::array<double, 1U> &varargout_2
//                ::coder::array<double, 1U> &varargout_3
// Return Type  : void
//
namespace coder {
void stft(const ::coder::array<creal_T, 2U> &x, double varargin_1,
          const ::coder::array<double, 1U> &varargin_3, double varargin_5,
          double varargin_7, ::coder::array<creal_T, 3U> &varargout_1,
          ::coder::array<double, 1U> &varargout_2,
          ::coder::array<double, 1U> &varargout_3)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      23,               // lineNo
      23,               // colNo
      "",               // aName
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      23,               // lineNo
      42,               // colNo
      "",               // aName
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      84,                 // lineNo
      38,                 // colNo
      "",                 // aName
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      35,                                                            // lineNo
      7,                                                             // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      23,               // lineNo
      11,               // colNo
      "",               // aName
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      35,                                                            // lineNo
      14,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      39,                                                            // lineNo
      7,                                                             // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      45,                                                            // lineNo
      11,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      45,                                                            // lineNo
      18,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      45,                                                            // lineNo
      25,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      85,                 // lineNo
      14,                 // colNo
      "",                 // aName
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      74,              // lineNo
      8,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      75,              // lineNo
      8,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo n_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      80,              // lineNo
      4,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo o_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      279,                                                          // lineNo
      12,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo p_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      279,                                                          // lineNo
      14,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo q_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      278,                                                          // lineNo
      12,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo r_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      278,                                                          // lineNo
      14,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo s_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      13,           // lineNo
      13,           // colNo
      "",           // aName
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo t_emlrtBCI{
      -1,           // iFirst
      -1,           // iLast
      16,           // lineNo
      13,           // colNo
      "",           // aName
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      0                         // checkKind
  };
  static rtBoundsCheckInfo u_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      23,                 // lineNo
      22,                 // colNo
      "",                 // aName
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      0                           // checkKind
  };
  static rtBoundsCheckInfo v_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      23,                 // lineNo
      24,                 // colNo
      "",                 // aName
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      0                           // checkKind
  };
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      18,                 // lineNo
      22,                 // colNo
      "",                 // aName
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      0                           // checkKind
  };
  static rtBoundsCheckInfo x_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      18,                 // lineNo
      24,                 // colNo
      "",                 // aName
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      0                           // checkKind
  };
  static rtBoundsCheckInfo y_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      78,              // lineNo
      8,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      74,              // lineNo
      8,               // colNo
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      14,               // lineNo
      30,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      4                         // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      14,               // lineNo
      30,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      14,               // lineNo
      5,                // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo f_emlrtDCI{
      23,               // lineNo
      23,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo g_emlrtDCI{
      23,               // lineNo
      42,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo h_emlrtDCI{
      81,                 // lineNo
      12,                 // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo i_emlrtDCI{
      81,                 // lineNo
      1,                  // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo j_emlrtDCI{
      13,           // lineNo
      13,           // colNo
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo k_emlrtDCI{
      16,           // lineNo
      13,           // colNo
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo l_emlrtDCI{
      23,                 // lineNo
      24,                 // colNo
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      1                           // checkKind
  };
  static rtDoubleCheckInfo m_emlrtDCI{
      18,                 // lineNo
      24,                 // colNo
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      1                           // checkKind
  };
  static rtDoubleCheckInfo n_emlrtDCI{
      78,              // lineNo
      8,               // colNo
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      1 // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      -1,                 // nDims
      85,                 // lineNo
      9,                  // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      -1,               // nDims
      23,               // lineNo
      5,                // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m" // pName
  };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      12,        // lineNo
      "datawrap" // fName
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      53,      // lineNo
      "bsxfun" // fName
  };
  static const char b[8]{'c', 'e', 'n', 't', 'e', 'r', 'e', 'd'};
  static const char b_b[8]{'t', 'w', 'o', 's', 'i', 'd', 'e', 'd'};
  array<creal_T, 3U> b_c;
  array<creal_T, 3U> xin;
  array<creal_T, 2U> b_data;
  array<creal_T, 2U> data;
  array<creal_T, 2U> wrappedData;
  array<creal_T, 1U> b_x;
  array<double, 2U> sintab;
  array<double, 2U> sintabinv;
  array<double, 2U> w1;
  array<double, 2U> y;
  array<double, 1U> f;
  c_struct_T opts;
  double Fs1;
  double Nyq;
  double d;
  double freq_res;
  double hopSize;
  double nCol;
  int b_xin[3];
  int c[2];
  int b_bcoef;
  int b_loop_ub;
  int bcoef;
  int csz_idx_0;
  int i;
  int i1;
  int i2;
  int k;
  int loop_ub;
  signal::internal::stft::stftParser(x, varargin_1, varargin_3, varargin_5,
                                     varargin_7, data, &opts);
  hopSize = opts.WindowLength - opts.OverlapLength;
  nCol = std::trunc((opts.DataLength - opts.OverlapLength) / hopSize);
  xin.set_size(static_cast<int>(opts.WindowLength), xin.size(1), xin.size(2));
  if (!(nCol >= 0.0)) {
    rtNonNegativeError(nCol, &c_emlrtDCI);
  }
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, &d_emlrtDCI);
  }
  xin.set_size(xin.size(0), static_cast<int>(nCol), data.size(1));
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, &e_emlrtDCI);
  }
  loop_ub = static_cast<int>(opts.WindowLength) * static_cast<int>(nCol) *
            data.size(1);
  for (i = 0; i < loop_ub; i++) {
    xin[i].re = 0.0;
    xin[i].im = 0.0;
  }
  if (nCol - 1.0 < 0.0) {
    y.set_size(y.size(0), 0);
  } else {
    y.set_size(1, static_cast<int>(nCol - 1.0) + 1);
    loop_ub = static_cast<int>(nCol - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      y[i] = i;
    }
  }
  i = static_cast<int>(nCol);
  if (static_cast<int>(nCol) - 1 >= 0) {
    c[1] = data.size(1);
    i1 = data.size(1);
    b_loop_ub = data.size(1);
  }
  for (int iCol{0}; iCol < i; iCol++) {
    d = hopSize * ((static_cast<double>(iCol) + 1.0) - 1.0);
    nCol = opts.WindowLength + d;
    if (d + 1.0 > nCol) {
      i2 = -1;
      k = -1;
    } else {
      if (d + 1.0 != static_cast<int>(std::floor(d + 1.0))) {
        rtIntegerError(d + 1.0, &f_emlrtDCI);
      }
      if ((static_cast<int>(d + 1.0) < 1) ||
          (static_cast<int>(d + 1.0) > data.size(0))) {
        rtDynamicBoundsError(static_cast<int>(d + 1.0), 1, data.size(0),
                             &b_emlrtBCI);
      }
      i2 = static_cast<int>(d + 1.0) - 2;
      if (nCol != static_cast<int>(std::floor(nCol))) {
        rtIntegerError(nCol, &g_emlrtDCI);
      }
      if ((static_cast<int>(nCol) < 1) ||
          (static_cast<int>(nCol) > data.size(0))) {
        rtDynamicBoundsError(static_cast<int>(nCol), 1, data.size(0),
                             &c_emlrtBCI);
      }
      k = static_cast<int>(nCol) - 1;
    }
    if ((iCol + 1 < 1) || (iCol + 1 > xin.size(1))) {
      rtDynamicBoundsError(iCol + 1, 1, xin.size(1), &emlrtBCI);
    }
    bcoef = xin.size(0);
    b_xin[0] = xin.size(0);
    b_xin[1] = 1;
    b_xin[2] = xin.size(2);
    b_bcoef = k - i2;
    c[0] = b_bcoef;
    rtSubAssignSizeCheck(&b_xin[0], 3, &c[0], 2, &emlrtECI);
    b_data.set_size(b_bcoef, i1);
    for (k = 0; k < b_loop_ub; k++) {
      for (loop_ub = 0; loop_ub < b_bcoef; loop_ub++) {
        b_data[loop_ub + b_data.size(0) * k] =
            data[((i2 + loop_ub) + data.size(0) * k) + 1];
      }
    }
    b_xin[0] = xin.size(0);
    loop_ub = xin.size(2);
    for (i2 = 0; i2 < loop_ub; i2++) {
      for (k = 0; k < bcoef; k++) {
        xin[(k + xin.size(0) * iCol) + xin.size(0) * xin.size(1) * i2] =
            b_data[k + b_xin[0] * i2];
      }
    }
  }
  y.set_size(1, y.size(1));
  nCol = opts.WindowLength / 2.0;
  loop_ub = y.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    y[i] = (y[i] * hopSize + nCol) / opts.EffectiveFs;
  }
  if (xin.size(0) == 1) {
    csz_idx_0 = opts.Window.size(0);
  } else if (opts.Window.size(0) == 1) {
    csz_idx_0 = xin.size(0);
  } else if (opts.Window.size(0) == xin.size(0)) {
    csz_idx_0 = opts.Window.size(0);
  } else {
    m_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  b_c.set_size(csz_idx_0, xin.size(1), xin.size(2));
  if ((csz_idx_0 != 0) && (xin.size(1) != 0)) {
    bcoef = (xin.size(2) != 1);
    i = xin.size(2) - 1;
    b_bcoef = (xin.size(1) != 1);
    csz_idx_0 = (xin.size(0) != 1);
    for (int b_k{0}; b_k <= i; b_k++) {
      loop_ub = bcoef * b_k;
      i1 = b_c.size(1) - 1;
      for (int iCol{0}; iCol <= i1; iCol++) {
        b_loop_ub = b_bcoef * iCol;
        i2 = b_c.size(0) - 1;
        for (k = 0; k <= i2; k++) {
          b_c[(k + b_c.size(0) * iCol) + b_c.size(0) * b_c.size(1) * b_k] =
              xin[(csz_idx_0 * k + xin.size(0) * b_loop_ub) +
                  xin.size(0) * xin.size(1) * loop_ub];
        }
      }
    }
  }
  i = static_cast<int>(std::floor(opts.FFTLength));
  if (opts.FFTLength != i) {
    rtIntegerError(opts.FFTLength, &h_emlrtDCI);
  }
  b_loop_ub = static_cast<int>(opts.FFTLength);
  xin.set_size(b_loop_ub, b_c.size(1), b_c.size(2));
  if (b_loop_ub != i) {
    rtIntegerError(opts.FFTLength, &i_emlrtDCI);
  }
  loop_ub = b_loop_ub * b_c.size(1) * b_c.size(2);
  for (i = 0; i < loop_ub; i++) {
    xin[i].re = 0.0;
    xin[i].im = 0.0;
  }
  if (b_c.size(0) > b_loop_ub) {
    i = static_cast<int>(static_cast<double>(b_c.size(1)) *
                         static_cast<double>(b_c.size(2)));
    for (int iCol{0}; iCol < i; iCol++) {
      loop_ub = b_c.size(0);
      c[0] = b_c.size(0);
      i1 = b_c.size(1) * b_c.size(2);
      if ((static_cast<int>(iCol + 1U) < 1) ||
          (static_cast<int>(iCol + 1U) > i1)) {
        rtDynamicBoundsError(static_cast<int>(iCol + 1U), 1, i1, &d_emlrtBCI);
      }
      b_x.set_size(b_c.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_x[i1] = b_c[i1 + c[0] * iCol];
      }
      if (!(opts.FFTLength >= 1.0)) {
        rtErrorWithMessageID(1, e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
      }
      if (b_c.size(0) == 1) {
        wrappedData.set_size(1, b_loop_ub);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          wrappedData[i1].re = 0.0;
          wrappedData[i1].im = 0.0;
        }
      } else {
        wrappedData.set_size(b_loop_ub, 1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          wrappedData[i1].re = 0.0;
          wrappedData[i1].im = 0.0;
        }
      }
      csz_idx_0 = div_s32(b_c.size(0), b_loop_ub);
      bcoef = csz_idx_0 * b_loop_ub;
      b_bcoef = b_c.size(0) - bcoef;
      if (b_bcoef > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int b_k{0}; b_k < b_bcoef; b_k++) {
        i1 = wrappedData.size(0) * wrappedData.size(1);
        if ((b_k + 1 < 1) || (b_k + 1 > i1)) {
          rtDynamicBoundsError(b_k + 1, 1, i1, &e_emlrtBCI);
        }
        i1 = (bcoef + b_k) + 1;
        if ((i1 < 1) || (i1 > b_c.size(0))) {
          rtDynamicBoundsError(i1, 1, b_c.size(0), &f_emlrtBCI);
        }
        wrappedData[b_k].re = b_x[i1 - 1].re;
        i2 = wrappedData.size(0) * wrappedData.size(1);
        if (b_k + 1 > i2) {
          rtDynamicBoundsError(b_k + 1, 1, i2, &e_emlrtBCI);
        }
        if ((i1 < 1) || (i1 > b_c.size(0))) {
          rtDynamicBoundsError(i1, 1, b_c.size(0), &f_emlrtBCI);
        }
        wrappedData[b_k].im = b_x[i1 - 1].im;
      }
      bcoef = b_bcoef + 1;
      if ((b_bcoef + 1 <= b_loop_ub) && (b_loop_ub > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (int b_k{bcoef}; b_k <= b_loop_ub; b_k++) {
        i1 = wrappedData.size(0) * wrappedData.size(1);
        if ((b_k < 1) || (b_k > i1)) {
          rtDynamicBoundsError(b_k, 1, i1, &g_emlrtBCI);
        }
        wrappedData[b_k - 1].re = 0.0;
        i1 = wrappedData.size(0) * wrappedData.size(1);
        if (b_k > i1) {
          rtDynamicBoundsError(b_k, 1, i1, &g_emlrtBCI);
        }
        wrappedData[b_k - 1].im = 0.0;
      }
      if (csz_idx_0 > 2147483646) {
        check_forloop_overflow_error();
      }
      for (b_bcoef = 0; b_bcoef < csz_idx_0; b_bcoef++) {
        bcoef = b_bcoef * b_loop_ub;
        for (int b_k{0}; b_k < b_loop_ub; b_k++) {
          i1 = wrappedData.size(0) * wrappedData.size(1);
          if ((b_k + 1 < 1) || (b_k + 1 > i1)) {
            rtDynamicBoundsError(b_k + 1, 1, i1, &h_emlrtBCI);
          }
          i1 = wrappedData.size(0) * wrappedData.size(1);
          if (b_k + 1 > i1) {
            rtDynamicBoundsError(b_k + 1, 1, i1, &i_emlrtBCI);
          }
          i1 = (bcoef + b_k) + 1;
          if ((i1 < 1) || (i1 > b_c.size(0))) {
            rtDynamicBoundsError(i1, 1, b_c.size(0), &j_emlrtBCI);
          }
          wrappedData[b_k].re = wrappedData[b_k].re + b_x[i1 - 1].re;
          i2 = wrappedData.size(0) * wrappedData.size(1);
          if (b_k + 1 > i2) {
            rtDynamicBoundsError(b_k + 1, 1, i2, &h_emlrtBCI);
          }
          if (i1 > b_c.size(0)) {
            rtDynamicBoundsError(i1, 1, b_c.size(0), &j_emlrtBCI);
          }
          i2 = wrappedData.size(0) * wrappedData.size(1);
          if (b_k + 1 > i2) {
            rtDynamicBoundsError(b_k + 1, 1, i2, &i_emlrtBCI);
          }
          wrappedData[b_k].im = wrappedData[b_k].im + b_x[i1 - 1].im;
        }
      }
      i1 = xin.size(1) * xin.size(2);
      if ((iCol + 1 < 1) || (iCol + 1 > i1)) {
        rtDynamicBoundsError(iCol + 1, 1, i1, &k_emlrtBCI);
      }
      bcoef = wrappedData.size(0) * wrappedData.size(1);
      rtSubAssignSizeCheck(xin.size(), 1, &bcoef, 1, &b_emlrtECI);
      bcoef = wrappedData.size(0) * wrappedData.size(1);
      c[0] = xin.size(0);
      for (i1 = 0; i1 < bcoef; i1++) {
        xin[i1 + c[0] * iCol] = wrappedData[i1];
      }
    }
  } else {
    xin.set_size(b_c.size(0), b_c.size(1), b_c.size(2));
    loop_ub = b_c.size(0) * b_c.size(1) * b_c.size(2);
    for (i = 0; i < loop_ub; i++) {
      xin[i] = b_c[i];
    }
  }
  if (xin.size(0) == 1) {
    g_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  if ((xin.size(0) == 0) || (xin.size(1) == 0) || (opts.FFTLength == 0.0)) {
    varargout_1.set_size(b_loop_ub, xin.size(1), xin.size(2));
    loop_ub = b_loop_ub * xin.size(1) * xin.size(2);
    for (i = 0; i < loop_ub; i++) {
      varargout_1[i].re = 0.0;
      varargout_1[i].im = 0.0;
    }
  } else {
    boolean_T useRadix2;
    useRadix2 =
        ((opts.FFTLength > 0.0) && ((b_loop_ub & (b_loop_ub - 1)) == 0));
    internal::FFTImplementationCallback::get_algo_sizes(
        static_cast<int>(opts.FFTLength), useRadix2, &bcoef, &b_bcoef);
    internal::FFTImplementationCallback::generate_twiddle_tables(
        b_bcoef, useRadix2, w1, sintab, sintabinv);
    if (useRadix2) {
      internal::FFTImplementationCallback::r2br_r2dit_trig(
          xin, static_cast<int>(opts.FFTLength), w1, sintab, varargout_1);
    } else {
      internal::FFTImplementationCallback::dobluesteinfft(
          xin, bcoef, static_cast<int>(opts.FFTLength), w1, sintab, sintabinv,
          varargout_1);
    }
  }
  if (std::isnan(opts.EffectiveFs)) {
    Fs1 = 6.2831853071795862;
  } else {
    Fs1 = opts.EffectiveFs;
  }
  freq_res = Fs1 / opts.FFTLength;
  if (opts.FFTLength - 1.0 < 0.0) {
    w1.set_size(w1.size(0), 0);
  } else {
    w1.set_size(1, static_cast<int>(opts.FFTLength));
    loop_ub = static_cast<int>(opts.FFTLength) - 1;
    for (i = 0; i <= loop_ub; i++) {
      w1[i] = i;
    }
  }
  w1.set_size(1, w1.size(1));
  loop_ub = w1.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    w1[i] = freq_res * w1[i];
  }
  Nyq = Fs1 / 2.0;
  nCol = freq_res / 2.0;
  if (rt_remd_snf(opts.FFTLength, 2.0) != 0.0) {
    hopSize = (opts.FFTLength + 1.0) / 2.0;
    if (hopSize != std::floor(hopSize)) {
      rtIntegerError(hopSize, &b_emlrtDCI);
    }
    if ((static_cast<int>(hopSize) < 1) ||
        (static_cast<int>(hopSize) > w1.size(1))) {
      rtDynamicBoundsError(static_cast<int>(hopSize), 1, w1.size(1),
                           &l_emlrtBCI);
    }
    w1[static_cast<int>(hopSize) - 1] = Nyq - nCol;
    if ((static_cast<int>(hopSize) + 1 < 1) ||
        (static_cast<int>(hopSize) + 1 > w1.size(1))) {
      rtDynamicBoundsError(static_cast<int>(hopSize) + 1, 1, w1.size(1),
                           &m_emlrtBCI);
    }
    w1[static_cast<int>(hopSize)] = Nyq + nCol;
  } else {
    d = opts.FFTLength / 2.0 + 1.0;
    if (d != std::floor(d)) {
      rtIntegerError(d, &n_emlrtDCI);
    }
    if ((static_cast<int>(d) < 1) || (static_cast<int>(d) > w1.size(1))) {
      rtDynamicBoundsError(static_cast<int>(d), 1, w1.size(1), &y_emlrtBCI);
    }
    w1[static_cast<int>(d) - 1] = Nyq;
  }
  if ((opts.FFTLength < 1.0) || (b_loop_ub > w1.size(1))) {
    rtDynamicBoundsError(static_cast<int>(opts.FFTLength), 1, w1.size(1),
                         &n_emlrtBCI);
  }
  w1[static_cast<int>(opts.FFTLength) - 1] = Fs1 - freq_res;
  f.set_size(w1.size(1));
  loop_ub = w1.size(1);
  for (i = 0; i < loop_ub; i++) {
    f[i] = w1[i];
  }
  bcoef = memcmp(&opts.FreqRange[0], &b[0], 8);
  if (bcoef == 0) {
    bcoef = 0;
  } else {
    bcoef = memcmp(&opts.FreqRange[0], &b_b[0], 8);
    if (bcoef == 0) {
      bcoef = 1;
    } else {
      bcoef = -1;
    }
  }
  switch (bcoef) {
  case 0:
    signal::internal::spectral::centerest(varargout_1);
    if (signalwavelet::internal::iseven(static_cast<double>(w1.size(1)))) {
      d = static_cast<double>(w1.size(1)) / 2.0;
      if (d != std::floor(d)) {
        rtIntegerError(d, &j_emlrtDCI);
      }
      if ((static_cast<int>(d) < 1) || (static_cast<int>(d) > w1.size(1))) {
        rtDynamicBoundsError(static_cast<int>(d), 1, w1.size(1), &s_emlrtBCI);
      }
      nCol = w1[static_cast<int>(d) - 1];
      f.set_size(w1.size(1));
      loop_ub = w1.size(1);
      for (i = 0; i < loop_ub; i++) {
        f[i] = w1[i] - nCol;
      }
    } else {
      d = (static_cast<double>(w1.size(1)) + 1.0) / 2.0;
      if (d != std::floor(d)) {
        rtIntegerError(d, &k_emlrtDCI);
      }
      if ((static_cast<int>(d) < 1) || (static_cast<int>(d) > w1.size(1))) {
        rtDynamicBoundsError(static_cast<int>(d), 1, w1.size(1), &t_emlrtBCI);
      }
      nCol = w1[static_cast<int>(d) - 1];
      f.set_size(w1.size(1));
      loop_ub = w1.size(1);
      for (i = 0; i < loop_ub; i++) {
        f[i] = w1[i] - nCol;
      }
    }
    break;
  case 1:
    break;
  default:
    if (varargout_1.size(0) != opts.NumFreqSamples) {
      if (opts.NumFreqSamples < 1.0) {
        loop_ub = 0;
      } else {
        if (varargout_1.size(0) < 1) {
          rtDynamicBoundsError(1, 1, varargout_1.size(0), &w_emlrtBCI);
        }
        if (opts.NumFreqSamples !=
            static_cast<int>(std::floor(opts.NumFreqSamples))) {
          rtIntegerError(opts.NumFreqSamples, &m_emlrtDCI);
        }
        if ((static_cast<int>(opts.NumFreqSamples) < 1) ||
            (static_cast<int>(opts.NumFreqSamples) > varargout_1.size(0))) {
          rtDynamicBoundsError(static_cast<int>(opts.NumFreqSamples), 1,
                               varargout_1.size(0), &x_emlrtBCI);
        }
        loop_ub = static_cast<int>(opts.NumFreqSamples);
      }
      bcoef = varargout_1.size(1) - 1;
      b_bcoef = varargout_1.size(2) - 1;
      b_loop_ub = varargout_1.size(1);
      for (i = 0; i <= b_bcoef; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            varargout_1[(i2 + loop_ub * i1) + loop_ub * (bcoef + 1) * i] =
                varargout_1[(i2 + varargout_1.size(0) * i1) +
                            varargout_1.size(0) * varargout_1.size(1) * i];
          }
        }
      }
      varargout_1.set_size(loop_ub, bcoef + 1, b_bcoef + 1);
    }
    if (w1.size(1) != opts.NumFreqSamples) {
      if (opts.NumFreqSamples < 1.0) {
        i = 0;
      } else {
        if (w1.size(1) < 1) {
          rtDynamicBoundsError(1, 1, w1.size(1), &u_emlrtBCI);
        }
        if (opts.NumFreqSamples !=
            static_cast<int>(std::floor(opts.NumFreqSamples))) {
          rtIntegerError(opts.NumFreqSamples, &l_emlrtDCI);
        }
        if ((static_cast<int>(opts.NumFreqSamples) < 1) ||
            (static_cast<int>(opts.NumFreqSamples) > w1.size(1))) {
          rtDynamicBoundsError(static_cast<int>(opts.NumFreqSamples), 1,
                               w1.size(1), &v_emlrtBCI);
        }
        i = static_cast<int>(opts.NumFreqSamples);
      }
      c[0] = 1;
      c[1] = i;
      internal::indexShapeCheck(w1.size(1), c);
      f.set_size(i);
    }
    break;
  }
  if (varargout_1.size(0) < 1) {
    loop_ub = 0;
  } else {
    if (f.size(0) < 1) {
      rtDynamicBoundsError(1, 1, f.size(0), &q_emlrtBCI);
    }
    if (varargout_1.size(0) > f.size(0)) {
      rtDynamicBoundsError(varargout_1.size(0), 1, f.size(0), &r_emlrtBCI);
    }
    loop_ub = varargout_1.size(0);
  }
  c[0] = 1;
  c[1] = loop_ub;
  internal::indexShapeCheck(f.size(0), c);
  varargout_2.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    varargout_2[i] = f[i];
  }
  if (varargout_1.size(1) < 1) {
    loop_ub = 0;
  } else {
    if (y.size(1) < 1) {
      rtDynamicBoundsError(1, 1, y.size(1), &o_emlrtBCI);
    }
    if (varargout_1.size(1) > y.size(1)) {
      rtDynamicBoundsError(varargout_1.size(1), 1, y.size(1), &p_emlrtBCI);
    }
    loop_ub = varargout_1.size(1);
  }
  varargout_3.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    varargout_3[i] = y[i];
  }
}

} // namespace coder

//
// File trailer for stft.cpp
//
// [EOF]
//
