//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: stft.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "stft.h"
#include "centerest.h"
#include "computeDFT.h"
#include "indexShapeCheck.h"
#include "iseven.h"
#include "rt_nonfinite.h"
#include "stftParser.h"
#include "thresholdGeneratorPre_internal_types.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Non-singleton dimensions of the two input arrays must match "
               "each other.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
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
      -1,                                                           // iFirst
      -1,                                                           // iLast
      279,                                                          // lineNo
      12,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      279,                                                          // lineNo
      14,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
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
      -1,                                                           // iFirst
      -1,                                                           // iLast
      278,                                                          // lineNo
      12,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,                                                           // iFirst
      -1,                                                           // iLast
      278,                                                          // lineNo
      14,                                                           // colNo
      "",                                                           // aName
      "computeSTFT",                                                // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\signal\\stft.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
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
  static rtBoundsCheckInfo i_emlrtBCI{
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
  static rtBoundsCheckInfo j_emlrtBCI{
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
  static rtBoundsCheckInfo k_emlrtBCI{
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
  static rtBoundsCheckInfo l_emlrtBCI{
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
  static rtBoundsCheckInfo m_emlrtBCI{
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
  static rtDoubleCheckInfo b_emlrtDCI{
      14,               // lineNo
      30,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      4                         // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      14,               // lineNo
      30,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      14,               // lineNo
      5,                // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      23,               // lineNo
      23,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo f_emlrtDCI{
      23,               // lineNo
      42,               // colNo
      "getSTFTColumns", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\getSTFTColumns.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo g_emlrtDCI{
      13,           // lineNo
      13,           // colNo
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo h_emlrtDCI{
      16,           // lineNo
      13,           // colNo
      "centerfreq", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "spectral\\centerfreq.m", // pName
      1                         // checkKind
  };
  static rtDoubleCheckInfo i_emlrtDCI{
      23,                 // lineNo
      24,                 // colNo
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      1                           // checkKind
  };
  static rtDoubleCheckInfo j_emlrtDCI{
      18,                 // lineNo
      24,                 // colNo
      "formatSTFTOutput", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\+signal\\+internal\\+"
      "stft\\formatSTFTOutput.m", // pName
      1                           // checkKind
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
      53,      // lineNo
      "bsxfun" // fName
  };
  static const char b[8]{'c', 'e', 'n', 't', 'e', 'r', 'e', 'd'};
  static const char b_b[8]{'t', 'w', 'o', 's', 'i', 'd', 'e', 'd'};
  array<creal_T, 3U> c;
  array<creal_T, 3U> xin;
  array<creal_T, 2U> b_data;
  array<creal_T, 2U> data;
  array<double, 2U> y;
  array<double, 1U> f;
  c_struct_T opts;
  double hopSize;
  double nCol;
  int b_xin[3];
  int iv[2];
  int b_bcoef;
  int bcoef;
  int csz_idx_0;
  int i;
  int i1;
  int i2;
  int iCol;
  int k;
  int loop_ub;
  signal::internal::stft::stftParser(x, varargin_1, varargin_3, varargin_5,
                                     varargin_7, data, &opts);
  hopSize = opts.WindowLength - opts.OverlapLength;
  nCol = std::trunc((opts.DataLength - opts.OverlapLength) / hopSize);
  xin.set_size(static_cast<int>(opts.WindowLength), xin.size(1), xin.size(2));
  if (!(nCol >= 0.0)) {
    rtNonNegativeError(nCol, &b_emlrtDCI);
  }
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, &c_emlrtDCI);
  }
  xin.set_size(xin.size(0), static_cast<int>(nCol), data.size(1));
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, &d_emlrtDCI);
  }
  bcoef = static_cast<int>(opts.WindowLength) * static_cast<int>(nCol) *
          data.size(1);
  for (i = 0; i < bcoef; i++) {
    xin[i].re = 0.0;
    xin[i].im = 0.0;
  }
  if (nCol - 1.0 < 0.0) {
    y.set_size(y.size(0), 0);
  } else {
    y.set_size(1, static_cast<int>(nCol - 1.0) + 1);
    bcoef = static_cast<int>(nCol - 1.0);
    for (i = 0; i <= bcoef; i++) {
      y[i] = i;
    }
  }
  i = static_cast<int>(nCol);
  if (static_cast<int>(nCol) - 1 >= 0) {
    iv[1] = data.size(1);
    i1 = data.size(1);
    loop_ub = data.size(1);
  }
  for (iCol = 0; iCol < i; iCol++) {
    double d;
    nCol = hopSize * ((static_cast<double>(iCol) + 1.0) - 1.0);
    d = opts.WindowLength + nCol;
    if (nCol + 1.0 > d) {
      i2 = -1;
      k = -1;
    } else {
      if (nCol + 1.0 != static_cast<int>(std::floor(nCol + 1.0))) {
        rtIntegerError(nCol + 1.0, &e_emlrtDCI);
      }
      if ((static_cast<int>(nCol + 1.0) < 1) ||
          (static_cast<int>(nCol + 1.0) > data.size(0))) {
        rtDynamicBoundsError(static_cast<int>(nCol + 1.0), 1, data.size(0),
                             &b_emlrtBCI);
      }
      i2 = static_cast<int>(nCol + 1.0) - 2;
      if (d != static_cast<int>(std::floor(d))) {
        rtIntegerError(d, &f_emlrtDCI);
      }
      if ((static_cast<int>(d) < 1) || (static_cast<int>(d) > data.size(0))) {
        rtDynamicBoundsError(static_cast<int>(d), 1, data.size(0), &c_emlrtBCI);
      }
      k = static_cast<int>(d) - 1;
    }
    if ((iCol + 1 < 1) || (iCol + 1 > xin.size(1))) {
      rtDynamicBoundsError(iCol + 1, 1, xin.size(1), &emlrtBCI);
    }
    b_bcoef = xin.size(0);
    b_xin[0] = xin.size(0);
    b_xin[1] = 1;
    b_xin[2] = xin.size(2);
    bcoef = k - i2;
    iv[0] = bcoef;
    rtSubAssignSizeCheck(&b_xin[0], 3, &iv[0], 2, &emlrtECI);
    b_data.set_size(bcoef, i1);
    for (k = 0; k < loop_ub; k++) {
      for (int b_k{0}; b_k < bcoef; b_k++) {
        b_data[b_k + b_data.size(0) * k] =
            data[((i2 + b_k) + data.size(0) * k) + 1];
      }
    }
    b_xin[0] = xin.size(0);
    bcoef = xin.size(2);
    for (i2 = 0; i2 < bcoef; i2++) {
      for (k = 0; k < b_bcoef; k++) {
        xin[(k + xin.size(0) * iCol) + xin.size(0) * xin.size(1) * i2] =
            b_data[k + b_xin[0] * i2];
      }
    }
  }
  y.set_size(1, y.size(1));
  nCol = opts.WindowLength / 2.0;
  bcoef = y.size(1) - 1;
  for (i = 0; i <= bcoef; i++) {
    y[i] = (y[i] * hopSize + nCol) / opts.EffectiveFs;
  }
  if (xin.size(0) == 1) {
    csz_idx_0 = opts.Window.size(0);
  } else if (opts.Window.size(0) == 1) {
    csz_idx_0 = xin.size(0);
  } else if (opts.Window.size(0) == xin.size(0)) {
    csz_idx_0 = opts.Window.size(0);
  } else {
    m_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  c.set_size(csz_idx_0, xin.size(1), xin.size(2));
  if ((csz_idx_0 != 0) && (xin.size(1) != 0)) {
    b_bcoef = (xin.size(2) != 1);
    i = xin.size(2) - 1;
    csz_idx_0 = (xin.size(1) != 1);
    bcoef = (xin.size(0) != 1);
    for (k = 0; k <= i; k++) {
      loop_ub = b_bcoef * k;
      i1 = c.size(1) - 1;
      for (int b_k{0}; b_k <= i1; b_k++) {
        iCol = csz_idx_0 * b_k;
        i2 = c.size(0) - 1;
        for (int c_k{0}; c_k <= i2; c_k++) {
          c[(c_k + c.size(0) * b_k) + c.size(0) * c.size(1) * k] =
              xin[(bcoef * c_k + xin.size(0) * iCol) +
                  xin.size(0) * xin.size(1) * loop_ub];
        }
      }
    }
  }
  computeDFT(c, opts.FFTLength, opts.EffectiveFs, varargout_1, f);
  b_bcoef = memcmp(&opts.FreqRange[0], &b[0], 8);
  if (b_bcoef == 0) {
    b_bcoef = 0;
  } else {
    b_bcoef = memcmp(&opts.FreqRange[0], &b_b[0], 8);
    if (b_bcoef == 0) {
      b_bcoef = 1;
    } else {
      b_bcoef = -1;
    }
  }
  switch (b_bcoef) {
  case 0:
    signal::internal::spectral::centerest(varargout_1);
    if (signalwavelet::internal::iseven(static_cast<double>(f.size(0)))) {
      nCol = static_cast<double>(f.size(0)) / 2.0;
      if (nCol != std::floor(nCol)) {
        rtIntegerError(nCol, &g_emlrtDCI);
      }
      if ((static_cast<int>(nCol) < 1) ||
          (static_cast<int>(nCol) > f.size(0))) {
        rtDynamicBoundsError(static_cast<int>(nCol), 1, f.size(0), &h_emlrtBCI);
      }
      nCol = f[static_cast<int>(nCol) - 1];
      bcoef = f.size(0);
      for (i = 0; i < bcoef; i++) {
        f[i] = f[i] - nCol;
      }
    } else {
      nCol = (static_cast<double>(f.size(0)) + 1.0) / 2.0;
      if (nCol != std::floor(nCol)) {
        rtIntegerError(nCol, &h_emlrtDCI);
      }
      if ((static_cast<int>(nCol) < 1) ||
          (static_cast<int>(nCol) > f.size(0))) {
        rtDynamicBoundsError(static_cast<int>(nCol), 1, f.size(0), &i_emlrtBCI);
      }
      nCol = f[static_cast<int>(nCol) - 1];
      bcoef = f.size(0);
      for (i = 0; i < bcoef; i++) {
        f[i] = f[i] - nCol;
      }
    }
    break;
  case 1:
    break;
  default:
    if (varargout_1.size(0) != opts.NumFreqSamples) {
      if (opts.NumFreqSamples < 1.0) {
        bcoef = 0;
      } else {
        if (varargout_1.size(0) < 1) {
          rtDynamicBoundsError(1, 1, varargout_1.size(0), &l_emlrtBCI);
        }
        if (opts.NumFreqSamples !=
            static_cast<int>(std::floor(opts.NumFreqSamples))) {
          rtIntegerError(opts.NumFreqSamples, &j_emlrtDCI);
        }
        if ((static_cast<int>(opts.NumFreqSamples) < 1) ||
            (static_cast<int>(opts.NumFreqSamples) > varargout_1.size(0))) {
          rtDynamicBoundsError(static_cast<int>(opts.NumFreqSamples), 1,
                               varargout_1.size(0), &m_emlrtBCI);
        }
        bcoef = static_cast<int>(opts.NumFreqSamples);
      }
      b_bcoef = varargout_1.size(1) - 1;
      csz_idx_0 = varargout_1.size(2) - 1;
      loop_ub = varargout_1.size(1);
      for (i = 0; i <= csz_idx_0; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < bcoef; i2++) {
            varargout_1[(i2 + bcoef * i1) + bcoef * (b_bcoef + 1) * i] =
                varargout_1[(i2 + varargout_1.size(0) * i1) +
                            varargout_1.size(0) * varargout_1.size(1) * i];
          }
        }
      }
      varargout_1.set_size(bcoef, b_bcoef + 1, csz_idx_0 + 1);
    }
    if (f.size(0) != opts.NumFreqSamples) {
      if (opts.NumFreqSamples < 1.0) {
        i = 0;
      } else {
        if (f.size(0) < 1) {
          rtDynamicBoundsError(1, 1, f.size(0), &j_emlrtBCI);
        }
        if (opts.NumFreqSamples !=
            static_cast<int>(std::floor(opts.NumFreqSamples))) {
          rtIntegerError(opts.NumFreqSamples, &i_emlrtDCI);
        }
        if ((static_cast<int>(opts.NumFreqSamples) < 1) ||
            (static_cast<int>(opts.NumFreqSamples) > f.size(0))) {
          rtDynamicBoundsError(static_cast<int>(opts.NumFreqSamples), 1,
                               f.size(0), &k_emlrtBCI);
        }
        i = static_cast<int>(opts.NumFreqSamples);
      }
      iv[0] = 1;
      iv[1] = i;
      internal::indexShapeCheck(f.size(0), iv);
      f.set_size(i);
    }
    break;
  }
  if (varargout_1.size(0) < 1) {
    bcoef = 0;
  } else {
    if (f.size(0) < 1) {
      rtDynamicBoundsError(1, 1, f.size(0), &f_emlrtBCI);
    }
    if (varargout_1.size(0) > f.size(0)) {
      rtDynamicBoundsError(varargout_1.size(0), 1, f.size(0), &g_emlrtBCI);
    }
    bcoef = varargout_1.size(0);
  }
  iv[0] = 1;
  iv[1] = bcoef;
  internal::indexShapeCheck(f.size(0), iv);
  varargout_2.set_size(bcoef);
  for (i = 0; i < bcoef; i++) {
    varargout_2[i] = f[i];
  }
  if (varargout_1.size(1) < 1) {
    bcoef = 0;
  } else {
    if (y.size(1) < 1) {
      rtDynamicBoundsError(1, 1, y.size(1), &d_emlrtBCI);
    }
    if (varargout_1.size(1) > y.size(1)) {
      rtDynamicBoundsError(varargout_1.size(1), 1, y.size(1), &e_emlrtBCI);
    }
    bcoef = varargout_1.size(1);
  }
  varargout_3.set_size(bcoef);
  for (i = 0; i < bcoef; i++) {
    varargout_3[i] = y[i];
  }
}

} // namespace coder

//
// File trailer for stft.cpp
//
// [EOF]
//
