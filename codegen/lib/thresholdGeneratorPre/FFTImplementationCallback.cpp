//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: FFTImplementationCallback.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
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
// Arguments    : const ::coder::array<creal_T, 3U> &x
//                int n2blue
//                int nfft
//                const ::coder::array<double, 2U> &costab
//                const ::coder::array<double, 2U> &sintab
//                const ::coder::array<double, 2U> &sintabinv
//                ::coder::array<creal_T, 3U> &y
// Return Type  : void
//
namespace coder {
namespace internal {
void FFTImplementationCallback::dobluesteinfft(
    const ::coder::array<creal_T, 3U> &x, int n2blue, int nfft,
    const ::coder::array<double, 2U> &costab,
    const ::coder::array<double, 2U> &sintab,
    const ::coder::array<double, 2U> &sintabinv, ::coder::array<creal_T, 3U> &y)
{
  array<creal_T, 1U> fv;
  array<creal_T, 1U> fy;
  array<creal_T, 1U> wwc;
  double nt_im;
  double nt_re;
  int a;
  int b;
  int iy;
  int j;
  int k;
  int minNrowsNx;
  int nChan;
  int nInt2;
  int nInt2m1;
  int nRowsD2;
  int nRowsD4;
  int nRowsM2;
  int rt;
  boolean_T b_overflow;
  boolean_T c_overflow;
  boolean_T overflow;
  nInt2m1 = (nfft + nfft) - 1;
  if (nInt2m1 < 0) {
    rtNonNegativeError(static_cast<double>(nInt2m1), &emlrtDCI);
  }
  wwc.set_size(nInt2m1);
  rt = 0;
  wwc[nfft - 1].re = 1.0;
  wwc[nfft - 1].im = 0.0;
  nInt2 = nfft << 1;
  if (nfft - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k <= nfft - 2; k++) {
    iy = ((k + 1) << 1) - 1;
    if (nInt2 - rt <= iy) {
      rt += iy - nInt2;
    } else {
      rt += iy;
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
    j = (nfft - k) - 2;
    wwc[j].re = nt_re;
    wwc[j].im = -nt_im;
  }
  j = nInt2m1 - 1;
  for (k = j; k >= nfft; k--) {
    wwc[k] = wwc[(nInt2m1 - k) - 1];
  }
  nChan = x.size(1) * x.size(2);
  y.set_size(nfft, x.size(1), x.size(2));
  if (nfft > x.size(0)) {
    y.set_size(nfft, x.size(1), x.size(2));
    iy = nfft * x.size(1) * x.size(2);
    for (j = 0; j < iy; j++) {
      y[j].re = 0.0;
      y[j].im = 0.0;
    }
  }
  minNrowsNx = x.size(0);
  if (nfft <= minNrowsNx) {
    minNrowsNx = nfft;
  }
  if (nChan > 2147483646) {
    check_forloop_overflow_error();
  }
  if (nChan - 1 >= 0) {
    overflow = (minNrowsNx > 2147483646);
    a = minNrowsNx + 1;
    b_overflow = ((minNrowsNx + 1 <= nfft) && (nfft > 2147483646));
    nRowsM2 = n2blue - 2;
    nRowsD2 = n2blue / 2;
    nRowsD4 = nRowsD2 / 2;
    b = wwc.size(0);
    c_overflow = ((nfft <= wwc.size(0)) && (wwc.size(0) > 2147483646));
  }
  for (int chan{0}; chan < nChan; chan++) {
    double b_nt_re_tmp;
    double twid_im;
    double twid_re;
    int i;
    int nt_re_tmp;
    int yoff;
    yoff = chan * nfft;
    nInt2m1 = chan * x.size(0);
    if (overflow) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < minNrowsNx; k++) {
      nt_re_tmp = (nfft + k) - 1;
      nt_re = wwc[nt_re_tmp].re;
      nt_im = wwc[nt_re_tmp].im;
      j = nInt2m1 + k;
      iy = yoff + k;
      y[iy].re = nt_re * x[j].re + nt_im * x[j].im;
      y[iy].im = nt_re * x[j].im - nt_im * x[j].re;
    }
    if (b_overflow) {
      check_forloop_overflow_error();
    }
    for (k = a; k <= nfft; k++) {
      j = (yoff + k) - 1;
      y[j].re = 0.0;
      y[j].im = 0.0;
    }
    fy.set_size(n2blue);
    if (n2blue > y.size(0)) {
      fy.set_size(n2blue);
      for (j = 0; j < n2blue; j++) {
        fy[j].re = 0.0;
        fy[j].im = 0.0;
      }
    }
    iy = y.size(0);
    nInt2 = n2blue;
    if (iy <= n2blue) {
      nInt2 = iy;
    }
    iy = 0;
    rt = 0;
    if (nInt2 - 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (i = 0; i <= nInt2 - 2; i++) {
      boolean_T tst;
      fy[iy] = y[yoff + i];
      nInt2m1 = n2blue;
      tst = true;
      while (tst) {
        nInt2m1 >>= 1;
        rt ^= nInt2m1;
        tst = ((rt & nInt2m1) == 0);
      }
      iy = rt;
    }
    fy[iy] = y[(yoff + nInt2) - 1];
    if (n2blue > 1) {
      for (i = 0; i <= nRowsM2; i += 2) {
        b_nt_re_tmp = fy[i + 1].re;
        nt_im = fy[i + 1].im;
        twid_im = fy[i].re;
        nt_re = fy[i].im;
        fy[i + 1].re = twid_im - b_nt_re_tmp;
        fy[i + 1].im = nt_re - nt_im;
        fy[i].re = twid_im + b_nt_re_tmp;
        fy[i].im = nt_re + nt_im;
      }
    }
    nInt2m1 = 2;
    rt = 4;
    k = nRowsD4;
    nInt2 = ((nRowsD4 - 1) << 2) + 1;
    while (k > 0) {
      for (i = 0; i < nInt2; i += rt) {
        nt_re_tmp = i + nInt2m1;
        nt_re = fy[nt_re_tmp].re;
        nt_im = fy[nt_re_tmp].im;
        fy[nt_re_tmp].re = fy[i].re - nt_re;
        fy[nt_re_tmp].im = fy[i].im - nt_im;
        fy[i].re = fy[i].re + nt_re;
        fy[i].im = fy[i].im + nt_im;
      }
      iy = 1;
      for (j = k; j < nRowsD2; j += k) {
        int ihi;
        twid_re = costab[j];
        twid_im = sintab[j];
        i = iy;
        ihi = iy + nInt2;
        while (i < ihi) {
          nt_re_tmp = i + nInt2m1;
          b_nt_re_tmp = fy[nt_re_tmp].im;
          nt_im = fy[nt_re_tmp].re;
          nt_re = twid_re * nt_im - twid_im * b_nt_re_tmp;
          nt_im = twid_re * b_nt_re_tmp + twid_im * nt_im;
          fy[nt_re_tmp].re = fy[i].re - nt_re;
          fy[nt_re_tmp].im = fy[i].im - nt_im;
          fy[i].re = fy[i].re + nt_re;
          fy[i].im = fy[i].im + nt_im;
          i += rt;
        }
        iy++;
      }
      k /= 2;
      nInt2m1 = rt;
      rt += rt;
      nInt2 -= nInt2m1;
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(wwc, n2blue, costab, sintab,
                                                    fv);
    iy = fy.size(0);
    for (j = 0; j < iy; j++) {
      twid_im = fy[j].re;
      nt_im = fv[j].im;
      nt_re = fy[j].im;
      twid_re = fv[j].re;
      fy[j].re = twid_im * twid_re - nt_re * nt_im;
      fy[j].im = twid_im * nt_im + nt_re * twid_re;
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(fy, n2blue, costab,
                                                    sintabinv, fv);
    if (fv.size(0) > 1) {
      nt_im = 1.0 / static_cast<double>(fv.size(0));
      iy = fv.size(0);
      for (j = 0; j < iy; j++) {
        fv[j].re = nt_im * fv[j].re;
        fv[j].im = nt_im * fv[j].im;
      }
    }
    if (c_overflow) {
      check_forloop_overflow_error();
    }
    for (k = nfft; k <= b; k++) {
      nt_im = wwc[k - 1].re;
      nt_re = fv[k - 1].im;
      twid_re = wwc[k - 1].im;
      twid_im = fv[k - 1].re;
      j = (yoff + k) - nfft;
      y[j].re = nt_im * twid_im + twid_re * nt_re;
      y[j].im = nt_im * nt_re - twid_re * twid_im;
    }
  }
}

//
// Arguments    : int nRows
//                boolean_T useRadix2
//                ::coder::array<double, 2U> &costab
//                ::coder::array<double, 2U> &sintab
//                ::coder::array<double, 2U> &sintabinv
// Return Type  : void
//
void FFTImplementationCallback::generate_twiddle_tables(
    int nRows, boolean_T useRadix2, ::coder::array<double, 2U> &costab,
    ::coder::array<double, 2U> &sintab, ::coder::array<double, 2U> &sintabinv)
{
  array<double, 2U> costab1q;
  double e;
  int i;
  int n;
  int nd2;
  e = 6.2831853071795862 / static_cast<double>(nRows);
  n = nRows / 2 / 2;
  costab1q.set_size(1, n + 1);
  costab1q[0] = 1.0;
  nd2 = n / 2 - 1;
  for (int k{0}; k <= nd2; k++) {
    costab1q[k + 1] = std::cos(e * (static_cast<double>(k) + 1.0));
  }
  i = nd2 + 2;
  nd2 = n - 1;
  for (int k{i}; k <= nd2; k++) {
    costab1q[k] = std::sin(e * static_cast<double>(n - k));
  }
  costab1q[n] = 0.0;
  if (!useRadix2) {
    n = costab1q.size(1) - 1;
    nd2 = (costab1q.size(1) - 1) << 1;
    costab.set_size(1, nd2 + 1);
    sintab.set_size(1, nd2 + 1);
    costab[0] = 1.0;
    sintab[0] = 0.0;
    sintabinv.set_size(1, nd2 + 1);
    for (int k{0}; k < n; k++) {
      sintabinv[k + 1] = costab1q[(n - k) - 1];
    }
    i = costab1q.size(1);
    for (int k{i}; k <= nd2; k++) {
      sintabinv[k] = costab1q[k - n];
    }
    for (int k{0}; k < n; k++) {
      costab[k + 1] = costab1q[k + 1];
      sintab[k + 1] = -costab1q[(n - k) - 1];
    }
    i = costab1q.size(1);
    for (int k{i}; k <= nd2; k++) {
      costab[k] = -costab1q[nd2 - k];
      sintab[k] = -costab1q[k - n];
    }
  } else {
    n = costab1q.size(1) - 1;
    nd2 = (costab1q.size(1) - 1) << 1;
    costab.set_size(1, nd2 + 1);
    sintab.set_size(1, nd2 + 1);
    costab[0] = 1.0;
    sintab[0] = 0.0;
    for (int k{0}; k < n; k++) {
      costab[k + 1] = costab1q[k + 1];
      sintab[k + 1] = -costab1q[(n - k) - 1];
    }
    i = costab1q.size(1);
    for (int k{i}; k <= nd2; k++) {
      costab[k] = -costab1q[nd2 - k];
      sintab[k] = -costab1q[k - n];
    }
    sintabinv.set_size(1, 0);
  }
}

//
// Arguments    : int nfft
//                boolean_T useRadix2
//                int *n2blue
//                int *nRows
// Return Type  : void
//
void FFTImplementationCallback::get_algo_sizes(int nfft, boolean_T useRadix2,
                                               int *n2blue, int *nRows)
{
  static rtRunTimeErrorInfo e_emlrtRTEI{
      417,                                       // lineNo
      "FFTImplementationCallback/get_algo_sizes" // fName
  };
  *n2blue = 1;
  if (useRadix2) {
    *nRows = nfft;
  } else {
    int n;
    if (nfft > 0) {
      int pmax;
      n = (nfft + nfft) - 1;
      pmax = 31;
      if (n <= 1) {
        pmax = 0;
      } else {
        int pmin;
        boolean_T exitg1;
        pmin = 0;
        exitg1 = false;
        while ((!exitg1) && (pmax - pmin > 1)) {
          int k;
          int pow2p;
          k = (pmin + pmax) >> 1;
          pow2p = 1 << k;
          if (pow2p == n) {
            pmax = k;
            exitg1 = true;
          } else if (pow2p > n) {
            pmax = k;
          } else {
            pmin = k;
          }
        }
      }
      *n2blue = 1 << pmax;
    }
    n = nfft << 2;
    if (n < 1) {
      n = 1;
    }
    if (*n2blue > n) {
      rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
    }
    *nRows = *n2blue;
  }
}

//
// Arguments    : const ::coder::array<creal_T, 1U> &x
//                int unsigned_nRows
//                const ::coder::array<double, 2U> &costab
//                const ::coder::array<double, 2U> &sintab
//                ::coder::array<creal_T, 1U> &y
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig_impl(
    const ::coder::array<creal_T, 1U> &x, int unsigned_nRows,
    const ::coder::array<double, 2U> &costab,
    const ::coder::array<double, 2U> &sintab, ::coder::array<creal_T, 1U> &y)
{
  double temp_im;
  double temp_re;
  double temp_re_tmp;
  double twid_re;
  int i;
  int iDelta2;
  int iheight;
  int iy;
  int ju;
  int k;
  int nRowsD2;
  y.set_size(unsigned_nRows);
  if (unsigned_nRows > x.size(0)) {
    y.set_size(unsigned_nRows);
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y[iy].re = 0.0;
      y[iy].im = 0.0;
    }
  }
  iDelta2 = x.size(0);
  if (iDelta2 > unsigned_nRows) {
    iDelta2 = unsigned_nRows;
  }
  iheight = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  k = nRowsD2 / 2;
  iy = 0;
  ju = 0;
  if (iDelta2 - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (i = 0; i <= iDelta2 - 2; i++) {
    boolean_T tst;
    y[iy] = x[i];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju;
  }
  y[iy] = x[iDelta2 - 1];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= iheight; i += 2) {
      temp_re_tmp = y[i + 1].re;
      temp_im = y[i + 1].im;
      temp_re = y[i].re;
      twid_re = y[i].im;
      y[i + 1].re = temp_re - temp_re_tmp;
      y[i + 1].im = twid_re - temp_im;
      y[i].re = temp_re + temp_re_tmp;
      y[i].im = twid_re + temp_im;
    }
  }
  iy = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    int b_temp_re_tmp;
    for (i = 0; i < iheight; i += iDelta2) {
      b_temp_re_tmp = i + iy;
      temp_re = y[b_temp_re_tmp].re;
      temp_im = y[b_temp_re_tmp].im;
      y[b_temp_re_tmp].re = y[i].re - temp_re;
      y[b_temp_re_tmp].im = y[i].im - temp_im;
      y[i].re = y[i].re + temp_re;
      y[i].im = y[i].im + temp_im;
    }
    ju = 1;
    for (int j{k}; j < nRowsD2; j += k) {
      double twid_im;
      int ihi;
      twid_re = costab[j];
      twid_im = sintab[j];
      i = ju;
      ihi = ju + iheight;
      while (i < ihi) {
        b_temp_re_tmp = i + iy;
        temp_re_tmp = y[b_temp_re_tmp].im;
        temp_im = y[b_temp_re_tmp].re;
        temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
        temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
        y[b_temp_re_tmp].re = y[i].re - temp_re;
        y[b_temp_re_tmp].im = y[i].im - temp_im;
        y[i].re = y[i].re + temp_re;
        y[i].im = y[i].im + temp_im;
        i += iDelta2;
      }
      ju++;
    }
    k /= 2;
    iy = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iy;
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for FFTImplementationCallback.cpp
//
// [EOF]
//
