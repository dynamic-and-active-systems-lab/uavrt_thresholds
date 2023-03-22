//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sparse1.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "sparse1.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
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
static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void j_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void k_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Index into matrix must be an integer.";
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
static void j_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Index into matrix is too large.";
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
static void k_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Index into matrix must be positive.";
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
// Arguments    : const ::coder::array<double, 1U> &s
//                ::coder::array<int, 1U> &sint
// Return Type  : void
//
namespace coder {
void sparse::assertValidIndexArg(const ::coder::array<double, 1U> &s,
                                 ::coder::array<int, 1U> &sint)
{
  static rtRunTimeErrorInfo e_emlrtRTEI{
      1658,                 // lineNo
      "assertValidIndexArg" // fName
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      1660,                 // lineNo
      "assertValidIndexArg" // fName
  };
  static rtRunTimeErrorInfo g_emlrtRTEI{
      1662,                 // lineNo
      "assertValidIndexArg" // fName
  };
  int ns;
  ns = s.size(0);
  sint.set_size(s.size(0));
  if (s.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < ns; k++) {
    if (!(std::floor(s[k]) == s[k])) {
      i_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
    }
    if (!(s[k] < 2.147483647E+9)) {
      j_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
    }
    if (!(s[k] > 0.0)) {
      k_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
    }
    sint[k] = static_cast<int>(s[k]);
  }
}

//
// Arguments    : void
// Return Type  : sparse
//
sparse::sparse() = default;

//
// Arguments    : void
// Return Type  : void
//
sparse::~sparse() = default;

} // namespace coder

//
// File trailer for sparse1.cpp
//
// [EOF]
//
