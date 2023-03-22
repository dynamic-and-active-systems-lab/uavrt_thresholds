//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:59
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "sparse.h"
#include "thresholdGeneratorSingleTrial.h"
#include "thresholdGeneratorSingleTrial_internal_types.h"
#include "thresholdGeneratorSingleTrial_terminate.h"
#include "coder_array.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static coder::array<int, 1U> argInit_Unboundedx1_int32_T();

static coder::array<double, 1U> argInit_Unboundedx1_real_T();

static coder::array<creal_T, 2U> argInit_UnboundedxUnbounded_creal_T();

static coder::array<creal_T, 3U>
argInit_UnboundedxUnboundedxUnbounded_creal_T();

static creal_T argInit_creal_T();

static int argInit_int32_T();

static double argInit_real_T();

static void argInit_sparse(coder::sparse *result);

static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void main_thresholdGeneratorSingleTrial();

// Function Definitions
//
// Arguments    : void
// Return Type  : coder::array<int, 1U>
//
static coder::array<int, 1U> argInit_Unboundedx1_int32_T()
{
  coder::array<int, 1U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_int32_T();
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 1U>
//
static coder::array<double, 1U> argInit_Unboundedx1_real_T()
{
  coder::array<double, 1U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<creal_T, 2U>
//
static coder::array<creal_T, 2U> argInit_UnboundedxUnbounded_creal_T()
{
  coder::array<creal_T, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + result.size(0) * idx1] = argInit_creal_T();
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : coder::array<creal_T, 3U>
//
static coder::array<creal_T, 3U> argInit_UnboundedxUnboundedxUnbounded_creal_T()
{
  coder::array<creal_T, 3U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      for (int idx2{0}; idx2 < result.size(2); idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[(idx0 + result.size(0) * idx1) +
               result.size(0) * result.size(1) * idx2] = argInit_creal_T();
      }
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : creal_T
//
static creal_T argInit_creal_T()
{
  creal_T result;
  double re_tmp;
  // Set the value of the complex variable.
  // Change this value to the value that the application requires.
  re_tmp = argInit_real_T();
  result.re = re_tmp;
  result.im = re_tmp;
  return result;
}

//
// Arguments    : void
// Return Type  : int
//
static int argInit_int32_T()
{
  return 0;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : coder::sparse *result
// Return Type  : void
//
static void argInit_sparse(coder::sparse *result)
{
  coder::array<double, 1U> r;
  coder::array<int, 1U> r1;
  int result_tmp;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_int32_T();
  r = argInit_Unboundedx1_real_T();
  r1 = argInit_Unboundedx1_int32_T();
  result->init(r, r1, r1, result_tmp, result_tmp);
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Example main does not support command line arguments.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : void
// Return Type  : void
//
static void main_thresholdGeneratorSingleTrial()
{
  coder::sparse Wq;
  coder::array<creal_T, 3U> Ssynth;
  coder::array<creal_T, 2U> W;
  double scores;
  // Initialize function 'thresholdGeneratorSingleTrial' input arguments.
  // Initialize function input argument 'W'.
  W = argInit_UnboundedxUnbounded_creal_T();
  // Initialize function input argument 'Ssynth'.
  Ssynth = argInit_UnboundedxUnboundedxUnbounded_creal_T();
  // Initialize function input argument 'Wq'.
  argInit_sparse(&Wq);
  // Call the entry-point 'thresholdGeneratorSingleTrial'.
  scores = thresholdGeneratorSingleTrial(W, Ssynth, &Wq, argInit_real_T());
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int argc, char **)
{
  static rtRunTimeErrorInfo emlrtRTEI{
      1,                              // lineNo
      "thresholdGeneratorSingleTrial" // fName
  };
  if (argc > 1) {
    d_rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_thresholdGeneratorSingleTrial();
  // Terminate the application.
  // You do not need to do this more than one time.
  thresholdGeneratorSingleTrial_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
