//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fft.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_data.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<creal_T, 1U> &x
//                ::coder::array<creal_T, 1U> &y
// Return Type  : void
//
namespace coder {
void fft(const ::coder::array<creal_T, 1U> &x, ::coder::array<creal_T, 1U> &y)
{
  array<creal_T, 1U> fv;
  array<creal_T, 1U> fy;
  array<creal_T, 1U> wwc;
  array<double, 2U> costab;
  array<double, 2U> sintab;
  array<double, 2U> sintabinv;
  int N2blue;
  int nInt2m1;
  int nfft;
  if (x.size(0) == 1) {
    g_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  nfft = x.size(0);
  if (x.size(0) == 0) {
    y.set_size(0);
  } else {
    boolean_T useRadix2;
    useRadix2 = ((x.size(0) & (x.size(0) - 1)) == 0);
    internal::FFTImplementationCallback::get_algo_sizes(x.size(0), useRadix2,
                                                        &N2blue, &nInt2m1);
    internal::FFTImplementationCallback::generate_twiddle_tables(
        nInt2m1, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
          x, x.size(0), costab, sintab, y);
    } else {
      double b_re_tmp;
      double nt_im;
      double nt_re;
      double re_tmp;
      int i;
      int nInt2;
      int rt;
      nInt2m1 = (x.size(0) + x.size(0)) - 1;
      if (nInt2m1 < 0) {
        rtNonNegativeError(static_cast<double>(nInt2m1), &emlrtDCI);
      }
      wwc.set_size(nInt2m1);
      rt = 0;
      wwc[x.size(0) - 1].re = 1.0;
      wwc[x.size(0) - 1].im = 0.0;
      nInt2 = x.size(0) << 1;
      i = x.size(0);
      for (int k{0}; k <= i - 2; k++) {
        int b_y;
        b_y = ((k + 1) << 1) - 1;
        if (nInt2 - rt <= b_y) {
          rt += b_y - nInt2;
        } else {
          rt += b_y;
        }
        nt_im = -3.1415926535897931 * static_cast<double>(rt) /
                static_cast<double>(nfft);
        if (nt_im == 0.0) {
          nt_re = 1.0;
          nt_im = 0.0;
        } else {
          nt_re = std::cos(nt_im);
          nt_im = std::sin(nt_im);
        }
        wwc[(x.size(0) - k) - 2].re = nt_re;
        wwc[(x.size(0) - k) - 2].im = -nt_im;
      }
      i = nInt2m1 - 1;
      for (int k{i}; k >= nfft; k--) {
        wwc[k] = wwc[(nInt2m1 - k) - 1];
      }
      y.set_size(x.size(0));
      nInt2m1 = x.size(0);
      if (x.size(0) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int k{0}; k < nInt2m1; k++) {
        nt_re = wwc[(nfft + k) - 1].re;
        nt_im = wwc[(nfft + k) - 1].im;
        re_tmp = x[k].im;
        b_re_tmp = x[k].re;
        y[k].re = nt_re * b_re_tmp + nt_im * re_tmp;
        y[k].im = nt_re * re_tmp - nt_im * b_re_tmp;
      }
      rt = x.size(0) + 1;
      for (int k{rt}; k <= nfft; k++) {
        y[k - 1].re = 0.0;
        y[k - 1].im = 0.0;
      }
      internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
          y, N2blue, costab, sintab, fy);
      internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
          wwc, N2blue, costab, sintab, fv);
      nInt2m1 = fy.size(0);
      for (i = 0; i < nInt2m1; i++) {
        nt_re = fy[i].re;
        nt_im = fv[i].im;
        re_tmp = fy[i].im;
        b_re_tmp = fv[i].re;
        fy[i].re = nt_re * b_re_tmp - re_tmp * nt_im;
        fy[i].im = nt_re * nt_im + re_tmp * b_re_tmp;
      }
      internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
          fy, N2blue, costab, sintabinv, fv);
      if (fv.size(0) > 1) {
        nt_re = 1.0 / static_cast<double>(fv.size(0));
        nInt2m1 = fv.size(0);
        for (i = 0; i < nInt2m1; i++) {
          fv[i].re = nt_re * fv[i].re;
          fv[i].im = nt_re * fv[i].im;
        }
      }
      rt = x.size(0);
      nInt2m1 = wwc.size(0);
      if ((x.size(0) <= wwc.size(0)) && (wwc.size(0) > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (int k{rt}; k <= nInt2m1; k++) {
        re_tmp = wwc[k - 1].re;
        b_re_tmp = fv[k - 1].im;
        nt_re = wwc[k - 1].im;
        nt_im = fv[k - 1].re;
        i = k - rt;
        y[i].re = re_tmp * nt_im + nt_re * b_re_tmp;
        y[i].im = re_tmp * b_re_tmp - nt_re * nt_im;
      }
    }
  }
}

} // namespace coder

//
// File trailer for fft.cpp
//
// [EOF]
//
