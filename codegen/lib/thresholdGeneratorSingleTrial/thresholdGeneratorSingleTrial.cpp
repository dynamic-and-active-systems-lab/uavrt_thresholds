//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorSingleTrial.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:59
//

// Include Files
#include "thresholdGeneratorSingleTrial.h"
#include "eml_int_forloop_overflow_check.h"
#include "sparse1.h"
#include "thresholdGeneratorSingleTrial_internal_types.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string>

// Type Definitions
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

// Function Declarations
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                                 const rtBoundsCheckInfo *aInfo);

static void rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtIntegerError(const double aInteger,
                           const rtDoubleCheckInfo *aInfo);

static boolean_T rtIsNullOrEmptyString(const char *aString);

static void rtNonNegativeError(const double aPositive,
                               const rtDoubleCheckInfo *aInfo);

static double rt_hypotd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Incorrect dimensions for matrix multiplication. Check that the "
         "number of columns in the first matrix matches the number of rows "
         "in the second matrix. To operate on each element of the matrix "
         "individually, use TIMES (.*) for elementwise multiplication.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Inner dimensions must agree. Generated code for a general matrix "
         "multiplication at this call site. If this should have been a sc"
         "alar times a variable-size matrix, the scalar input must be "
         "fixed-size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : int aIndexValue
//                int aLoBound
//                int aHiBound
//                const rtBoundsCheckInfo *aInfo
// Return Type  : void
//
static void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                                 const rtBoundsCheckInfo *aInfo)
{
  std::stringstream b_outStream;
  std::stringstream outStream;
  if (aLoBound == 0) {
    aIndexValue++;
    aLoBound = 1;
    aHiBound++;
  }
  if (rtIsNullOrEmptyString(aInfo->aName)) {
    ((((((b_outStream << "Index exceeds array dimensions. Index value ")
         << aIndexValue)
        << " exceeds valid range [")
       << aLoBound)
      << "-")
     << aHiBound)
        << "].";
    b_outStream << "\n";
    ((((b_outStream << "Error in ") << aInfo->fName) << " (line ")
     << aInfo->lineNo)
        << ")";
    throw std::runtime_error(b_outStream.str());
  } else {
    ((((((((outStream << "Index exceeds array dimensions. Index value ")
           << aIndexValue)
          << " exceeds valid range [")
         << aLoBound)
        << "-")
       << aHiBound)
      << "] for array \'")
     << aInfo->aName)
        << "\'.";
    outStream << "\n";
    ((((outStream << "Error in ") << aInfo->fName) << " (line ")
     << aInfo->lineNo)
        << ")";
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "If the working dimension of MAX or MIN is variable in length, "
               "it must not have zero length at runtime.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const double aInteger
//                const rtDoubleCheckInfo *aInfo
// Return Type  : void
//
static void rtIntegerError(const double aInteger,
                           const rtDoubleCheckInfo *aInfo)
{
  std::stringstream outStream;
  ((outStream << "Expected a value representable in the C type \'int\'. Found ")
   << aInteger)
      << " instead.";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo->fName) << " (line ") << aInfo->lineNo)
      << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aString
// Return Type  : boolean_T
//
static boolean_T rtIsNullOrEmptyString(const char *aString)
{
  return (aString == nullptr) || (*aString == '\x00');
}

//
// Arguments    : const double aPositive
//                const rtDoubleCheckInfo *aInfo
// Return Type  : void
//
static void rtNonNegativeError(const double aPositive,
                               const rtDoubleCheckInfo *aInfo)
{
  std::stringstream outStream;
  ((outStream << "Value ") << aPositive)
      << " is not greater than or equal to zero.\nExiting to prevent memory "
         "corruption.";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo->fName) << " (line ") << aInfo->lineNo)
      << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * std::sqrt(y * y + 1.0);
  } else if (!std::isnan(y)) {
    y = a * 1.4142135623730951;
  }
  return y;
}

