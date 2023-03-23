//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_int_forloop_overflow_check.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:54:30
//

// Include Files
#include "eml_int_forloop_overflow_check.h"
#include "thresholdGeneratorSingleTrial_internal_types.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum);

// Function Definitions
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
  ((outStream << "The loop variable of class ") << r)
      << " might overflow on the last iteration of the for loop. This could "
         "lead to an infinite loop.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : void
// Return Type  : void
//
namespace coder {
void check_forloop_overflow_error()
{
  static rtRunTimeErrorInfo emlrtRTEI{
      87,                            // lineNo
      "check_forloop_overflow_error" // fName
  };
  rtErrorWithMessageID("int32", emlrtRTEI.fName, emlrtRTEI.lineNo);
}

} // namespace coder

//
// File trailer for eml_int_forloop_overflow_check.cpp
//
// [EOF]
//
