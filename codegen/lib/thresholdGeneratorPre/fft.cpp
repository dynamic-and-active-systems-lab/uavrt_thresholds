//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fft.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
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
  int j;
  int nInt2m1;
  if (x.size(0) == 1) {
    g_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  j = x.size(0);
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
      double nt_im;
      double nt_re;
      double nt_re_tmp;
      double re_tmp;
      double twid_im;
      double twid_re;
      int i;
      int ihi;
      int ju;
      int k;
      int nInt2;
      int nRowsD2;
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
      ihi = x.size(0);
      for (k = 0; k <= ihi - 2; k++) {
        ju = ((k + 1) << 1) - 1;
        if (nInt2 - rt <= ju) {
          rt += ju - nInt2;
        } else {
          rt += ju;
        }
        nt_im = -3.1415926535897931 * static_cast<double>(rt) /
                static_cast<double>(j);
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
      ihi = nInt2m1 - 1;
      for (k = ihi; k >= j; k--) {
        wwc[k] = wwc[(nInt2m1 - k) - 1];
      }
      y.set_size(x.size(0));
      nInt2m1 = x.size(0);
      if (x.size(0) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (k = 0; k < nInt2m1; k++) {
        nt_re = wwc[(j + k) - 1].re;
        nt_im = wwc[(j + k) - 1].im;
        twid_im = x[k].im;
        re_tmp = x[k].re;
        y[k].re = nt_re * re_tmp + nt_im * twid_im;
        y[k].im = nt_re * twid_im - nt_im * re_tmp;
      }
      rt = x.size(0) + 1;
      for (k = rt; k <= j; k++) {
        y[k - 1].re = 0.0;
        y[k - 1].im = 0.0;
      }
      fy.set_size(N2blue);
      if (N2blue > y.size(0)) {
        fy.set_size(N2blue);
        for (ihi = 0; ihi < N2blue; ihi++) {
          fy[ihi].re = 0.0;
          fy[ihi].im = 0.0;
        }
      }
      rt = y.size(0);
      if (rt > N2blue) {
        rt = N2blue;
      }
      nInt2 = N2blue - 2;
      nRowsD2 = N2blue / 2;
      k = nRowsD2 / 2;
      nInt2m1 = 0;
      ju = 0;
      if (rt - 1 > 2147483646) {
        check_forloop_overflow_error();
      }
      for (i = 0; i <= rt - 2; i++) {
        fy[nInt2m1] = y[i];
        nInt2m1 = N2blue;
        useRadix2 = true;
        while (useRadix2) {
          nInt2m1 >>= 1;
          ju ^= nInt2m1;
          useRadix2 = ((ju & nInt2m1) == 0);
        }
        nInt2m1 = ju;
      }
      fy[nInt2m1] = y[rt - 1];
      if (N2blue > 1) {
        for (i = 0; i <= nInt2; i += 2) {
          nt_re_tmp = fy[i + 1].re;
          nt_im = fy[i + 1].im;
          re_tmp = fy[i].re;
          twid_re = fy[i].im;
          fy[i + 1].re = re_tmp - nt_re_tmp;
          fy[i + 1].im = twid_re - nt_im;
          fy[i].re = re_tmp + nt_re_tmp;
          fy[i].im = twid_re + nt_im;
        }
      }
      nInt2m1 = 2;
      rt = 4;
      nInt2 = ((k - 1) << 2) + 1;
      while (k > 0) {
        int b_nt_re_tmp;
        for (i = 0; i < nInt2; i += rt) {
          b_nt_re_tmp = i + nInt2m1;
          nt_re = fy[b_nt_re_tmp].re;
          nt_im = fy[b_nt_re_tmp].im;
          fy[b_nt_re_tmp].re = fy[i].re - nt_re;
          fy[b_nt_re_tmp].im = fy[i].im - nt_im;
          fy[i].re = fy[i].re + nt_re;
          fy[i].im = fy[i].im + nt_im;
        }
        ju = 1;
        for (j = k; j < nRowsD2; j += k) {
          twid_re = costab[j];
          twid_im = sintab[j];
          i = ju;
          ihi = ju + nInt2;
          while (i < ihi) {
            b_nt_re_tmp = i + nInt2m1;
            nt_re_tmp = fy[b_nt_re_tmp].im;
            nt_im = fy[b_nt_re_tmp].re;
            nt_re = twid_re * nt_im - twid_im * nt_re_tmp;
            nt_im = twid_re * nt_re_tmp + twid_im * nt_im;
            fy[b_nt_re_tmp].re = fy[i].re - nt_re;
            fy[b_nt_re_tmp].im = fy[i].im - nt_im;
            fy[i].re = fy[i].re + nt_re;
            fy[i].im = fy[i].im + nt_im;
            i += rt;
          }
          ju++;
        }
        k /= 2;
        nInt2m1 = rt;
        rt += rt;
        nInt2 -= nInt2m1;
      }
      internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
          wwc, N2blue, costab, sintab, fv);
      nInt2m1 = fy.size(0);
      for (ihi = 0; ihi < nInt2m1; ihi++) {
        re_tmp = fy[ihi].re;
        nt_im = fv[ihi].im;
        twid_re = fy[ihi].im;
        twid_im = fv[ihi].re;
        fy[ihi].re = re_tmp * twid_im - twid_re * nt_im;
        fy[ihi].im = re_tmp * nt_im + twid_re * twid_im;
      }
      internal::FFTImplementationCallback::r2br_r2dit_trig_impl(
          fy, N2blue, costab, sintabinv, fv);
      if (fv.size(0) > 1) {
        nt_im = 1.0 / static_cast<double>(fv.size(0));
        nInt2m1 = fv.size(0);
        for (ihi = 0; ihi < nInt2m1; ihi++) {
          fv[ihi].re = nt_im * fv[ihi].re;
          fv[ihi].im = nt_im * fv[ihi].im;
        }
      }
      rt = x.size(0);
      nInt2m1 = wwc.size(0);
      if ((x.size(0) <= wwc.size(0)) && (wwc.size(0) > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (k = rt; k <= nInt2m1; k++) {
        twid_im = wwc[k - 1].re;
        re_tmp = fv[k - 1].im;
        nt_im = wwc[k - 1].im;
        twid_re = fv[k - 1].re;
        ihi = k - rt;
        y[ihi].re = twid_im * twid_re + nt_im * re_tmp;
        y[ihi].im = twid_im * re_tmp - nt_im * twid_re;
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
