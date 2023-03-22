//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sparse.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "sparse.h"
#include "anonymous_function.h"
#include "eml_int_forloop_overflow_check.h"
#include "introsort.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "thresholdGeneratorPre_internal_types.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include "omp.h"
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Vectors must be the same length.";
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
// Arguments    : const ::coder::array<double, 1U> &varargin_1
//                const ::coder::array<double, 1U> &varargin_2
//                const ::coder::array<double, 1U> &varargin_3
//                sparse *y
// Return Type  : void
//
namespace coder {
void b_sparse(const ::coder::array<double, 1U> &varargin_1,
              const ::coder::array<double, 1U> &varargin_2,
              const ::coder::array<double, 1U> &varargin_3, sparse *y)
{
  static rtDoubleCheckInfo b_emlrtDCI{
      193,             // lineNo
      48,              // colNo
      "sparse/sparse", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
      "sparse\\sparse.m", // pName
      4                   // checkKind
  };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      116,            // lineNo
      "sparse/sparse" // fName
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      111,            // lineNo
      "sparse/sparse" // fName
  };
  anonymous_function b_this;
  array<int, 1U> sortedIndices;
  array<int, 1U> t;
  int i;
  int k;
  int nc;
  int numalloc;
  int ny;
  nc = varargin_2.size(0);
  if ((varargin_1.size(0) != varargin_2.size(0)) ||
      (varargin_3.size(0) != varargin_2.size(0))) {
    h_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  if ((varargin_3.size(0) != varargin_2.size(0)) &&
      (varargin_3.size(0) != varargin_1.size(0))) {
    h_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  sparse::assertValidIndexArg(varargin_1, b_this.workspace.b);
  sparse::assertValidIndexArg(varargin_2, b_this.workspace.a);
  sortedIndices.set_size(varargin_2.size(0));
  if (varargin_2.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nc; k++) {
    sortedIndices[k] = k + 1;
  }
  internal::introsort(sortedIndices, b_this.workspace.a.size(0), &b_this);
  ny = b_this.workspace.a.size(0);
  t.set_size(b_this.workspace.a.size(0));
  numalloc = b_this.workspace.a.size(0);
  for (i = 0; i < numalloc; i++) {
    t[i] = b_this.workspace.a[i];
  }
  if (b_this.workspace.a.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < ny; k++) {
    b_this.workspace.a[k] = t[sortedIndices[k] - 1];
  }
  ny = b_this.workspace.b.size(0);
  t.set_size(b_this.workspace.b.size(0));
  numalloc = b_this.workspace.b.size(0);
  for (i = 0; i < numalloc; i++) {
    t[i] = b_this.workspace.b[i];
  }
  if (b_this.workspace.b.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < ny; k++) {
    b_this.workspace.b[k] = t[sortedIndices[k] - 1];
  }
  if ((b_this.workspace.b.size(0) == 0) || (b_this.workspace.a.size(0) == 0)) {
    ny = 0;
    y->n = 0;
  } else {
    numalloc = b_this.workspace.b.size(0);
    ny = b_this.workspace.b[0];
    if (b_this.workspace.b.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 2; k <= numalloc; k++) {
      i = b_this.workspace.b[k - 1];
      if (ny < i) {
        ny = i;
      }
    }
    y->n = b_this.workspace.a[b_this.workspace.a.size(0) - 1];
  }
  y->m = ny;
  numalloc = varargin_2.size(0);
  if (numalloc < 1) {
    numalloc = 1;
  }
  y->d.set_size(numalloc);
  for (i = 0; i < numalloc; i++) {
    y->d[i] = 0.0;
  }
  y->maxnz = numalloc;
  if (y->n + 1 < 0) {
    rtNonNegativeError(static_cast<double>(y->n + 1), &b_emlrtDCI);
  }
  y->colidx.set_size(y->n + 1);
  y->colidx[0] = 1;
  y->rowidx.set_size(numalloc);
  for (i = 0; i < numalloc; i++) {
    y->rowidx[i] = 0;
  }
  numalloc = 0;
  ny = y->n;
  if (y->n > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int c{0}; c < ny; c++) {
    while ((numalloc + 1 <= nc) && (b_this.workspace.a[numalloc] == c + 1)) {
      y->rowidx[numalloc] = b_this.workspace.b[numalloc];
      numalloc++;
    }
    y->colidx[c + 1] = numalloc + 1;
  }
  for (k = 0; k < nc; k++) {
    y->d[k] = 1.0;
  }
  numalloc = 1;
  i = y->colidx.size(0);
  for (int c{0}; c <= i - 2; c++) {
    ny = y->colidx[c];
    y->colidx[c] = numalloc;
    int exitg1;
    do {
      exitg1 = 0;
      k = y->colidx[c + 1];
      if (ny < k) {
        double val;
        val = 0.0;
        nc = y->rowidx[ny - 1];
        while ((ny < k) && (y->rowidx[ny - 1] == nc)) {
          val += y->d[ny - 1];
          ny++;
        }
        if (val != 0.0) {
          y->d[numalloc - 1] = val;
          y->rowidx[numalloc - 1] = nc;
          numalloc++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  y->colidx[y->colidx.size(0) - 1] = numalloc;
}

} // namespace coder

//
// File trailer for sparse.cpp
//
// [EOF]
//
