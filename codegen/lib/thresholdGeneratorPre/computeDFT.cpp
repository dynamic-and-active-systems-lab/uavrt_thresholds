//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeDFT.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 23-Mar-2023 08:53:28
//

// Include Files
#include "computeDFT.h"
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "thresholdGeneratorPre_data.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "coder_array.h"
#include <cfloat>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>

// Function Declarations
static int div_s32(int numerator, int denominator);

static void rtDivisionByZeroErrorN();

static double rt_remd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    rtDivisionByZeroErrorN();
  } else {
    unsigned int b_denominator;
    unsigned int b_numerator;
    if (numerator < 0) {
      b_numerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      b_numerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      b_denominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      b_denominator = static_cast<unsigned int>(denominator);
    }
    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int>(b_numerator);
    } else {
      quotient = static_cast<int>(b_numerator);
    }
  }
  return quotient;
}

//
// Arguments    : void
// Return Type  : void
//
static void rtDivisionByZeroErrorN()
{
  std::stringstream outStream;
  outStream << "Division by zero detected.\nEarly termination due to division "
               "by zero.";
  outStream << "\n";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_remd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
    y = rtNaN;
  } else if (std::isinf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
    double q;
    q = std::abs(u0 / u1);
    if (!(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }
  return y;
}

//
// Arguments    : const ::coder::array<creal_T, 3U> &xin
//                double nfft
//                double varargin_1
//                ::coder::array<creal_T, 3U> &Xx
//                ::coder::array<double, 1U> &f
// Return Type  : void
//
namespace coder {
void computeDFT(const ::coder::array<creal_T, 3U> &xin, double nfft,
                double varargin_1, ::coder::array<creal_T, 3U> &Xx,
                ::coder::array<double, 1U> &f)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      35,                                                            // lineNo
      7,                                                             // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      35,                                                            // lineNo
      14,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      39,                                                            // lineNo
      7,                                                             // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      45,                                                            // lineNo
      11,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      84,                 // lineNo
      38,                 // colNo
      "",                 // aName
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      45,                                                            // lineNo
      18,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,                                                            // iFirst
      -1,                                                            // iLast
      45,                                                            // lineNo
      25,                                                            // colNo
      "",                                                            // aName
      "datawrap",                                                    // fName
      "C:\\Program Files\\MATLAB\\toolbox\\signal\\eml\\datawrap.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      85,                 // lineNo
      14,                 // colNo
      "",                 // aName
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      74,              // lineNo
      8,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      75,              // lineNo
      8,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      80,              // lineNo
      4,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      78,              // lineNo
      8,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      74,              // lineNo
      8,               // colNo
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      81,                 // lineNo
      12,                 // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      81,                 // lineNo
      1,                  // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      78,              // lineNo
      8,               // colNo
      "frequencygrid", // fName
      "C:\\Program Files\\MATLAB\\toolbox\\shared\\siglib\\psdfreqvec.m", // pName
      1 // checkKind
  };
  static rtEqualityCheckInfo emlrtECI{
      -1,                 // nDims
      85,                 // lineNo
      9,                  // colNo
      "computeDFTviaFFT", // fName
      "C:\\Program "
      "Files\\MATLAB\\toolbox\\signal\\signal\\private\\computeDFT.m" // pName
  };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      12,        // lineNo
      "datawrap" // fName
  };
  array<creal_T, 3U> xw;
  array<creal_T, 2U> wrappedData;
  array<creal_T, 1U> x;
  array<double, 2U> sintab;
  array<double, 2U> sintabinv;
  array<double, 2U> w1;
  double Nyq;
  double temp_im;
  double temp_re;
  double twid_im;
  double twid_re;
  int b_remainder;
  int istart;
  int ju;
  int k;
  int loop_ub_tmp;
  int nFullPasses;
  int offset;
  int temp_re_tmp;
  temp_re_tmp = static_cast<int>(std::floor(nfft));
  if (nfft != temp_re_tmp) {
    rtIntegerError(nfft, &c_emlrtDCI);
  }
  loop_ub_tmp = static_cast<int>(nfft);
  xw.set_size(loop_ub_tmp, xin.size(1), xin.size(2));
  if (loop_ub_tmp != temp_re_tmp) {
    rtIntegerError(nfft, &d_emlrtDCI);
  }
  offset = loop_ub_tmp * xin.size(1) * xin.size(2);
  for (temp_re_tmp = 0; temp_re_tmp < offset; temp_re_tmp++) {
    xw[temp_re_tmp].re = 0.0;
    xw[temp_re_tmp].im = 0.0;
  }
  if (xin.size(0) > loop_ub_tmp) {
    temp_re_tmp = static_cast<int>(static_cast<double>(xin.size(1)) *
                                   static_cast<double>(xin.size(2)));
    for (int j{0}; j < temp_re_tmp; j++) {
      offset = xin.size(0);
      b_remainder = xin.size(0);
      istart = xin.size(1) * xin.size(2);
      if ((static_cast<int>(j + 1U) < 1) ||
          (static_cast<int>(j + 1U) > istart)) {
        rtDynamicBoundsError(static_cast<int>(j + 1U), 1, istart, &emlrtBCI);
      }
      x.set_size(xin.size(0));
      for (istart = 0; istart < offset; istart++) {
        x[istart] = xin[istart + b_remainder * j];
      }
      if (!(nfft >= 1.0)) {
        rtErrorWithMessageID(1, e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
      }
      if (xin.size(0) == 1) {
        wrappedData.set_size(1, loop_ub_tmp);
        for (istart = 0; istart < loop_ub_tmp; istart++) {
          wrappedData[istart].re = 0.0;
          wrappedData[istart].im = 0.0;
        }
      } else {
        wrappedData.set_size(loop_ub_tmp, 1);
        for (istart = 0; istart < loop_ub_tmp; istart++) {
          wrappedData[istart].re = 0.0;
          wrappedData[istart].im = 0.0;
        }
      }
      nFullPasses = div_s32(xin.size(0), loop_ub_tmp);
      offset = nFullPasses * loop_ub_tmp;
      b_remainder = xin.size(0) - offset;
      if (b_remainder > 2147483646) {
        check_forloop_overflow_error();
      }
      for (k = 0; k < b_remainder; k++) {
        istart = wrappedData.size(0) * wrappedData.size(1);
        if ((k + 1 < 1) || (k + 1 > istart)) {
          rtDynamicBoundsError(k + 1, 1, istart, &b_emlrtBCI);
        }
        istart = (offset + k) + 1;
        if ((istart < 1) || (istart > xin.size(0))) {
          rtDynamicBoundsError(istart, 1, xin.size(0), &c_emlrtBCI);
        }
        wrappedData[k].re = x[istart - 1].re;
        if (istart > xin.size(0)) {
          rtDynamicBoundsError(istart, 1, xin.size(0), &c_emlrtBCI);
        }
        ju = wrappedData.size(0) * wrappedData.size(1);
        if (k + 1 > ju) {
          rtDynamicBoundsError(k + 1, 1, ju, &b_emlrtBCI);
        }
        wrappedData[k].im = x[istart - 1].im;
      }
      ju = b_remainder + 1;
      for (k = ju; k <= loop_ub_tmp; k++) {
        istart = wrappedData.size(0) * wrappedData.size(1);
        if ((k < 1) || (k > istart)) {
          rtDynamicBoundsError(k, 1, istart, &d_emlrtBCI);
        }
        wrappedData[k - 1].re = 0.0;
        istart = wrappedData.size(0) * wrappedData.size(1);
        if (k > istart) {
          rtDynamicBoundsError(k, 1, istart, &d_emlrtBCI);
        }
        wrappedData[k - 1].im = 0.0;
      }
      if (nFullPasses > 2147483646) {
        check_forloop_overflow_error();
      }
      for (b_remainder = 0; b_remainder < nFullPasses; b_remainder++) {
        offset = b_remainder * loop_ub_tmp;
        for (k = 0; k < loop_ub_tmp; k++) {
          istart = wrappedData.size(0) * wrappedData.size(1);
          if (k + 1 > istart) {
            rtDynamicBoundsError(k + 1, 1, istart, &e_emlrtBCI);
          }
          istart = wrappedData.size(0) * wrappedData.size(1);
          if (k + 1 > istart) {
            rtDynamicBoundsError(k + 1, 1, istart, &f_emlrtBCI);
          }
          istart = (offset + k) + 1;
          if ((istart < 1) || (istart > xin.size(0))) {
            rtDynamicBoundsError(istart, 1, xin.size(0), &g_emlrtBCI);
          }
          wrappedData[k].re = wrappedData[k].re + x[istart - 1].re;
          ju = wrappedData.size(0) * wrappedData.size(1);
          if (k + 1 > ju) {
            rtDynamicBoundsError(k + 1, 1, ju, &f_emlrtBCI);
          }
          if (istart > xin.size(0)) {
            rtDynamicBoundsError(istart, 1, xin.size(0), &g_emlrtBCI);
          }
          ju = wrappedData.size(0) * wrappedData.size(1);
          if (k + 1 > ju) {
            rtDynamicBoundsError(k + 1, 1, ju, &e_emlrtBCI);
          }
          wrappedData[k].im = wrappedData[k].im + x[istart - 1].im;
        }
      }
      istart = xw.size(1) * xw.size(2);
      if ((j + 1 < 1) || (j + 1 > istart)) {
        rtDynamicBoundsError(j + 1, 1, istart, &h_emlrtBCI);
      }
      ju = wrappedData.size(0) * wrappedData.size(1);
      rtSubAssignSizeCheck(xw.size(), 1, &ju, 1, &emlrtECI);
      ju = wrappedData.size(0) * wrappedData.size(1);
      b_remainder = xw.size(0);
      for (istart = 0; istart < ju; istart++) {
        xw[istart + b_remainder * j] = wrappedData[istart];
      }
    }
  } else {
    xw.set_size(xin.size(0), xin.size(1), xin.size(2));
    offset = xin.size(0) * xin.size(1) * xin.size(2);
    for (temp_re_tmp = 0; temp_re_tmp < offset; temp_re_tmp++) {
      xw[temp_re_tmp] = xin[temp_re_tmp];
    }
  }
  if (xw.size(0) == 1) {
    g_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  if ((xw.size(0) == 0) || (xw.size(1) == 0) || (nfft == 0.0)) {
    Xx.set_size(loop_ub_tmp, xw.size(1), xw.size(2));
    offset = loop_ub_tmp * xw.size(1) * xw.size(2);
    for (temp_re_tmp = 0; temp_re_tmp < offset; temp_re_tmp++) {
      Xx[temp_re_tmp].re = 0.0;
      Xx[temp_re_tmp].im = 0.0;
    }
  } else {
    boolean_T useRadix2;
    useRadix2 = ((nfft > 0.0) && ((loop_ub_tmp & (loop_ub_tmp - 1)) == 0));
    internal::FFTImplementationCallback::get_algo_sizes(
        static_cast<int>(nfft), useRadix2, &ju, &offset);
    internal::FFTImplementationCallback::generate_twiddle_tables(
        offset, useRadix2, w1, sintab, sintabinv);
    if (useRadix2) {
      int nChan;
      int nRowsD2;
      int nRowsD4;
      int u0;
      nChan = xw.size(1) * xw.size(2);
      Xx.set_size(loop_ub_tmp, xw.size(1), xw.size(2));
      if (loop_ub_tmp > xw.size(0)) {
        Xx.set_size(loop_ub_tmp, xw.size(1), xw.size(2));
        offset = static_cast<int>(nfft) * xw.size(1) * xw.size(2);
        for (temp_re_tmp = 0; temp_re_tmp < offset; temp_re_tmp++) {
          Xx[temp_re_tmp].re = 0.0;
          Xx[temp_re_tmp].im = 0.0;
        }
      }
      u0 = xw.size(0);
      if (u0 > loop_ub_tmp) {
        u0 = loop_ub_tmp;
      }
      nRowsD2 = loop_ub_tmp / 2;
      nRowsD4 = nRowsD2 / 2;
      if (nChan > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int chan{0}; chan < nChan; chan++) {
        int i;
        int yoff;
        offset = chan * xw.size(0);
        yoff = chan * loop_ub_tmp;
        b_remainder = yoff;
        ju = 0;
        if (u0 - 1 > 2147483646) {
          check_forloop_overflow_error();
        }
        for (i = 0; i <= u0 - 2; i++) {
          Xx[b_remainder] = xw[offset + i];
          b_remainder = loop_ub_tmp;
          useRadix2 = true;
          while (useRadix2) {
            b_remainder >>= 1;
            ju ^= b_remainder;
            useRadix2 = ((ju & b_remainder) == 0);
          }
          b_remainder = yoff + ju;
        }
        offset = (offset + u0) - 1;
        Xx[b_remainder] = xw[offset];
        ju = (yoff + loop_ub_tmp) - 2;
        if (nfft > 1.0) {
          if ((yoff <= ju) && (ju > 2147483645)) {
            check_forloop_overflow_error();
          }
          for (i = yoff; i <= ju; i += 2) {
            temp_re = Xx[i + 1].re;
            temp_im = Xx[i + 1].im;
            Xx[i + 1].re = Xx[i].re - Xx[i + 1].re;
            Xx[i + 1].im = Xx[i].im - Xx[i + 1].im;
            Xx[i].re = Xx[i].re + temp_re;
            Xx[i].im = Xx[i].im + temp_im;
          }
        }
        b_remainder = 2;
        offset = 4;
        k = nRowsD4;
        nFullPasses = ((nRowsD4 - 1) << 2) + 1;
        while (k > 0) {
          i = yoff;
          ju = yoff + nFullPasses;
          while (i < ju) {
            temp_re_tmp = i + b_remainder;
            temp_re = Xx[temp_re_tmp].re;
            temp_im = Xx[temp_re_tmp].im;
            Xx[temp_re_tmp].re = Xx[i].re - temp_re;
            Xx[temp_re_tmp].im = Xx[i].im - temp_im;
            Xx[i].re = Xx[i].re + temp_re;
            Xx[i].im = Xx[i].im + temp_im;
            i += offset;
          }
          istart = yoff + 1;
          for (int j{k}; j < nRowsD2; j += k) {
            twid_re = w1[j];
            twid_im = sintab[j];
            i = istart;
            ju = istart + nFullPasses;
            while (i < ju) {
              temp_re_tmp = i + b_remainder;
              temp_re =
                  twid_re * Xx[temp_re_tmp].re - twid_im * Xx[temp_re_tmp].im;
              temp_im =
                  twid_re * Xx[temp_re_tmp].im + twid_im * Xx[temp_re_tmp].re;
              Xx[temp_re_tmp].re = Xx[i].re - temp_re;
              Xx[temp_re_tmp].im = Xx[i].im - temp_im;
              Xx[i].re = Xx[i].re + temp_re;
              Xx[i].im = Xx[i].im + temp_im;
              i += offset;
            }
            istart++;
          }
          k /= 2;
          b_remainder = offset;
          offset += offset;
          nFullPasses -= b_remainder;
        }
      }
    } else {
      internal::FFTImplementationCallback::dobluesteinfft(
          xw, ju, static_cast<int>(nfft), w1, sintab, sintabinv, Xx);
    }
  }
  if (std::isnan(varargin_1)) {
    twid_re = 6.2831853071795862;
  } else {
    twid_re = varargin_1;
  }
  twid_im = twid_re / nfft;
  if (nfft - 1.0 < 0.0) {
    w1.set_size(w1.size(0), 0);
  } else {
    w1.set_size(1, static_cast<int>(nfft));
    offset = static_cast<int>(nfft) - 1;
    for (temp_re_tmp = 0; temp_re_tmp <= offset; temp_re_tmp++) {
      w1[temp_re_tmp] = temp_re_tmp;
    }
  }
  w1.set_size(1, w1.size(1));
  offset = w1.size(1) - 1;
  for (temp_re_tmp = 0; temp_re_tmp <= offset; temp_re_tmp++) {
    w1[temp_re_tmp] = twid_im * w1[temp_re_tmp];
  }
  Nyq = twid_re / 2.0;
  temp_re = twid_im / 2.0;
  if (rt_remd_snf(nfft, 2.0) != 0.0) {
    temp_im = (nfft + 1.0) / 2.0;
    if (temp_im != std::floor(temp_im)) {
      rtIntegerError(temp_im, &b_emlrtDCI);
    }
    if ((static_cast<int>(temp_im) < 1) ||
        (static_cast<int>(temp_im) > w1.size(1))) {
      rtDynamicBoundsError(static_cast<int>(temp_im), 1, w1.size(1),
                           &i_emlrtBCI);
    }
    w1[static_cast<int>(temp_im) - 1] = Nyq - temp_re;
    if ((static_cast<int>(temp_im) + 1 < 1) ||
        (static_cast<int>(temp_im) + 1 > w1.size(1))) {
      rtDynamicBoundsError(static_cast<int>(temp_im) + 1, 1, w1.size(1),
                           &j_emlrtBCI);
    }
    w1[static_cast<int>(temp_im)] = Nyq + temp_re;
  } else {
    temp_re = nfft / 2.0 + 1.0;
    if (temp_re != std::floor(temp_re)) {
      rtIntegerError(temp_re, &e_emlrtDCI);
    }
    if ((static_cast<int>(temp_re) < 1) ||
        (static_cast<int>(temp_re) > w1.size(1))) {
      rtDynamicBoundsError(static_cast<int>(temp_re), 1, w1.size(1),
                           &l_emlrtBCI);
    }
    w1[static_cast<int>(temp_re) - 1] = Nyq;
  }
  if ((nfft < 1.0) || (loop_ub_tmp > w1.size(1))) {
    rtDynamicBoundsError(static_cast<int>(nfft), 1, w1.size(1), &k_emlrtBCI);
  }
  w1[static_cast<int>(nfft) - 1] = twid_re - twid_im;
  f.set_size(w1.size(1));
  offset = w1.size(1);
  for (temp_re_tmp = 0; temp_re_tmp < offset; temp_re_tmp++) {
    f[temp_re_tmp] = w1[temp_re_tmp];
  }
}

} // namespace coder

//
// File trailer for computeDFT.cpp
//
// [EOF]
//
