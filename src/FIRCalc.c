#include <math.h>
#include <stdlib.h>
#include "FIRCalc.h"
#include "FIRCalcWindows.h"

const double PI = 3.14159265;

void FIRCalcWindow(int length, double cutoff, double *coeffs, double *window)
{
  double sum = 0;

  if ((length % 2) == 0) // Even length
  {
    for (int i=0; i<length; i++)
    {
      double n = i - (length / 2.0) + 0.5;
      // Calculate Sinc function
      coeffs[i] = sin(PI * n * cutoff) / (PI * n * cutoff);
      // Multiply by the window
      coeffs[i] *= window[i];
      sum += coeffs[i];
    }
  }
  else // Odd length filter
  {
    for (int i=0; i<length; i++)
    {
      double n = i - ((length-1) / 2.0);
      // Calculate Sinc function
      if (n == 0) {
        coeffs[i] = 1;
      } else {
        coeffs[i] = sin(PI*n*cutoff) / (PI*n*cutoff);
      }
      // Multiply by Hamming Window
      coeffs[i] *= window[i];
      sum += coeffs[i];
    }
  }

  sum = fabs(sum);

  // Scale the filter coefficients
  for (int i=0; i<length; i++)
  {
    coeffs[i] /= sum;
  }

}

void FIRCalcHann(int length, double cutoff, double *coeffs)
{
  double *window;
  window = malloc(length * sizeof(double));
  FIRCalcHannWindow(length, window);
  FIRCalcWindow(length, cutoff, coeffs, window);
  free(window);
}

void FIRCalcHamming(int length, double cutoff, double *coeffs)
{
  double *window;
  window = malloc(length * sizeof(double));
  FIRCalcHammingWindow(length, window);
  FIRCalcWindow(length, cutoff, coeffs, window);
  free(window);
}

void FIRCalcBlackman(int length, double cutoff, double *coeffs, double alpha)
{
  double *window;
  window = malloc(length * sizeof(double));
  FIRCalcBlackmanWindow(length, window, alpha);
  FIRCalcWindow(length, cutoff, coeffs, window);
  free(window);
}

void FIRCalcExactBlackman(int length, double cutoff, double *coeffs)
{
  double *window;
  window = malloc(length * sizeof(double));
  FIRCalcExactBlackmanWindow(length, window);
  FIRCalcWindow(length, cutoff, coeffs, window);
  free(window);
}

void FIRCalcBlackmanHarris(int length, double cutoff, double *coeffs)
{
  double *window;
  window = malloc(length * sizeof(double));
  FIRCalcBlackmanHarrisWindow(length, window);
  FIRCalcWindow(length, cutoff, coeffs, window);
  free(window);
}

void FIRCalcKaiser(int length, double cutoff, double *coeffs, double alpha)
{
  double *window;
  window = malloc(length * sizeof(double));
  FIRCalcKaiserWindow(length, window, alpha);
  FIRCalcWindow(length, cutoff, coeffs, window);
  free(window);
}
