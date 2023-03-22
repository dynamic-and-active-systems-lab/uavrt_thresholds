//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: FFTImplementationCallback.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_data.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include "omp.h"
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
  array<creal_T, 1U> r;
  array<creal_T, 1U> wwc;
  double a_im;
  double a_re;
  double b_re_tmp;
  double re_tmp;
  int b_k;
  int b_y;
  int i;
  int i1;
  int minNrowsNx;
  int nChan;
  int nInt2;
  int nInt2m1;
  int rt;
  int u0;
  int xoff;
  nChan = x.size(1) * x.size(2);
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
  for (int k{0}; k <= nfft - 2; k++) {
    double nt_im;
    double nt_re;
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
    i = (nfft - k) - 2;
    wwc[i].re = nt_re;
    wwc[i].im = -nt_im;
  }
  i = nInt2m1 - 1;
  for (int k{i}; k >= nfft; k--) {
    wwc[k] = wwc[(nInt2m1 - k) - 1];
  }
  nInt2m1 = x.size(0);
  y.set_size(nfft, x.size(1), x.size(2));
  if (nfft > x.size(0)) {
    y.set_size(nfft, x.size(1), x.size(2));
    b_y = nfft * x.size(1) * x.size(2);
    for (i = 0; i < b_y; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }
  if (nChan > 2147483646) {
    check_forloop_overflow_error();
  }
  b_y = nChan - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    fv, fy, r, xoff, i1, minNrowsNx, b_k, u0, a_re, a_im, re_tmp, b_re_tmp)

  for (int chan = 0; chan <= b_y; chan++) {
    xoff = chan * nInt2m1;
    r.set_size(nfft);
    if (nfft > x.size(0)) {
      r.set_size(nfft);
      for (i1 = 0; i1 < nfft; i1++) {
        r[i1].re = 0.0;
        r[i1].im = 0.0;
      }
    }
    minNrowsNx = x.size(0);
    if (nfft <= minNrowsNx) {
      minNrowsNx = nfft;
    }
    if (minNrowsNx > 2147483646) {
      check_forloop_overflow_error();
    }
    for (b_k = 0; b_k < minNrowsNx; b_k++) {
      u0 = (nfft + b_k) - 1;
      a_re = wwc[u0].re;
      a_im = wwc[u0].im;
      i1 = xoff + b_k;
      r[b_k].re = a_re * x[i1].re + a_im * x[i1].im;
      r[b_k].im = a_re * x[i1].im - a_im * x[i1].re;
    }
    u0 = minNrowsNx + 1;
    if ((minNrowsNx + 1 <= nfft) && (nfft > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (b_k = u0; b_k <= nfft; b_k++) {
      r[b_k - 1].re = 0.0;
      r[b_k - 1].im = 0.0;
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(r, n2blue, costab, sintab,
                                                    fy);
    FFTImplementationCallback::r2br_r2dit_trig_impl(wwc, n2blue, costab, sintab,
                                                    fv);
    u0 = fy.size(0);
    for (i1 = 0; i1 < u0; i1++) {
      a_re = fy[i1].re;
      a_im = fv[i1].im;
      re_tmp = fy[i1].im;
      b_re_tmp = fv[i1].re;
      fy[i1].re = a_re * b_re_tmp - re_tmp * a_im;
      fy[i1].im = a_re * a_im + re_tmp * b_re_tmp;
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(fy, n2blue, costab,
                                                    sintabinv, fv);
    if (fv.size(0) > 1) {
      a_re = 1.0 / static_cast<double>(fv.size(0));
      u0 = fv.size(0);
      for (i1 = 0; i1 < u0; i1++) {
        fv[i1].re = a_re * fv[i1].re;
        fv[i1].im = a_re * fv[i1].im;
      }
    }
    u0 = wwc.size(0);
    if ((nfft <= wwc.size(0)) && (wwc.size(0) > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (b_k = nfft; b_k <= u0; b_k++) {
      a_re = wwc[b_k - 1].re;
      a_im = fv[b_k - 1].im;
      re_tmp = wwc[b_k - 1].im;
      b_re_tmp = fv[b_k - 1].re;
      i1 = b_k - nfft;
      r[i1].re = a_re * b_re_tmp + re_tmp * a_im;
      r[i1].im = a_re * a_im - re_tmp * b_re_tmp;
    }
    xoff = y.size(0);
    u0 = r.size(0);
    for (i1 = 0; i1 < u0; i1++) {
      y[i1 + xoff * chan] = r[i1];
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
// Arguments    : const ::coder::array<creal_T, 3U> &x
//                int n1_unsigned
//                const ::coder::array<double, 2U> &costab
//                const ::coder::array<double, 2U> &sintab
//                ::coder::array<creal_T, 3U> &y
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig(
    const ::coder::array<creal_T, 3U> &x, int n1_unsigned,
    const ::coder::array<double, 2U> &costab,
    const ::coder::array<double, 2U> &sintab, ::coder::array<creal_T, 3U> &y)
{
  array<creal_T, 1U> r;
  double temp_im;
  double temp_re;
  double temp_re_tmp;
  double twid_im;
  double twid_re;
  int b_i;
  int b_temp_re_tmp;
  int iDelta2;
  int iheight;
  int iy;
  int j;
  int ju;
  int k;
  int nChan;
  int nRowsD2;
  int nrows;
  int xoff;
  boolean_T tst;
  nChan = x.size(1) * x.size(2);
  nrows = x.size(0);
  y.set_size(n1_unsigned, x.size(1), x.size(2));
  if (n1_unsigned > x.size(0)) {
    int loop_ub;
    y.set_size(n1_unsigned, x.size(1), x.size(2));
    loop_ub = n1_unsigned * x.size(1) * x.size(2);
    for (int i{0}; i < loop_ub; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }
  if (nChan > 2147483646) {
    check_forloop_overflow_error();
  }
  nChan--;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    r, xoff, iheight, iy, j, nRowsD2, k, ju, b_i, iDelta2, tst, temp_re_tmp,   \
    temp_im, temp_re, twid_re, b_temp_re_tmp, twid_im)

  for (int chan = 0; chan <= nChan; chan++) {
    xoff = chan * nrows;
    r.set_size(n1_unsigned);
    if (n1_unsigned > x.size(0)) {
      r.set_size(n1_unsigned);
      for (iheight = 0; iheight < n1_unsigned; iheight++) {
        r[iheight].re = 0.0;
        r[iheight].im = 0.0;
      }
    }
    iy = x.size(0);
    j = n1_unsigned;
    if (iy <= n1_unsigned) {
      j = iy;
    }
    iheight = n1_unsigned - 2;
    nRowsD2 = n1_unsigned / 2;
    k = nRowsD2 / 2;
    iy = 0;
    ju = 0;
    if (j - 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (b_i = 0; b_i <= j - 2; b_i++) {
      r[iy] = x[xoff + b_i];
      iDelta2 = n1_unsigned;
      tst = true;
      while (tst) {
        iDelta2 >>= 1;
        ju ^= iDelta2;
        tst = ((ju & iDelta2) == 0);
      }
      iy = ju;
    }
    r[iy] = x[(xoff + j) - 1];
    if (n1_unsigned > 1) {
      for (b_i = 0; b_i <= iheight; b_i += 2) {
        temp_re_tmp = r[b_i + 1].re;
        temp_im = r[b_i + 1].im;
        temp_re = r[b_i].re;
        twid_re = r[b_i].im;
        r[b_i + 1].re = temp_re - temp_re_tmp;
        r[b_i + 1].im = twid_re - temp_im;
        r[b_i].re = temp_re + temp_re_tmp;
        r[b_i].im = twid_re + temp_im;
      }
    }
    iy = 2;
    iDelta2 = 4;
    iheight = ((k - 1) << 2) + 1;
    while (k > 0) {
      for (b_i = 0; b_i < iheight; b_i += iDelta2) {
        b_temp_re_tmp = b_i + iy;
        temp_re = r[b_temp_re_tmp].re;
        temp_im = r[b_temp_re_tmp].im;
        r[b_temp_re_tmp].re = r[b_i].re - temp_re;
        r[b_temp_re_tmp].im = r[b_i].im - temp_im;
        r[b_i].re = r[b_i].re + temp_re;
        r[b_i].im = r[b_i].im + temp_im;
      }
      ju = 1;
      for (j = k; j < nRowsD2; j += k) {
        twid_re = costab[j];
        twid_im = sintab[j];
        b_i = ju;
        xoff = ju + iheight;
        while (b_i < xoff) {
          b_temp_re_tmp = b_i + iy;
          temp_re_tmp = r[b_temp_re_tmp].im;
          temp_im = r[b_temp_re_tmp].re;
          temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
          temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
          r[b_temp_re_tmp].re = r[b_i].re - temp_re;
          r[b_temp_re_tmp].im = r[b_i].im - temp_im;
          r[b_i].re = r[b_i].re + temp_re;
          r[b_i].im = r[b_i].im + temp_im;
          b_i += iDelta2;
        }
        ju++;
      }
      k /= 2;
      iy = iDelta2;
      iDelta2 += iDelta2;
      iheight -= iy;
    }
    iy = y.size(0);
    iDelta2 = r.size(0);
    for (iheight = 0; iheight < iDelta2; iheight++) {
      y[iheight + iy * chan] = r[iheight];
    }
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
