//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: introsort.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "introsort.h"
#include "anonymous_function.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"
#include "stack1.h"
#include "thresholdGeneratorPre_internal_types.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static void r_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void r_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Cannot push onto a fixed-size stack which is at capacity.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : ::coder::array<int, 1U> &x
//                int xend
//                const anonymous_function *cmp
// Return Type  : void
//
namespace coder {
namespace internal {
void introsort(::coder::array<int, 1U> &x, int xend,
               const anonymous_function *cmp)
{
  static rtDoubleCheckInfo b_emlrtDCI{
      48,            // lineNo
      48,            // colNo
      "stack/stack", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
      "internal\\stack.m", // pName
      4                    // checkKind
  };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      62,          // lineNo
      "stack/push" // fName
  };
  struct_T frame;
  if (xend > 1) {
    if (xend <= 32) {
      insertionsort(x, 1, xend, cmp);
    } else {
      stack st;
      int MAXDEPTH;
      int i;
      int j;
      int pmax;
      int pmin;
      int pow2p;
      int unnamed_idx_0;
      boolean_T exitg1;
      pmax = 31;
      pmin = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax - pmin > 1)) {
        j = (pmin + pmax) >> 1;
        pow2p = 1 << j;
        if (pow2p == xend) {
          pmax = j;
          exitg1 = true;
        } else if (pow2p > xend) {
          pmax = j;
        } else {
          pmin = j;
        }
      }
      MAXDEPTH = (pmax - 1) << 1;
      frame.xstart = 1;
      frame.xend = xend;
      frame.depth = 0;
      unnamed_idx_0 = MAXDEPTH << 1;
      if (unnamed_idx_0 < 0) {
        rtNonNegativeError(static_cast<double>(unnamed_idx_0), &b_emlrtDCI);
      }
      for (i = 0; i < unnamed_idx_0; i++) {
        st.d.data[i] = frame;
      }
      if (unnamed_idx_0 <= 0) {
        r_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
      }
      st.d.data[0] = frame;
      st.n = 1;
      while (st.n > 0) {
        int frame_tmp_tmp;
        frame_tmp_tmp = st.n - 1;
        frame = st.d.data[st.n - 1];
        st.n--;
        i = frame.xend - frame.xstart;
        if (i + 1 <= 32) {
          insertionsort(x, frame.xstart, frame.xend, cmp);
        } else if (frame.depth == MAXDEPTH) {
          b_heapsort(x, frame.xstart, frame.xend, cmp);
        } else {
          int pivot;
          boolean_T varargout_1;
          pow2p = (frame.xstart + i / 2) - 1;
          i = x[frame.xstart - 1];
          pmax = cmp->workspace.a[x[pow2p] - 1];
          pmin = cmp->workspace.a[i - 1];
          if (pmax < pmin) {
            varargout_1 = true;
          } else if (pmax == pmin) {
            varargout_1 =
                (cmp->workspace.b[x[pow2p] - 1] < cmp->workspace.b[i - 1]);
          } else {
            varargout_1 = false;
          }
          if (varargout_1) {
            x[frame.xstart - 1] = x[pow2p];
            x[pow2p] = i;
          }
          if (cmp->workspace.a[x[frame.xend - 1] - 1] <
              cmp->workspace.a[x[frame.xstart - 1] - 1]) {
            varargout_1 = true;
          } else {
            i = x[frame.xend - 1] - 1;
            pmax = x[frame.xstart - 1] - 1;
            if (cmp->workspace.a[i] == cmp->workspace.a[pmax]) {
              varargout_1 = (cmp->workspace.b[i] < cmp->workspace.b[pmax]);
            } else {
              varargout_1 = false;
            }
          }
          if (varargout_1) {
            pmax = x[frame.xstart - 1];
            x[frame.xstart - 1] = x[frame.xend - 1];
            x[frame.xend - 1] = pmax;
          }
          if (cmp->workspace.a[x[frame.xend - 1] - 1] <
              cmp->workspace.a[x[pow2p] - 1]) {
            varargout_1 = true;
          } else {
            i = x[frame.xend - 1] - 1;
            if (cmp->workspace.a[i] == cmp->workspace.a[x[pow2p] - 1]) {
              varargout_1 =
                  (cmp->workspace.b[i] < cmp->workspace.b[x[pow2p] - 1]);
            } else {
              varargout_1 = false;
            }
          }
          if (varargout_1) {
            pmax = x[pow2p];
            x[pow2p] = x[frame.xend - 1];
            x[frame.xend - 1] = pmax;
          }
          pivot = x[pow2p] - 1;
          x[pow2p] = x[frame.xend - 2];
          x[frame.xend - 2] = pivot + 1;
          pmin = frame.xstart - 1;
          j = frame.xend - 2;
          int exitg2;
          do {
            int exitg3;
            exitg2 = 0;
            pmin++;
            do {
              exitg3 = 0;
              i = cmp->workspace.a[x[pmin] - 1];
              if (i < cmp->workspace.a[pivot]) {
                varargout_1 = true;
              } else if (i == cmp->workspace.a[pivot]) {
                varargout_1 =
                    (cmp->workspace.b[x[pmin] - 1] < cmp->workspace.b[pivot]);
              } else {
                varargout_1 = false;
              }
              if (varargout_1) {
                pmin++;
              } else {
                exitg3 = 1;
              }
            } while (exitg3 == 0);
            j--;
            do {
              exitg3 = 0;
              i = cmp->workspace.a[x[j] - 1];
              if (cmp->workspace.a[pivot] < i) {
                varargout_1 = true;
              } else if (cmp->workspace.a[pivot] == i) {
                varargout_1 =
                    (cmp->workspace.b[pivot] < cmp->workspace.b[x[j] - 1]);
              } else {
                varargout_1 = false;
              }
              if (varargout_1) {
                j--;
              } else {
                exitg3 = 1;
              }
            } while (exitg3 == 0);
            if (pmin + 1 >= j + 1) {
              exitg2 = 1;
            } else {
              pmax = x[pmin];
              x[pmin] = x[j];
              x[j] = pmax;
            }
          } while (exitg2 == 0);
          x[frame.xend - 2] = x[pmin];
          x[pmin] = pivot + 1;
          if (pmin + 2 < frame.xend) {
            if (frame_tmp_tmp >= unnamed_idx_0) {
              r_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
            }
            st.d.data[frame_tmp_tmp].xstart = pmin + 2;
            st.d.data[frame_tmp_tmp].xend = frame.xend;
            st.d.data[frame_tmp_tmp].depth = frame.depth + 1;
            st.n = frame_tmp_tmp + 1;
          }
          if (frame.xstart < pmin + 1) {
            if (st.n >= unnamed_idx_0) {
              r_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
            }
            st.d.data[st.n].xstart = frame.xstart;
            st.d.data[st.n].xend = pmin + 1;
            st.d.data[st.n].depth = frame.depth + 1;
            st.n++;
          }
        }
      }
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for introsort.cpp
//
// [EOF]
//
