//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wgn.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "wgn.h"
#include "randn.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void l_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtSizeEqNDCheck(const int *aDims1, const int *aDims2,
                            const rtEqualityCheckInfo *aInfo);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void l_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "The required dimensions must be real, integer scalars > 1.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const int *aDims1
//                const int *aDims2
//                const rtEqualityCheckInfo *aInfo
// Return Type  : void
//
static void rtSizeEqNDCheck(const int *aDims1, const int *aDims2,
                            const rtEqualityCheckInfo *aInfo)
{
  std::stringstream outStream;
  for (int i{0}; i < aInfo->nDims; i++) {
    if (aDims1[i] != aDims2[i]) {
      std::string dims1Str;
      std::string dims2Str;
      dims1Str = rtGenSizeString(aInfo->nDims, aDims1);
      dims2Str = rtGenSizeString(aInfo->nDims, aDims2);
      ((((outStream << "Sizes mismatch: ") << dims1Str) << " ~= ") << dims2Str)
          << ".";
      outStream << "\n";
      ((((outStream << "Error in ") << aInfo->fName) << " (line ")
       << aInfo->lineNo)
          << ")";
      throw std::runtime_error(outStream.str());
    }
  }
}

//
// Arguments    : double varargin_1
//                double varargin_3
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
namespace coder {
void wgn(double varargin_1, double varargin_3, ::coder::array<creal_T, 2U> &y)
{
  static rtEqualityCheckInfo emlrtECI{
      2,                                                      // nDims
      223,                                                    // lineNo
      38,                                                     // colNo
      "wgn",                                                  // fName
      "C:\\Program Files\\MATLAB\\toolbox\\comm\\comm\\wgn.m" // pName
  };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      180,  // lineNo
      "wgn" // fName
  };
  static const char cv[128]{
      '\x00', '\x01',     '\x02', '\x03', '\x04', '\x05', '\x06', '\x07',
      '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
      '\x10', '\x11',     '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
      '\x18', '\x19',     '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f',
      ' ',    '!',        '\"',   '#',    '$',    '%',    '&',    '\'',
      '(',    ')',        '*',    '+',    ',',    '-',    '.',    '/',
      '0',    '1',        '2',    '3',    '4',    '5',    '6',    '7',
      '8',    '9',        ':',    ';',    '<',    '=',    '>',    '?',
      '@',    'a',        'b',    'c',    'd',    'e',    'f',    'g',
      'h',    'i',        'j',    'k',    'l',    'm',    'n',    'o',
      'p',    'q',        'r',    's',    't',    'u',    'v',    'w',
      'x',    'y',        'z',    '[',    '\\',   ']',    '^',    '_',
      '`',    'a',        'b',    'c',    'd',    'e',    'f',    'g',
      'h',    'i',        'j',    'k',    'l',    'm',    'n',    'o',
      'p',    'q',        'r',    's',    't',    'u',    'v',    'w',
      'x',    'y',        'z',    '{',    '|',    '}',    '~',    '\x7f'};
  static const char b_b[7]{'c', 'o', 'm', 'p', 'l', 'e', 'x'};
  static const char cv2[7]{'c', 'o', 'm', 'p', 'l', 'e', 'x'};
  static const char b[6]{'l', 'i', 'n', 'e', 'a', 'r'};
  static const char cv1[6]{'l', 'i', 'n', 'e', 'a', 'r'};
  array<double, 2U> c_b;
  array<double, 2U> r;
  double noisePower;
  int iv[2];
  int iv1[2];
  int b_y;
  int exitg2;
  int k;
  char cplxMode_data[7];
  char pMode_data[6];
  char switch_expression_data[6];
  boolean_T x[6];
  boolean_T c_y;
  boolean_T exitg1;
  for (b_y = 0; b_y < 6; b_y++) {
    pMode_data[b_y] = b[b_y];
  }
  for (b_y = 0; b_y < 7; b_y++) {
    cplxMode_data[b_y] = b_b[b_y];
  }
  x[0] = (varargin_1 <= 0.0);
  x[1] = false;
  x[2] = false;
  x[3] = false;
  x[4] = (varargin_1 - std::floor(varargin_1) != 0.0);
  x[5] = false;
  c_y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 6)) {
    if (x[k]) {
      c_y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (c_y) {
    l_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  for (k = 0; k < 6; k++) {
    switch_expression_data[k] = cv[static_cast<int>(pMode_data[k])];
  }
  c_y = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 6) {
      if (switch_expression_data[k] != cv1[k]) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      c_y = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);
  if (c_y) {
    b_y = 0;
  } else {
    b_y = -1;
  }
  if (b_y == 0) {
    noisePower = varargin_3;
  } else {
    noisePower = rt_powd_snf(10.0, (varargin_3 - 30.0) / 10.0);
  }
  c_y = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 7) {
      if (cplxMode_data[k] != cv2[k]) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      c_y = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);
  if (c_y) {
    randn(varargin_1, r);
    randn(varargin_1, c_b);
    y.set_size(c_b.size(0), 1000);
    k = c_b.size(0) * 1000;
    for (b_y = 0; b_y < k; b_y++) {
      y[b_y].re = c_b[b_y] * 0.0;
      y[b_y].im = c_b[b_y];
    }
    iv[0] = (*(int(*)[2])r.size())[0];
    iv[1] = (*(int(*)[2])r.size())[1];
    iv1[0] = (*(int(*)[2])y.size())[0];
    iv1[1] = (*(int(*)[2])y.size())[1];
    rtSizeEqNDCheck(&iv[0], &iv1[0], &emlrtECI);
    noisePower = std::sqrt(noisePower / 2.0);
    k = r.size(0) * 1000;
    y.set_size(r.size(0), 1000);
    for (b_y = 0; b_y < k; b_y++) {
      y[b_y].re = noisePower * (r[b_y] + y[b_y].re);
      y[b_y].im = noisePower * y[b_y].im;
    }
  } else {
    noisePower = std::sqrt(noisePower);
    randn(varargin_1, c_b);
    y.set_size(c_b.size(0), 1000);
    k = c_b.size(0) * 1000;
    for (b_y = 0; b_y < k; b_y++) {
      y[b_y].re = noisePower * c_b[b_y];
      y[b_y].im = 0.0;
    }
  }
}

} // namespace coder

//
// File trailer for wgn.cpp
//
// [EOF]
//
