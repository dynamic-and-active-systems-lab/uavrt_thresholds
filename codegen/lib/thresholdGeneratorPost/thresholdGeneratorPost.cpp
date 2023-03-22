//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorPost.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:50
//

// Include Files
#include "thresholdGeneratorPost.h"
#include "blockedSummation.h"
#include "eml_int_forloop_overflow_check.h"
#include "evfit.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPost_internal_types.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>
#include <sstream>
#include <stdexcept>
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

// Function Declarations
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                                 const rtBoundsCheckInfo *aInfo);

static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum);

static void rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static boolean_T rtIsNullOrEmptyString(const char *aString);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Function values at interval endpoints must be finite and real.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Domain error. To compute complex results from real x, use \'")
   << r)
      << "(complex(x))\'.";
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
  outStream << "Second argument must be finite.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Unable to reach a maximum likelihood solution.";
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
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be nonempty.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Function values at the interval endpoints must differ in sign.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
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
// Arguments    : const coder::array<double, 1U> &scores
//                double *mu
//                double *sigma
// Return Type  : void
//
void thresholdGeneratorPost(const coder::array<double, 1U> &scores, double *mu,
                            double *sigma)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      13,                   // lineNo
      25,                   // colNo
      "",                   // aName
      "rangeWithCensoring", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\stats\\stats\\+stats\\+coder\\+"
      "internal\\rangeWithCensoring.m", // pName
      0                                 // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      15,                   // lineNo
      14,                   // colNo
      "",                   // aName
      "rangeWithCensoring", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\stats\\stats\\+stats\\+coder\\+"
      "internal\\rangeWithCensoring.m", // pName
      0                                 // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      16,                   // lineNo
      25,                   // colNo
      "",                   // aName
      "rangeWithCensoring", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\stats\\stats\\+stats\\+coder\\+"
      "internal\\rangeWithCensoring.m", // pName
      0                                 // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      12,                   // lineNo
      14,                   // colNo
      "",                   // aName
      "rangeWithCensoring", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\stats\\stats\\+stats\\+coder\\+"
      "internal\\rangeWithCensoring.m", // pName
      0                                 // checkKind
  };
  static rtRunTimeErrorInfo b_emlrtRTEI{
      13,                // lineNo
      "validatenonempty" // fName
  };
  static rtRunTimeErrorInfo c_emlrtRTEI{
      209,    // lineNo
      "evfit" // fName
  };
  static rtRunTimeErrorInfo d_emlrtRTEI{
      127,    // lineNo
      "fzero" // fName
  };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      137,    // lineNo
      "fzero" // fName
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      14,   // lineNo
      "log" // fName
  };
  static rtRunTimeErrorInfo g_emlrtRTEI{
      149,    // lineNo
      "fzero" // fName
  };
  static rtRunTimeErrorInfo h_emlrtRTEI{
      227,    // lineNo
      "evfit" // fName
  };
  static rtRunTimeErrorInfo i_emlrtRTEI{
      218,    // lineNo
      "evfit" // fName
  };
  coder::array<double, 1U> absdiff;
  coder::array<double, 1U> x;
  coder::array<double, 1U> x0;
  double rangex;
  double tempMax;
  double tempMin;
  int exponent;
  int k;
  int kend;
  x.set_size(scores.size(0));
  kend = scores.size(0);
  for (k = 0; k < kend; k++) {
    x[k] = -scores[k];
  }
  if (x.size(0) == 0) {
    rtErrorWithMessageID("X", b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
  tempMin = rtInf;
  tempMax = rtMinusInf;
  k = x.size(0);
  for (kend = 0; kend < k; kend++) {
    if (kend + 1 > x.size(0)) {
      rtDynamicBoundsError(kend + 1, 1, x.size(0), &emlrtBCI);
    }
    if (x[kend] > tempMax) {
      if (kend + 1 > x.size(0)) {
        rtDynamicBoundsError(kend + 1, 1, x.size(0), &b_emlrtBCI);
      }
      tempMax = x[kend];
    }
    if (kend + 1 > x.size(0)) {
      rtDynamicBoundsError(kend + 1, 1, x.size(0), &c_emlrtBCI);
    }
    if (x[kend] < tempMin) {
      if (kend + 1 > x.size(0)) {
        rtDynamicBoundsError(kend + 1, 1, x.size(0), &d_emlrtBCI);
      }
      tempMin = x[kend];
    }
  }
  rangex = tempMax - tempMin;
  if (std::isinf(rangex) || std::isnan(rangex)) {
    *mu = rtNaN;
    *sigma = rtNaN;
  } else if (rangex < 2.2250738585072014E-308) {
    *mu = x[0];
    *sigma = 0.0;
  } else {
    double fb;
    double savefa;
    double savefb;
    double scale;
    double t;
    double upper;
    double wgtmeanUnc;
    x0.set_size(x.size(0));
    kend = x.size(0);
    for (k = 0; k < kend; k++) {
      x0[k] = (x[k] - tempMax) / rangex;
    }
    kend = x0.size(0);
    if (x0.size(0) == 1) {
      if ((!std::isinf(x0[0])) && (!std::isnan(x0[0]))) {
        tempMin = 0.0;
      } else {
        tempMin = rtNaN;
      }
    } else {
      tempMin = coder::blockedSummation(x0, x0.size(0)) /
                static_cast<double>(x0.size(0));
      absdiff.set_size(x0.size(0));
      if (x0.size(0) > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      for (k = 0; k < kend; k++) {
        absdiff[k] = std::abs(x0[k] - tempMin);
      }
      tempMin = 0.0;
      scale = 3.3121686421112381E-170;
      kend = x0.size(0);
      for (k = 0; k < kend; k++) {
        if (absdiff[k] > scale) {
          t = scale / absdiff[k];
          tempMin = tempMin * t * t + 1.0;
          scale = absdiff[k];
        } else {
          t = absdiff[k] / scale;
          tempMin += t * t;
        }
      }
      tempMin = scale * std::sqrt(tempMin);
      tempMin /= std::sqrt(static_cast<double>(x0.size(0)) - 1.0);
    }
    scale = 2.4494897427831779 * tempMin / 3.1415926535897931;
    wgtmeanUnc = coder::blockedSummation(x0, x0.size(0)) /
                 static_cast<double>(x.size(0));
    if (coder::lkeqn(scale, x0, wgtmeanUnc) > 0.0) {
      upper = scale;
      scale *= 0.5;
      while (coder::lkeqn(scale, x0, wgtmeanUnc) > 0.0) {
        upper = scale;
        scale *= 0.5;
        if (scale < 2.2250738585072014E-308) {
          d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
        }
      }
    } else {
      upper = 2.0 * scale;
      while (coder::lkeqn(upper, x0, wgtmeanUnc) < 0.0) {
        scale = upper;
        upper *= 2.0;
        if (scale < 2.2250738585072014E-308) {
          d_rtErrorWithMessageID(i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
        }
      }
    }
    if (std::isinf(scale) || std::isnan(scale) ||
        (std::isinf(upper) || std::isnan(upper))) {
      c_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
    }
    tempMin = coder::lkeqn(scale, x0, wgtmeanUnc);
    fb = coder::lkeqn(upper, x0, wgtmeanUnc);
    if (std::isinf(tempMin) || std::isnan(tempMin) ||
        (std::isinf(fb) || std::isnan(fb))) {
      b_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
    }
    savefa = tempMin;
    savefb = fb;
    if (tempMin == 0.0) {
      upper = scale;
      fb = tempMin;
    } else if (!(fb == 0.0)) {
      double c;
      double d;
      double e;
      double fc;
      boolean_T exitg1;
      if ((tempMin > 0.0) == (fb > 0.0)) {
        rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
      }
      fc = fb;
      c = upper;
      e = 0.0;
      d = 0.0;
      exitg1 = false;
      while ((!exitg1) && ((fb != 0.0) && (scale != upper))) {
        double m;
        double toler;
        if ((fb > 0.0) == (fc > 0.0)) {
          c = scale;
          fc = tempMin;
          d = upper - scale;
          e = d;
        }
        if (std::abs(fc) < std::abs(fb)) {
          scale = upper;
          upper = c;
          c = scale;
          tempMin = fb;
          fb = fc;
          fc = tempMin;
        }
        m = 0.5 * (c - upper);
        toler = 2.0E-6 * std::fmax(std::abs(upper), 1.0);
        if ((std::abs(m) <= toler) || (fb == 0.0)) {
          exitg1 = true;
        } else {
          if ((std::abs(e) < toler) || (std::abs(tempMin) <= std::abs(fb))) {
            d = m;
            e = m;
          } else {
            double s;
            s = fb / tempMin;
            if (scale == c) {
              tempMin = 2.0 * m * s;
              t = 1.0 - s;
            } else {
              double r;
              t = tempMin / fc;
              r = fb / fc;
              tempMin =
                  s * (2.0 * m * t * (t - r) - (upper - scale) * (r - 1.0));
              t = (t - 1.0) * (r - 1.0) * (s - 1.0);
            }
            if (tempMin > 0.0) {
              t = -t;
            } else {
              tempMin = -tempMin;
            }
            if ((2.0 * tempMin < 3.0 * m * t - std::abs(toler * t)) &&
                (tempMin < std::abs(0.5 * e * t))) {
              e = d;
              d = tempMin / t;
            } else {
              d = m;
              e = m;
            }
          }
          scale = upper;
          tempMin = fb;
          if (std::abs(d) > toler) {
            upper += d;
          } else if (upper > c) {
            upper -= toler;
          } else {
            upper += toler;
          }
          fb = coder::lkeqn(upper, x0, wgtmeanUnc);
        }
      }
      if (!(std::abs(fb) <= std::fmax(std::abs(savefa), std::abs(savefb)))) {
        d_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
      }
    }
    tempMin = std::abs(fb);
    if ((!std::isinf(tempMin)) && (!std::isnan(tempMin)) &&
        (!(tempMin <= 2.2250738585072014E-308))) {
      frexp(tempMin, &exponent);
    }
    kend = x0.size(0);
    for (k = 0; k < kend; k++) {
      x0[k] = x0[k] / upper;
    }
    kend = x0.size(0);
    for (k = 0; k < kend; k++) {
      x0[k] = std::exp(x0[k]);
    }
    tempMin = coder::blockedSummation(x0, x0.size(0)) /
              static_cast<double>(x.size(0));
    if (tempMin < 0.0) {
      b_rtErrorWithMessageID("log", f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
    }
    tempMin = std::log(tempMin);
    *mu = rangex * (upper * tempMin) + tempMax;
    *sigma = rangex * upper;
  }
}

//
// File trailer for thresholdGeneratorPost.cpp
//
// [EOF]
//
