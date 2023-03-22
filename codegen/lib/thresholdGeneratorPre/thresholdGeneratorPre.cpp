//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: thresholdGeneratorPre.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 22-Mar-2023 15:24:14
//

// Include Files
#include "thresholdGeneratorPre.h"
#include "assertValidSizeArg.h"
#include "buildtimecorrelatormatrix.h"
#include "eml_int_forloop_overflow_check.h"
#include "fft.h"
#include "fftshift.h"
#include "nullAssignment.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sparse1.h"
#include "stft.h"
#include "thresholdGeneratorPre_data.h"
#include "thresholdGeneratorPre_initialize.h"
#include "thresholdGeneratorPre_rtwutil.h"
#include "thresholdGeneratorPre_types.h"
#include "weightingmatrix.h"
#include "wgn.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <string>

// Function Declarations
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3);

static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum);

static double rt_hypotd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "To RESHAPE the number of elements must not change.";
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
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(1) == 1) {
    i = in2.size(1);
  } else {
    i = in3.size(1);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(1) != 1);
  stride_1_0 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] + in3[i * stride_1_0];
  }
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream
      << "To RESHAPE the number of elements must not change, and if the input "
         "is empty, the maximum dimension length cannot be increased u"
         "nless the output size is fixed.";
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
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  ((outStream << "Order, ") << r) << ", must be finite.";
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
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * std::sqrt(y * y + 1.0);
  } else if (!std::isnan(y)) {
    y = a * 1.4142135623730951;
  }
  return y;
}

