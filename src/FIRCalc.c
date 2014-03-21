#include "FIRCalc.h"

void FIRCalcHamming(int length, int cutoff, double *coeffs)
{
  double sum = 0;

  if ((length % 2) == 0) // Even length
  {
    for (int i=0; i<length; i++)
    {
      n = i - (length / 2.0) + 0.5;
      // Calculate Sinc function
      coeffs[i] = sin(FIRCALC_PI*n*cutoff) / (FIRCALC_PI*n*cutoff);
      // Multiply by Hamming Window
      coeffs[i] *= (25.0/46.0) + (21.0/46.0)*cos(2*FIRCALC_PI*n*cutoff/(length-1));
    }
  }
  else // Odd length filter
  {
    for (int i=0; i<length; i++)
    {
      n = i - ((length-1) / 2.0);
      // Calculate Sinc function
      if (n == 0) {
        coeffs[i] = 1;
      } else {
        coeffs[i] = sin(FIRCALC_PI*n*cutoff) / (FIRCALC_PI*n*cutoff);
      }
      // Multiply by Hamming Window
      coeffs[i] *= (25.0/46.0) + (21.0/46.0)*cos(2*FIRCALC_PI*n*cutoff/(length-1));
    }
  }

  sum = fabs(sum);

  // Scale the filter coefficients
  for (int i=0; i<length; i++)
  {
    coeffs[i] /= sum;
  }

}

