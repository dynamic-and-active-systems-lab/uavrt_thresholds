//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: indexShapeCheck.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_types.h"
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Code generation assumption about size violated. Run-time indexing is "
         "scalar(vector), but compile-time assumption was vector(vect"
         "or) indexing.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : int matrixSize
//                const int indexSize[2]
// Return Type  : void
//
namespace coder {
namespace internal {
void indexShapeCheck(int matrixSize, const int indexSize[2])
{
  static rtRunTimeErrorInfo e_emlrtRTEI{
      122,          // lineNo
      "errOrWarnIf" // fName
  };
  if ((matrixSize == 1) && (indexSize[1] != 1)) {
    p_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for indexShapeCheck.cpp
//
// [EOF]
//