//
// Arguments    : double Fs
//                double t_p
//                double t_ip
//                double t_ipu
//                double t_ipj
//                double K
//                coder::array<creal_T, 2U> &W
//                coder::array<creal_T, 3U> &Ssynth
//                coder::sparse *Wq
//                boolean_T *success
// Return Type  : void
//
void thresholdGeneratorPre(double Fs, double t_p, double t_ip, double t_ipu,
                           double t_ipj, double K, coder::array<creal_T, 2U> &W,
                           coder::array<creal_T, 3U> &Ssynth, coder::sparse *Wq,
                           boolean_T *success)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,                                              // iFirst
      -1,                                              // iLast
      159,                                             // lineNo
      29,                                              // colNo
      "stackedToeplitzMatrices",                       // aName
      "weightingmatrix",                               // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m", // pName
      0                                                // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                                              // iFirst
      -1,                                              // iLast
      159,                                             // lineNo
      38,                                              // colNo
      "stackedToeplitzMatrices",                       // aName
      "weightingmatrix",                               // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m", // pName
      0                                                // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                                              // iFirst
      -1,                                              // iLast
      192,                                             // lineNo
      33,                                              // colNo
      "freqs",                                         // aName
      "weightingmatrix",                               // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m", // pName
      0                                                // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                                              // iFirst
      -1,                                              // iLast
      202,                                             // lineNo
      9,                                               // colNo
      "W",                                             // aName
      "weightingmatrix",                               // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m", // pName
      0                                                // checkKind
  };
  static rtBoundsCheckInfo emlrtBCI{
      -1,                                              // iFirst
      -1,                                              // iLast
      159,                                             // lineNo
      71,                                              // colNo
      "Xs",                                            // aName
      "weightingmatrix",                               // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m", // pName
      0                                                // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      19,                                                     // lineNo
      26,                                                     // colNo
      "thresholdGeneratorPre",                                // fName
      "H:\\repos\\uavrt_thresholds\\thresholdGeneratorPre.m", // pName
      4                                                       // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      19,                                                     // lineNo
      26,                                                     // colNo
      "thresholdGeneratorPre",                                // fName
      "H:\\repos\\uavrt_thresholds\\thresholdGeneratorPre.m", // pName
      1                                                       // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      155,                                             // lineNo
      41,                                              // colNo
      "weightingmatrix",                               // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m", // pName
      1                                                // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      155,                                             // lineNo
      1,                                               // colNo
      "weightingmatrix",                               // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m", // pName
      1                                                // checkKind
  };
  static rtDoubleCheckInfo f_emlrtDCI{
      194,                                             // lineNo
      55,                                              // colNo
      "weightingmatrix",                               // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m", // pName
      4                                                // checkKind
  };
  static rtDoubleCheckInfo g_emlrtDCI{
      194,                                             // lineNo
      48,                                              // colNo
      "weightingmatrix",                               // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m", // pName
      4                                                // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      1,                                              // nDims
      146,                                            // lineNo
      19,                                             // colNo
      "weightingmatrix",                              // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m" // pName
  };
  static rtEqualityCheckInfo c_emlrtECI{
      -1,                                             // nDims
      147,                                            // lineNo
      5,                                              // colNo
      "weightingmatrix",                              // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m" // pName
  };
  static rtEqualityCheckInfo d_emlrtECI{
      -1,                                             // nDims
      159,                                            // lineNo
      5,                                              // colNo
      "weightingmatrix",                              // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m" // pName
  };
  static rtEqualityCheckInfo e_emlrtECI{
      -1,                                             // nDims
      191,                                            // lineNo
      1,                                              // colNo
      "weightingmatrix",                              // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      -1,                                             // nDims
      145,                                            // lineNo
      5,                                              // colNo
      "weightingmatrix",                              // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m" // pName
  };
  static rtEqualityCheckInfo f_emlrtECI{
      1,                                              // nDims
      195,                                            // lineNo
      6,                                              // colNo
      "weightingmatrix",                              // fName
      "H:\\repos\\uavrt_detection\\weightingmatrix.m" // pName
  };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      18,           // lineNo
      "check_order" // fName
  };
  static rtRunTimeErrorInfo f_emlrtRTEI{
      52,                 // lineNo
      "reshapeSizeChecks" // fName
  };
  static rtRunTimeErrorInfo g_emlrtRTEI{
      59,                 // lineNo
      "reshapeSizeChecks" // fName
  };
  static rtRunTimeErrorInfo h_emlrtRTEI{
      81,        // lineNo
      "eml_find" // fName
  };
  static rtRunTimeErrorInfo i_emlrtRTEI{
      392,                 // lineNo
      "find_first_indices" // fName
  };
  coder::array<creal_T, 2U> Xs;
  coder::array<creal_T, 2U> buffer;
  coder::array<creal_T, 2U> r;
  coder::array<creal_T, 2U> s;
  coder::array<creal_T, 2U> stackedToeplitzMatrices;
  coder::array<creal_T, 2U> xsynth;
  coder::array<creal_T, 1U> b_s;
  coder::array<creal_T, 1U> currDFT;
  coder::array<double, 2U> freqs;
  coder::array<double, 2U> wrapper;
  coder::array<double, 1U> a__3;
  coder::array<double, 1U> b_x;
  coder::array<double, 1U> r1;
  coder::array<int, 2U> b_Wq;
  coder::array<int, 1U> iidx;
  coder::array<signed char, 2U> b;
  coder::array<boolean_T, 2U> x;
  double n_ol;
  double n_p;
  double n_ws;
  double xtmp_im;
  double xtmp_re;
  int b_currDFT[2];
  int i;
  int i1;
  int ii_data;
  int k;
  int kend;
  int md2;
  int nx;
  unsigned int rowEnd;
  unsigned int rowStart;
  boolean_T exitg1;
  if (!isInitialized_thresholdGeneratorPre) {
    thresholdGeneratorPre_initialize();
  }
  printf(
      "thresholdGeneratorPre - Fs:%f t_p:%f t_ip:%f t_ipu:%f t_ipj:%f K:%f\n",
      Fs, t_p, t_ip, t_ipu, t_ipj, K);
  fflush(stdout);
  n_p = std::ceil(t_p * Fs);
  // Samples per pulse
  // Number of elements in STFT window
  n_ol = std::floor(0.5 * n_p);
  // Number of elements overlap in STFT window
  n_ws = n_p - n_ol;
  // Number of elements in each step of STFT
  if (!(n_p >= 0.0)) {
    rtNonNegativeError(n_p, &b_emlrtDCI);
  }
  if (n_p != static_cast<int>(n_p)) {
    rtIntegerError(n_p, &c_emlrtDCI);
  }
  if (std::isinf(n_p)) {
    rtErrorWithMessageID("N", e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  buildtimecorrelatormatrix(std::floor(std::ceil(t_ip * Fs) / n_ws),
                            std::ceil(std::ceil(t_ipu * Fs) / n_ws),
                            std::ceil(std::ceil(t_ipj * Fs) / n_ws), K, Wq);
  // WEIGHTINGMATRIX Builds the spectral weighting matrix for the incoherent
  // summationation algorithm. The matrix is based on the DFT coefficients
  // developed from the waveform passed to the function. The function first
  // developeds a weighting vectors based on an unaltered waveform, but then
  // shifts the waveforms spectral content base fractions of the DFT bin width,
  // as defined by the zetas input. These shifted waveforms then have their
  // DFT's computed. The original and shifted DFT coefficients are then aligned
  // in a matrix. In this way, this weighting matrix allows for the dominant
  // frequency in the vector it weights to be between bins. This submatrix is
  // then row shifted and concantinated a number of times so that the DFT
  // coefficients are shifted across all DFT frequency bins. The outputs are
  // the weighting matrix W and a frequency vector Wf that corresponds to the
  // rows of W. The frequencies, and therefore the rows of the W matrix, use a
  // centered frequency definitions defined by the STFT.m algorithm.
  //
  //    Example:   [W,Wf] = weightingmatrix(rand(1,10),1,[0 0.5])
  //
  //    INPUTS:
  //    x_of_n      nx1     Vector of discrete data sampled as Fs. Can be 1xn.
  //    Fs          1x1     Sampling rate in Hz of the dataset
  //    zetas       mx1     A vector of fractions of the DFT frequency bin
  //                        width for which to compute and include in the
  //                        spectral weighting matrix output. If no interbin
  //                        shifting is desired, enter 0. Range of inputs
  //                        [0,1).
  //    frequencyRangeType  String of either 'centered' or 'twosided'. See
  //                        stft.m documentation on details of these frequency
  //                        bounds. If 'centered' is selected, the zero
  //                        frequency point is near the center of the output
  //                        matrix. If 'twosided' is selected, the zero
  //                        frequency points is in the upper left corner of the
  //                        output W matrix.
  //
  //    OUTPUTS:
  //    W           nxnm    A matrix of spectral weighting vectors along each
  //                        column. The hermitian of this matrix is designed to
  //                        be multiplied by a vector of DFT coefficients. The
  //                        weights held in column p can be thought of as the
  //                        matched DFT coefficients if the signal were to have
  //                        been shifted by the template by Wf(p).
  //    Wf          nmx1    A matrix of the frequency shifts corresponding to
  //                        each column of W
  //
  //  The intended use of the W matrix is to multiply it's hermetian by a FFT
  //  vector, or STFT matrix with frequencies in the rows.
  //
  //
  //    [W^h]*S         or          [W^h]*FFT
  //
  //  The outputs of this multiplication will have n*m rows. The rows of the
  //  result there for are the "scores" of at frequency associated with that
  //  row. The row frequencies are dependent on the zetas. Consider an input
  //  series that had frequencies [-100 0 100 200]. If the zeta input was
  //  [0 0.5], weightings for full and half frequencies steps would be
  //  developed.
  //
  //        output freq     input freq
  //                            -100    0   100     200
  //                -150    [                           ]
  //                -100    [                           ]
  //                -50     [                           ]
  //                0       [            W^h            ]
  //                50      [                           ]
  //                100     [                           ]
  //                150     [                           ]
  //                200     [                           ]
  //
  //    The first row of the matrix above would contain the weightings for the
  //    -100 0 100 and 200 Hz frequencie bins if the FFT (or STFT time window)
  //    had a signal at -150 Hz. Similarly, the second row would contain the
  //    weightings for the -100 0 100 and 200 Hz frequencie bins if the FFT
  //    (or STFT time window) had a signal at -100 Hz.
  //
  // Author: Michael Shafer
  // Date:   2020-12-19
  //
  //  Change Log
  //  2022-01-12    Updated to include twosided frequency range for output and
  //                updated the code associated with generating the unsorted W
  //                matrix to increase speed. Added use of makestftFreqVector
  //                function.
  //
  // Check the inputs
  // Reshape to a column vector, as the algorithm expects
  // F_bin_width = Fs/nw;
  if (static_cast<int>(n_p) - 1 < 0) {
    freqs.set_size(1, 0);
  } else {
    freqs.set_size(1, static_cast<int>(n_p));
    ii_data = static_cast<int>(n_p) - 1;
    for (i = 0; i <= ii_data; i++) {
      freqs[i] = i;
    }
  }
  // Use complex so when implementing in simulink later, it knows this is a
  // complex vector.
  s.set_size(static_cast<int>(n_p), 2);
  nx = static_cast<int>(n_p) << 1;
  Xs.set_size(static_cast<int>(n_p), 2);
  for (i = 0; i < nx; i++) {
    s[i].re = 0.0;
    s[i].im = 0.0;
    Xs[i].re = 0.0;
    Xs[i].im = 0.0;
  }
  // Develop a vector of frequencies that would result from the centered method
  // of the STFT function if it were computed on the x input. This is useful
  // for debugging the frequency outputs.
  // These are designed to develop the same freqs as the STFT centered method
  // Check the "'FrequencyRange' — STFT frequency range" in the STFT help file
  // if mod(nw,2)==0
  //     freqs_orig = ((-nw/2+1):nw/2)*Fs/nw;
  // else
  //     freqs_orig = (ceil(-nw/2):floor(nw/2))*Fs/nw;
  // end
  // figure;
  ii_data = freqs.size(1);
  for (int b_i{0}; b_i < 2; b_i++) {
    double t;
    double y;
    xtmp_im = 0.5 * static_cast<double>(b_i) * 6.2831853071795862;
    currDFT.set_size(freqs.size(1));
    for (i = 0; i < ii_data; i++) {
      t = xtmp_im * freqs[i];
      if (t == 0.0) {
        currDFT[i].re = 0.0 / static_cast<double>(static_cast<int>(n_p));
        currDFT[i].im = 0.0;
      } else {
        currDFT[i].re = 0.0;
        currDFT[i].im = t / static_cast<double>(static_cast<int>(n_p));
      }
    }
    nx = currDFT.size(0);
    if (currDFT.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (k = 0; k < nx; k++) {
      if (currDFT[k].im == 0.0) {
        currDFT[k].re = std::exp(currDFT[k].re);
        currDFT[k].im = 0.0;
      } else if (std::isinf(currDFT[k].im) && std::isinf(currDFT[k].re) &&
                 (currDFT[k].re < 0.0)) {
        currDFT[k].re = 0.0;
        currDFT[k].im = 0.0;
      } else {
        xtmp_re = std::exp(currDFT[k].re / 2.0);
        currDFT[k].re = xtmp_re * (xtmp_re * std::cos(currDFT[k].im));
        currDFT[k].im = xtmp_re * (xtmp_re * std::sin(currDFT[k].im));
      }
    }
    rtSubAssignSizeCheck(s.size(), 1, currDFT.size(), 1, &emlrtECI);
    kend = currDFT.size(0);
    for (i = 0; i < kend; i++) {
      s[i + s.size(0) * b_i] = currDFT[i];
    }
    kend = s.size(0);
    if ((s.size(0) != static_cast<int>(n_p)) &&
        ((s.size(0) != 1) && (static_cast<int>(n_p) != 1))) {
      emlrtDimSizeImpxCheckR2021b(s.size(0), static_cast<int>(n_p),
                                  &b_emlrtECI);
    }
    if (s.size(0) == static_cast<int>(n_p)) {
      b_s.set_size(s.size(0));
      for (i = 0; i < kend; i++) {
        b_s[i] = s[i + s.size(0) * b_i];
      }
      coder::fft(b_s, currDFT);
    } else {
      binary_expand_op(currDFT, s, b_i, n_p);
    }
    if (currDFT.size(0) == 0) {
      y = 0.0;
    } else {
      y = 0.0;
      if (currDFT.size(0) == 1) {
        y = rt_hypotd_snf(currDFT[0].re, currDFT[0].im);
      } else {
        xtmp_re = 3.3121686421112381E-170;
        kend = currDFT.size(0);
        if (currDFT.size(0) > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (k = 0; k < kend; k++) {
          xtmp_im = std::abs(currDFT[k].re);
          if (xtmp_im > xtmp_re) {
            t = xtmp_re / xtmp_im;
            y = y * t * t + 1.0;
            xtmp_re = xtmp_im;
          } else {
            t = xtmp_im / xtmp_re;
            y += t * t;
          }
          xtmp_im = std::abs(currDFT[k].im);
          if (xtmp_im > xtmp_re) {
            t = xtmp_re / xtmp_im;
            y = y * t * t + 1.0;
            xtmp_re = xtmp_im;
          } else {
            t = xtmp_im / xtmp_re;
            y += t * t;
          }
        }
        y = xtmp_re * std::sqrt(y);
      }
    }
    kend = currDFT.size(0);
    for (i = 0; i < kend; i++) {
      xtmp_re = currDFT[i].re;
      t = currDFT[i].im;
      if (t == 0.0) {
        xtmp_im = xtmp_re / y;
        xtmp_re = 0.0;
      } else if (xtmp_re == 0.0) {
        xtmp_im = 0.0;
        xtmp_re = t / y;
      } else {
        xtmp_im = xtmp_re / y;
        xtmp_re = t / y;
      }
      currDFT[i].re = xtmp_im;
      currDFT[i].im = xtmp_re;
    }
    // FFTSHIFTSTFT Performs a standard fftshift operation but accounts for the
    // different frequency range definition in Matlabs STFT function when
    // outputing a 'centered' frequency range
    //    When calling the STFT function, the default output for frequency is
    //    the 'centered' method where frequencies are reported on the range of
    //    (-n/2+1:n/2)*Fs/n if the vector is of even length and
    //    (ceil(-n/2):floor(n/2))*Fs/n if the vector is of odd length. It seems
    //    that Matlab's fftshift function is develped for frequencies in the
    //    range of (-n/2:n/2+1)*Fs/n if the vector is of even length. The odd
    //    length definition is unaffected. The result is an incorrect shifting
    //    of the frequency vector if fftshift is used on f defined by stft's
    //    centered method. This function uses the fftshift command for vectors
    //    of even length, but shifts the result by 1 to the left to correct for
    //    this problem.
    //
    //    If x is a matrix, it is assumed that the matrix is formatted similar
    //    to the output of a STFT call, wherein the rows represent the different
    //    frequencies and the rows are the time windows. As such, in this case
    //    the rows are operated on (shifted).
    //
    // INPUTS:
    //    x       nxm     A matrix of real or complex data. If passed a matrix,
    //                    the rows should represent frequency bins
    // OUTPUT:
    //    xout    nxm     A matrix of real or complex shifted data
    //
    //  Author: Michael Shafer
    //  Date:   2020-12-19
    //
    //  Change log:
    //  2022-01-10    Updated to deal with row or column vectors or stft
    //  matrices
    //
    //  if (numel(sz)~=2) && (min(sz)~=1)
    //      error('fftshiftstft only accepts vector inputs.')
    //  end
    // Passed a matrix or a column vector
    if (currDFT.size(0) == 0) {
      i = 0;
    } else {
      i = static_cast<int>(
          std::fmod(static_cast<double>(currDFT.size(0)), 2.0));
    }
    if (i != 0.0) {
      coder::fftshift(currDFT);
    } else {
      coder::fftshift(currDFT);
      if ((currDFT.size(0) != 0) && (currDFT.size(0) != 1)) {
        kend = static_cast<int>(
            std::floor(static_cast<double>(currDFT.size(0)) / 2.0));
        buffer.set_size(1, static_cast<int>(std::floor(
                               static_cast<double>(currDFT.size(0)) / 2.0)));
        for (i = 0; i < kend; i++) {
          buffer[i].re = 0.0;
          buffer[i].im = 0.0;
        }
        i = currDFT.size(0) - 2;
        buffer[0] = currDFT[0];
        for (k = 0; k <= i; k++) {
          currDFT[k] = currDFT[k + 1];
        }
        currDFT[i + 1] = buffer[0];
      }
    }
    rtSubAssignSizeCheck(Xs.size(), 1, currDFT.size(), 1, &c_emlrtECI);
    kend = currDFT.size(0);
    for (i = 0; i < kend; i++) {
      Xs[i + Xs.size(0) * b_i] = currDFT[i];
    }
    //    stem(freqs_orig,abs(Xs(:,i)),'DisplayName',['\zeta
    //    =',num2str(zetas(i))]); hold on
  }
  // ylabel('|Xs|');xlabel('Frequency');legend('Location',"best");
  // title('DFT of primary frequency shifts of the template')
  // New W generation method. ~25% faster on average
  xtmp_re = 2.0 * static_cast<double>(static_cast<int>(n_p));
  if (xtmp_re != static_cast<int>(xtmp_re)) {
    rtIntegerError(xtmp_re, &d_emlrtDCI);
  }
  stackedToeplitzMatrices.set_size(static_cast<int>(xtmp_re),
                                   static_cast<int>(n_p));
  if (xtmp_re != static_cast<int>(xtmp_re)) {
    rtIntegerError(xtmp_re, &e_emlrtDCI);
  }
  ii_data = static_cast<int>(xtmp_re) * static_cast<int>(n_p);
  for (i = 0; i < ii_data; i++) {
    stackedToeplitzMatrices[i].re = 0.0;
    stackedToeplitzMatrices[i].im = 0.0;
  }
  if (Xs.size(0) < 2) {
    i = -1;
    i1 = -1;
  } else {
    i = 0;
    i1 = Xs.size(0) - 1;
  }
  nx = i1 - i;
  md2 = nx >> 1;
  i1 = Xs.size(0) - 1;
  for (int b_i{0}; b_i < 2; b_i++) {
    int i2;
    int i3;
    int i4;
    rowStart = b_i * static_cast<int>(n_p) + 1U;
    rowEnd = (rowStart + static_cast<int>(n_p)) - 1U;
    if (rowStart > rowEnd) {
      i2 = 0;
      i3 = 0;
    } else {
      if ((static_cast<int>(rowStart) < 1) ||
          (static_cast<int>(rowStart) > stackedToeplitzMatrices.size(0))) {
        rtDynamicBoundsError(static_cast<int>(rowStart), 1,
                             stackedToeplitzMatrices.size(0), &b_emlrtBCI);
      }
      i2 = static_cast<int>(rowStart) - 1;
      if ((static_cast<int>(rowEnd) < 1) ||
          (static_cast<int>(rowEnd) > stackedToeplitzMatrices.size(0))) {
        rtDynamicBoundsError(static_cast<int>(rowEnd), 1,
                             stackedToeplitzMatrices.size(0), &c_emlrtBCI);
      }
      i3 = static_cast<int>(rowEnd);
    }
    if (Xs.size(0) < 1) {
      rtDynamicBoundsError(1, 1, Xs.size(0), &emlrtBCI);
    }
    currDFT.set_size(nx);
    for (i4 = 0; i4 < nx; i4++) {
      currDFT[i4] = Xs[((i + i4) + Xs.size(0) * b_i) + 1];
    }
    for (int c_i{0}; c_i < md2; c_i++) {
      xtmp_re = currDFT[c_i].re;
      xtmp_im = currDFT[c_i].im;
      kend = (nx - c_i) - 1;
      currDFT[c_i] = currDFT[kend];
      currDFT[kend].re = xtmp_re;
      currDFT[kend].im = xtmp_im;
    }
    b_s.set_size(currDFT.size(0) + 1);
    b_s[0] = Xs[Xs.size(0) * b_i];
    ii_data = currDFT.size(0);
    for (i4 = 0; i4 < ii_data; i4++) {
      b_s[i4 + 1] = currDFT[i4];
    }
    r.set_size(Xs.size(0), b_s.size(0));
    kend = 0;
    i4 = b_s.size(0) - 1;
    for (ii_data = 0; ii_data <= i4; ii_data++) {
      k = ii_data;
      for (int c_i{0}; c_i <= i1; c_i++) {
        if (c_i < ii_data) {
          r[kend + c_i] = b_s[k];
          k--;
        } else {
          r[kend + c_i] = Xs[k + Xs.size(0) * b_i];
          k++;
        }
      }
      kend = (kend + i1) + 1;
    }
    b_currDFT[0] = i3 - i2;
    b_currDFT[1] = stackedToeplitzMatrices.size(1);
    rtSubAssignSizeCheck(&b_currDFT[0], 2, r.size(), 2, &d_emlrtECI);
    ii_data = r.size(1);
    for (i3 = 0; i3 < ii_data; i3++) {
      kend = r.size(0);
      for (i4 = 0; i4 < kend; i4++) {
        stackedToeplitzMatrices[(i2 + i4) + stackedToeplitzMatrices.size(0) *
                                                i3] = r[i4 + r.size(0) * i3];
      }
    }
  }
  // Reshape in this way will interweave rows of each sub matrix of the stack
  rowStart = static_cast<unsigned int>(static_cast<int>(n_p)) << 1;
  nx = stackedToeplitzMatrices.size(0) * stackedToeplitzMatrices.size(1);
  coder::internal::assertValidSizeArg(
      static_cast<double>(static_cast<int>(n_p)));
  coder::internal::assertValidSizeArg(static_cast<double>(rowStart));
  kend = stackedToeplitzMatrices.size(0);
  if (stackedToeplitzMatrices.size(1) > stackedToeplitzMatrices.size(0)) {
    kend = stackedToeplitzMatrices.size(1);
  }
  if (nx >= kend) {
    kend = nx;
  }
  if (static_cast<int>(n_p) > kend) {
    c_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  if (static_cast<int>(rowStart) > kend) {
    c_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  if (static_cast<int>(n_p) * static_cast<int>(rowStart) != nx) {
    b_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  // OLD W generation method. Easier to understand, but slower
  //  W     = 1i*zeros(nw,numZetas*nw);
  //  freqs = zeros(1,numZetas*nw);
  //  for i = 1:nw
  //      W(:,(i-1)*numZetas+(1:numZetas))=...
  //          circshift(Xs,i-1,1);
  //  end
  // Build a vector of the frequencies
  //   tick=1;
  //   for i = 1:numZetas:size(W,2)
  //       freqs(i:i+(numZetas-1)) = Fs/nw*((tick-1)+zetas);
  //       tick = tick+1;
  //   end
  // MAKESTFTFREQVECTOR Generates the frequency vector based on the frequency
  // range specification for Matlab's stft.m 'FrequencyRange' input standard,
  //
  //    This function outputs a frequency vector based on the frequency
  //    range specification for Matlab's stft.m 'FrequencyRange' input
  //    standard. The options for the frequency ranges are 'centered'
  //    (default), 'twosided', and 'onesided'. The sftf.m documentation
  //    standard states:
  //        STFT frequency range, specified as 'centered', 'twosided', or
  //        'onesided'.
  //
  //        'centered' — Compute a two-sided, centered STFT. If 'FFTLength' is
  //        even, then s is computed over the interval (–π, π] rad/sample. If
  //        'FFTLength' is odd, then s is computed over the interval (–π, π)
  //        rad/sample. If you specify time information, then the intervals are
  //         (–fs, fs/2] cycles/unit time and (–fs, fs/2) cycles/unit time,
  //        respectively, where fs is the effective sample rate.
  //
  //        'twosided' — Compute a two-sided STFT over the interval [0, 2π)
  //        rad/sample. If you specify time information, then the interval is
  //        [0, fs) cycles/unit time.
  //
  //        'onesided' — Compute a one-sided STFT. If 'FFTLength' is even,
  //        then s is computed over the interval [0, π] rad/sample. If
  //        'FFTLength' is odd, then s is computed over the interval [0, π)
  //        rad/sample. If you specify time information, then the intervals are
  //         [0, fs/2] cycles/unit time and [0, fs/2) cycles/unit time,
  //        respectively, where fs is the effective sample rate. This option is
  //         valid only for real signals.
  //
  //    If Fs is not specificed, outputs will be in rad/sample with pi as
  //    specified in the stft.m frequency range standard.
  //
  // INPUTS:
  //    nfft                 Length of FFT performed on the STFT.
  //    frequencyRangeType   String containing 'centered', 'twosided',
  //    'onesided' Fs                   Sample rate of data
  //
  // OUTPUTS:
  //    freqs       Vector of frequencies at which the STFT is calculated
  //
  // Author:    Michael Shafer
  // Date:      2022-01-11
  //
  if (static_cast<double>(rowStart) - 1.0 < 0.0) {
    freqs.set_size(freqs.size(0), 0);
  } else {
    freqs.set_size(1,
                   static_cast<int>(static_cast<double>(rowStart) - 1.0) + 1);
    ii_data = static_cast<int>(static_cast<double>(rowStart) - 1.0);
    for (i = 0; i <= ii_data; i++) {
      freqs[i] = i;
    }
  }
  freqs.set_size(1, freqs.size(1));
  ii_data = freqs.size(1) - 1;
  for (i = 0; i <= ii_data; i++) {
    freqs[i] = freqs[i] * Fs / static_cast<double>(rowStart);
  }
  // Simulink (coder?) didn't like the new round inputs
  // freqs = round(freqs,3);
  // freqs = round(freqs*1000)/1000;
  // Shift everything so we use a negative frequencies
  // A little non-matlab notation to get this to run in simulink.
  // nyq_ind(1)  = find(freqs == floor(Fs/2),1,'first');
  x.set_size(1, freqs.size(1));
  xtmp_re = Fs / 2.0;
  ii_data = freqs.size(1);
  for (i = 0; i < ii_data; i++) {
    x[i] = (freqs[i] == xtmp_re);
  }
  k = (x.size(1) >= 1);
  if (k > x.size(1)) {
    rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  kend = 0;
  if (x.size(1) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  nx = 0;
  exitg1 = false;
  while ((!exitg1) && (nx <= x.size(1) - 1)) {
    if (x[nx]) {
      kend = 1;
      ii_data = nx + 1;
      exitg1 = true;
    } else {
      nx++;
    }
  }
  if (kend > k) {
    rtErrorWithMessageID(i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  if (k == 1) {
    if (kend == 0) {
      k = 0;
    }
  } else {
    k = (kend >= 1);
  }
  for (i = 0; i < k; i++) {
    rowEnd = static_cast<unsigned int>(ii_data);
  }
  if (k != 1) {
    rtSizeEq1DError(1, 0, &e_emlrtECI);
  }
  kend = static_cast<int>(rowEnd);
  if (freqs.size(1) < 1) {
    rtDynamicBoundsError(freqs.size(1), 1, freqs.size(1), &d_emlrtBCI);
  }
  xtmp_re = -freqs[freqs.size(1) - 1] - (Fs - freqs[freqs.size(1) - 1]);
  b.set_size(1, b.size(1));
  i = freqs.size(1) - static_cast<int>(rowEnd);
  if (i < 0) {
    rtNonNegativeError(static_cast<double>(i), &f_emlrtDCI);
  }
  b.set_size(b.size(0), i);
  ii_data = freqs.size(1) - static_cast<int>(rowEnd);
  if (ii_data < 0) {
    rtNonNegativeError(static_cast<double>(ii_data), &g_emlrtDCI);
  }
  for (i = 0; i < ii_data; i++) {
    b[i] = 1;
  }
  wrapper.set_size(1, static_cast<int>(rowEnd) + b.size(1));
  for (i = 0; i < kend; i++) {
    wrapper[i] = 0.0;
  }
  ii_data = b.size(1);
  for (i = 0; i < ii_data; i++) {
    wrapper[i + static_cast<int>(rowEnd)] = xtmp_re;
  }
  if ((wrapper.size(1) != freqs.size(1)) &&
      ((wrapper.size(1) != 1) && (freqs.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(wrapper.size(1), freqs.size(1), &f_emlrtECI);
  }
  // Here we sort the output to set up to have an ascending order of frequency
  // to be similar to the centered frequency list used elsewhere in the
  // codebase for the STFT output.
  if (wrapper.size(1) == freqs.size(1)) {
    b_x.set_size(wrapper.size(1));
    ii_data = wrapper.size(1);
    for (i = 0; i < ii_data; i++) {
      b_x[i] = wrapper[i] + freqs[i];
    }
  } else {
    binary_expand_op(b_x, wrapper, freqs);
  }
  coder::internal::sort(b_x, iidx);
  ii_data = static_cast<int>(n_p);
  W.set_size(static_cast<int>(n_p), iidx.size(0));
  kend = iidx.size(0);
  for (i = 0; i < kend; i++) {
    for (i1 = 0; i1 < ii_data; i1++) {
      if ((iidx[i] < 1) || (iidx[i] > static_cast<int>(rowStart))) {
        rtDynamicBoundsError(iidx[i], 1, static_cast<int>(rowStart),
                             &e_emlrtBCI);
      }
      W[i1 + W.size(0) * i].re =
          stackedToeplitzMatrices[i1 + static_cast<int>(n_p) * (iidx[i] - 1)]
              .re;
      if ((iidx[i] < 1) || (iidx[i] > static_cast<int>(rowStart))) {
        rtDynamicBoundsError(iidx[i], 1, static_cast<int>(rowStart),
                             &e_emlrtBCI);
      }
      W[i1 + W.size(0) * i].im =
          stackedToeplitzMatrices[i1 + static_cast<int>(n_p) * (iidx[i] - 1)]
              .im;
    }
  }
  // Number of sets of synthetic noise to generate
  // Calculate the total power in the waveform for all frequency bins. Units are
  // W/bin * # bins = W
  coder::wgn((static_cast<double>(Wq->m) + 1.0) * n_ws + n_ol, n_p, xsynth);
  // Generate the synthetic data
  r1.set_size(static_cast<int>(n_p));
  ii_data = static_cast<int>(n_p);
  for (i = 0; i < ii_data; i++) {
    r1[i] = 1.0;
  }
  coder::stft(xsynth, Fs, r1, n_ol, n_p, Ssynth, b_x, a__3);
  b_Wq.set_size(1, Ssynth.size(1) - Wq->m);
  ii_data = Ssynth.size(1) - Wq->m;
  for (i = 0; i < ii_data; i++) {
    b_Wq[i] = (Wq->m + i) + 1;
  }
  coder::internal::nullAssignment(Ssynth, b_Wq);
  // Trim excess so we have the correct number of windows.
  *success = true;
}

//
// File trailer for thresholdGeneratorPre.cpp
//
// [EOF]
//
