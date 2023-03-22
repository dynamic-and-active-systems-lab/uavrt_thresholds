//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: stftParser.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "stftParser.h"
#include "iseven.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_internal_types.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void c_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void d_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void e_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void f_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void g_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtErrorWithMessageID(const char *r, const char *r1, const char *r2,
                                 const char *aFcnName, int aLineNum);

static void rtErrorWithMessageID(const long long i, const char *aFcnName,
                                 int aLineNum);

// Function Definitions
//
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be nonempty.";
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
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void c_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be integer-valued.";
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
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void d_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be nonnegative.";
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
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void e_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be non-NaN.";
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
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void f_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be finite.";
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
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void g_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be positive.";
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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream
      << "Input signal must be a real-valued vector, matrix, or timetable when "
         "\'FrequencyRange\' is specified as \'onesided\'.";
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
// Arguments    : const char *r
//                const char *r1
//                const char *r2
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *r, const char *r1, const char *r2,
                                 const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((((((outStream << "Expected ") << r) << " to be a scalar with value ") << r1)
    << " ")
   << r2)
      << ".";
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
// Arguments    : const long long i
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const long long i, const char *aFcnName,
                                 int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Input signal length must be greater than or equal to the "
                 "window length, ")
   << i)
      << ".";
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
// Arguments    : const ::coder::array<creal_T, 2U> &x
//                double varargin_1
//                const ::coder::array<double, 1U> &varargin_3
//                double varargin_5
//                double varargin_7
//                ::coder::array<creal_T, 2U> &varargout_1
//                c_struct_T *varargout_2
// Return Type  : void
//
namespace coder {
namespace signal {
namespace internal {
namespace stft {
void stftParser(const ::coder::array<creal_T, 2U> &x, double varargin_1,
                const ::coder::array<double, 1U> &varargin_3, double varargin_5,
                double varargin_7, ::coder::array<creal_T, 2U> &varargout_1,
                c_struct_T *varargout_2)
{
  static rtRunTimeErrorInfo e_emlrtRTEI{
      13,                // lineNo
      "validatenonempty" // fName
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      22,          // lineNo
      "validategt" // fName
  };
  static rtRunTimeErrorInfo g_emlrtRTEI{
      13,               // lineNo
      "validateinteger" // fName
  };
  static rtRunTimeErrorInfo h_emlrtRTEI{
      14,                   // lineNo
      "validatenonnegative" // fName
  };
  static rtRunTimeErrorInfo i_emlrtRTEI{
      22,          // lineNo
      "validatelt" // fName
  };
  static rtRunTimeErrorInfo j_emlrtRTEI{
      22,          // lineNo
      "validatege" // fName
  };
  static rtRunTimeErrorInfo k_emlrtRTEI{
      14,              // lineNo
      "validatefinite" // fName
  };
  static rtRunTimeErrorInfo l_emlrtRTEI{
      14,              // lineNo
      "validatenonnan" // fName
  };
  static rtRunTimeErrorInfo m_emlrtRTEI{
      386,                // lineNo
      "verifyDataAndTime" // fName
  };
  static rtRunTimeErrorInfo n_emlrtRTEI{
      419,                // lineNo
      "verifyDataAndTime" // fName
  };
  static rtRunTimeErrorInfo o_emlrtRTEI{
      14,                // lineNo
      "validatepositive" // fName
  };
  static const char timeDimension[13]{'a', 'c', 'r', 'o', 's', 's', 'c',
                                      'o', 'l', 'u', 'm', 'n', 's'};
  static const char b[8]{'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'};
  static const char freqRange[8]{'c', 'e', 'n', 't', 'e', 'r', 'e', 'd'};
  int i;
  int ret;
  boolean_T exitg1;
  boolean_T isOnesided;
  if (varargin_3.size(0) == 0) {
    b_rtErrorWithMessageID("Window", e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  if (varargin_3.size(0) <= 1) {
    rtErrorWithMessageID("WindowLength", ">", "1", f_emlrtRTEI.fName,
                         f_emlrtRTEI.lineNo);
  }
  if (std::isinf(varargin_5) || std::isnan(varargin_5) ||
      (!(std::floor(varargin_5) == varargin_5))) {
    c_rtErrorWithMessageID("OverlapLength", g_emlrtRTEI.fName,
                           g_emlrtRTEI.lineNo);
  }
  if (varargin_5 < 0.0) {
    d_rtErrorWithMessageID("OverlapLength", h_emlrtRTEI.fName,
                           h_emlrtRTEI.lineNo);
  }
  if (!(varargin_5 < varargin_3.size(0))) {
    rtErrorWithMessageID("OverlapLength", "<", "NaN", i_emlrtRTEI.fName,
                         i_emlrtRTEI.lineNo);
  }
  if (std::isinf(varargin_7) || std::isnan(varargin_7) ||
      (!(std::floor(varargin_7) == varargin_7))) {
    c_rtErrorWithMessageID("FFTLength", g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  if (varargin_7 < 0.0) {
    d_rtErrorWithMessageID("FFTLength", h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  if (!(varargin_7 >= varargin_3.size(0))) {
    rtErrorWithMessageID("FFTLength", ">=", "NaN", j_emlrtRTEI.fName,
                         j_emlrtRTEI.lineNo);
  }
  isOnesided = true;
  i = x.size(0) * 1000;
  ret = 0;
  exitg1 = false;
  while ((!exitg1) && (ret <= i - 1)) {
    if ((!std::isinf(x[ret].re)) && (!std::isinf(x[ret].im)) &&
        ((!std::isnan(x[ret].re)) && (!std::isnan(x[ret].im)))) {
      ret++;
    } else {
      isOnesided = false;
      exitg1 = true;
    }
  }
  if (!isOnesided) {
    f_rtErrorWithMessageID("X", k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  isOnesided = true;
  i = x.size(0) * 1000;
  ret = 0;
  exitg1 = false;
  while ((!exitg1) && (ret <= i - 1)) {
    if ((!std::isnan(x[ret].re)) && (!std::isnan(x[ret].im))) {
      ret++;
    } else {
      isOnesided = false;
      exitg1 = true;
    }
  }
  if (!isOnesided) {
    e_rtErrorWithMessageID("X", l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
  }
  if (x.size(0) == 0) {
    b_rtErrorWithMessageID("X", e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  if (x.size(0) == 1) {
    varargout_1.set_size(1000, 1);
    for (i = 0; i < 1000; i++) {
      varargout_1[i] = x[i];
    }
  } else {
    varargout_1.set_size(x.size(0), 1000);
    ret = x.size(0) * 1000;
    for (i = 0; i < ret; i++) {
      varargout_1[i] = x[i];
    }
  }
  varargout_2->NumChannels = varargout_1.size(1);
  ret = memcmp(&freqRange[0], &b[0], 8);
  isOnesided = (ret == 0);
  if (isOnesided) {
    if (signalwavelet::internal::iseven(varargin_7)) {
      varargout_2->NumFreqSamples = varargin_7 / 2.0 + 1.0;
    } else {
      varargout_2->NumFreqSamples = (varargin_7 + 1.0) / 2.0;
    }
  } else {
    varargout_2->NumFreqSamples = varargin_7;
  }
  if (varargin_3.size(0) > varargout_1.size(0)) {
    rtErrorWithMessageID(static_cast<long long>(varargin_3.size(0)),
                         m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
  }
  if (isOnesided) {
    n_rtErrorWithMessageID(n_emlrtRTEI.fName, n_emlrtRTEI.lineNo);
  }
  varargout_2->DataLength = varargout_1.size(0);
  varargout_2->TimeAxisLength = 0.0;
  varargout_2->IsSingle = false;
  varargout_2->IsNormalizedFreq = false;
  varargout_2->Window.set_size(varargin_3.size(0));
  ret = varargin_3.size(0);
  for (i = 0; i < ret; i++) {
    varargout_2->Window[i] = varargin_3[i];
  }
  varargout_2->WindowLength = varargin_3.size(0);
  varargout_2->OverlapLength = varargin_5;
  varargout_2->FFTLength = varargin_7;
  for (i = 0; i < 8; i++) {
    varargout_2->FreqRange[i] = freqRange[i];
  }
  varargout_2->ConjugateSymmetric = false;
  for (i = 0; i < 13; i++) {
    varargout_2->TimeDimension[i] = timeDimension[i];
  }
  varargout_2->TimeMode[0] = 'f';
  varargout_2->TimeMode[1] = 's';
  if (std::isinf(varargin_1) || std::isnan(varargin_1)) {
    f_rtErrorWithMessageID("sample rate", k_emlrtRTEI.fName,
                           k_emlrtRTEI.lineNo);
  }
  if (varargin_1 <= 0.0) {
    g_rtErrorWithMessageID("sample rate", o_emlrtRTEI.fName,
                           o_emlrtRTEI.lineNo);
  }
  varargout_2->EffectiveFs = varargin_1;
}

} // namespace stft
} // namespace internal
} // namespace signal
} // namespace coder

//
// File trailer for stftParser.cpp
//
// [EOF]
//