//
// Arguments    : const coder::array<creal_T, 2U> &W
//                const coder::array<creal_T, 3U> &Ssynth
//                const coder::sparse *Wq
//                double i
// Return Type  : double
//
double thresholdGeneratorSingleTrial(const coder::array<creal_T, 2U> &W,
                                     const coder::array<creal_T, 3U> &Ssynth,
                                     const coder::sparse *Wq, double i)
{
  static rtBoundsCheckInfo emlrtBCI{
      -1,                                                             // iFirst
      -1,                                                             // iLast
      4,                                                              // lineNo
      36,                                                             // colNo
      "Ssynth",                                                       // aName
      "thresholdGeneratorSingleTrial",                                // fName
      "H:\\repos\\uavrt_thresholds\\thresholdGeneratorSingleTrial.m", // pName
      0 // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      136,        // lineNo
      13,         // colNo
      "fsmtimes", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
      "sparse\\mtimes.m", // pName
      4                   // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      4,                                                              // lineNo
      18,                                                             // colNo
      "thresholdGeneratorSingleTrial",                                // fName
      "H:\\repos\\uavrt_thresholds\\thresholdGeneratorSingleTrial.m", // pName
      4 // checkKind
  };
  static rtDoubleCheckInfo emlrtDCI{
      4,                                                              // lineNo
      36,                                                             // colNo
      "thresholdGeneratorSingleTrial",                                // fName
      "H:\\repos\\uavrt_thresholds\\thresholdGeneratorSingleTrial.m", // pName
      1 // checkKind
  };
  static rtRunTimeErrorInfo b_emlrtRTEI{
      29,             // lineNo
      "sparse/mtimes" // fName
  };
  static rtRunTimeErrorInfo c_emlrtRTEI{
      135,            // lineNo
      "unaryMinOrMax" // fName
  };
  static rtRunTimeErrorInfo d_emlrtRTEI{
      138,                  // lineNo
      "dynamic_size_checks" // fName
  };
  static rtRunTimeErrorInfo emlrtRTEI{
      133,                  // lineNo
      "dynamic_size_checks" // fName
  };
  coder::array<creal_T, 2U> b;
  coder::array<creal_T, 2U> y;
  coder::array<double, 2U> b_y;
  coder::array<double, 2U> varargin_1;
  double s_re;
  double scores;
  int a;
  int aoff;
  int aoffset;
  int b_i;
  int boffset;
  int c_i;
  int coff;
  int coffset;
  int inner;
  int k;
  int m;
  int n;
  boolean_T overflow;
  printf("thresholdGeneratorSingleTrial - trial %f\n", i);
  fflush(stdout);
  //  'all' call finds max across all temporal correlation sets and frequency
  //  bins just like we do in the dectection code.
  if (i != static_cast<int>(std::floor(i))) {
    rtIntegerError(i, &emlrtDCI);
  }
  if ((static_cast<int>(i) < 1) || (static_cast<int>(i) > Ssynth.size(2))) {
    rtDynamicBoundsError(static_cast<int>(i), 1, Ssynth.size(2), &emlrtBCI);
  }
  aoff = Ssynth.size(0);
  aoffset = Ssynth.size(1);
  b.set_size(Ssynth.size(0), Ssynth.size(1));
  for (b_i = 0; b_i < aoffset; b_i++) {
    for (inner = 0; inner < aoff; inner++) {
      b[inner + b.size(0) * b_i] =
          Ssynth[(inner + Ssynth.size(0) * b_i) +
                 Ssynth.size(0) * Ssynth.size(1) * (static_cast<int>(i) - 1)];
    }
  }
  if (W.size(0) != Ssynth.size(0)) {
    if (((W.size(0) == 1) && (W.size(1) == 1)) ||
        ((Ssynth.size(0) == 1) && (Ssynth.size(1) == 1))) {
      c_rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
    } else {
      b_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
    }
  }
  m = W.size(1);
  inner = W.size(0);
  n = Ssynth.size(1) - 1;
  y.set_size(W.size(1), Ssynth.size(1));
  overflow = (Ssynth.size(1) > 2147483646);
  if (overflow) {
    coder::check_forloop_overflow_error();
  }
  for (coff = 0; coff <= n; coff++) {
    coffset = coff * m;
    boffset = coff * Ssynth.size(0);
    if (m > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (c_i = 0; c_i < m; c_i++) {
      double s_im;
      aoffset = c_i * W.size(0);
      s_re = 0.0;
      s_im = 0.0;
      if (inner > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      for (k = 0; k < inner; k++) {
        double W_im;
        double W_re;
        aoff = aoffset + k;
        W_re = W[aoff].re;
        W_im = -W[aoff].im;
        aoff = boffset + k;
        s_re += W_re * b[aoff].re - W_im * b[aoff].im;
        s_im += W_re * b[aoff].im + W_im * b[aoff].re;
      }
      b_i = coffset + c_i;
      y[b_i].re = s_re;
      y[b_i].im = s_im;
    }
  }
  aoffset = y.size(0) * y.size(1);
  b_y.set_size(y.size(0), y.size(1));
  if (aoffset > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (k = 0; k < aoffset; k++) {
    b_y[k] = rt_hypotd_snf(y[k].re, y[k].im);
  }
  aoff = b_y.size(0) * b_y.size(1);
  for (b_i = 0; b_i < aoff; b_i++) {
    s_re = b_y[b_i];
    b_y[b_i] = s_re * s_re;
  }
  if (b_y.size(1) != Wq->m) {
    b_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
  m = b_y.size(0);
  n = Wq->n - 1;
  varargin_1.set_size(b_y.size(0), varargin_1.size(1));
  if (Wq->n < 0) {
    rtNonNegativeError(static_cast<double>(Wq->n), &b_emlrtDCI);
  }
  varargin_1.set_size(varargin_1.size(0), Wq->n);
  if (Wq->n < 0) {
    rtNonNegativeError(static_cast<double>(Wq->n), &c_emlrtDCI);
  }
  aoff = b_y.size(0) * Wq->n;
  for (b_i = 0; b_i < aoff; b_i++) {
    varargin_1[b_i] = 0.0;
  }
  if ((b_y.size(1) != 0) && (b_y.size(0) != 0) && (Wq->n != 0) &&
      (Wq->colidx[Wq->colidx.size(0) - 1] - 1 != 0)) {
    if (b_y.size(0) == 1) {
      aoffset = Wq->n;
      if (Wq->n > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      for (k = 0; k < aoffset; k++) {
        s_re = 0.0;
        aoff = Wq->colidx[k + 1] - 1;
        a = Wq->colidx[k];
        if ((Wq->colidx[k] <= aoff) && (aoff > 2147483646)) {
          coder::check_forloop_overflow_error();
        }
        for (inner = a; inner <= aoff; inner++) {
          s_re += Wq->d[inner - 1] * b_y[Wq->rowidx[inner - 1] - 1];
        }
        varargin_1[k] = s_re;
      }
    } else if (b_y.size(0) >= 4) {
      if (Wq->n > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      for (k = 0; k <= n; k++) {
        coff = k * varargin_1.size(0);
        boffset = Wq->colidx[k + 1] - 1;
        a = Wq->colidx[k];
        if ((Wq->colidx[k] <= boffset) && (boffset > 2147483646)) {
          coder::check_forloop_overflow_error();
        }
        for (int bp{a}; bp <= boffset; bp++) {
          c_i = Wq->rowidx[bp - 1] - 1;
          aoff = c_i * b_y.size(0);
          s_re = Wq->d[bp - 1];
          coffset = (m / 4) << 2;
          if (coffset > 2147483643) {
            coder::check_forloop_overflow_error();
          }
          for (int crow{1}; crow <= coffset; crow += 4) {
            aoffset = crow + coff;
            inner = crow + aoff;
            varargin_1[aoffset - 1] =
                varargin_1[aoffset - 1] + b_y[inner - 1] * s_re;
            varargin_1[aoffset] = varargin_1[aoffset] + b_y[inner] * s_re;
            varargin_1[aoffset + 1] =
                varargin_1[aoffset + 1] + b_y[inner + 1] * s_re;
            varargin_1[aoffset + 2] =
                varargin_1[aoffset + 2] + b_y[inner + 2] * s_re;
          }
          aoff = coffset + 1;
          if ((coffset + 1 <= m) && (m > 2147483646)) {
            coder::check_forloop_overflow_error();
          }
          for (int crow{aoff}; crow <= m; crow++) {
            b_i = (crow + coff) - 1;
            varargin_1[b_i] =
                varargin_1[b_i] + b_y[(crow + b_y.size(0) * c_i) - 1] * s_re;
          }
        }
      }
    } else {
      if (Wq->n > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      for (k = 0; k <= n; k++) {
        boffset = Wq->colidx[k + 1] - 1;
        a = Wq->colidx[k];
        if ((Wq->colidx[k] <= boffset) && (boffset > 2147483646)) {
          coder::check_forloop_overflow_error();
        }
        for (int bp{a}; bp <= boffset; bp++) {
          for (int crow{0}; crow < m; crow++) {
            varargin_1[crow + varargin_1.size(0) * k] =
                varargin_1[crow + varargin_1.size(0) * k] +
                b_y[crow + b_y.size(0) * (Wq->rowidx[bp - 1] - 1)] *
                    Wq->d[bp - 1];
          }
        }
      }
    }
  }
  if (varargin_1.size(0) * varargin_1.size(1) < 1) {
    rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
  }
  aoffset = varargin_1.size(0) * varargin_1.size(1);
  if (varargin_1.size(0) * varargin_1.size(1) <= 2) {
    if (varargin_1.size(0) * varargin_1.size(1) == 1) {
      scores = varargin_1[0];
    } else if ((varargin_1[0] <
                varargin_1[varargin_1.size(0) * varargin_1.size(1) - 1]) ||
               (std::isnan(varargin_1[0]) &&
                (!std::isnan(
                    varargin_1[varargin_1.size(0) * varargin_1.size(1) -
                               1])))) {
      scores = varargin_1[varargin_1.size(0) * varargin_1.size(1) - 1];
    } else {
      scores = varargin_1[0];
    }
  } else {
    if (!std::isnan(varargin_1[0])) {
      aoff = 1;
    } else {
      boolean_T exitg1;
      aoff = 0;
      if (varargin_1.size(0) * varargin_1.size(1) > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= aoffset)) {
        if (!std::isnan(varargin_1[k - 1])) {
          aoff = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (aoff == 0) {
      scores = varargin_1[0];
    } else {
      scores = varargin_1[aoff - 1];
      a = aoff + 1;
      if ((aoff + 1 <= varargin_1.size(0) * varargin_1.size(1)) &&
          (varargin_1.size(0) * varargin_1.size(1) > 2147483646)) {
        coder::check_forloop_overflow_error();
      }
      for (k = a; k <= aoffset; k++) {
        if (scores < varargin_1[k - 1]) {
          scores = varargin_1[k - 1];
        }
      }
    }
  }
  return scores;
}

//
// File trailer for thresholdGeneratorSingleTrial.cpp
//
// [EOF]
//
