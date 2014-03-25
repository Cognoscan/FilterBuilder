#include <math.h>
#include "FIRCalcWindows.h"

static const double PI = 3.14159265;

// Hann Window
void FIRCalcHannWindow(int length, double *window)
{
  for (int i=0; i<length; i++)
  {
    window[i] = 0.5 - 0.5*cos(2*PI*i/(length-1));
  }
}

// Hamming Window
void FIRCalcHammingWindow(int length, double *window)
{
  for (int i=0; i<length; i++)
  {
    window[i] = (25.0/46.0) - (21.0/46.0)*cos(2*PI*i/(length-1));
  }
}

// Blackman Window
void FIRCalcBlackmanWindow(int length, double *window, double alpha)
{
  for (int i=0; i<length; i++)
  {
    window[i] = (1-alpha)/2.0 -
      (1/2.0)*cos(2*PI*i/(length-1)) +
      (alpha/2.0)*cos(4*PI*i/(length-1));
  }
}

// Exact Blackman Window
void FIRCalcExactBlackmanWindow(int length, double *window)
{
  FIRCalcBlackmanWindow(length, window, 0.16);
}

// Blackman-Harris Window
void FIRCalcBlackmanHarrisWindow(int length, double *window)
{
  for (int i=0; i<length; i++)
  {
    double n = i - (length / 2.0) + 0.5;
    window[i] = 0.35875 -
      0.48829 * cos(2*PI*i/(length-1)) +
      0.14128 * cos(4*PI*i/(length-1)) -
      0.01168 * cos(6*PI*i/(length-1));
  }
}

double FIRCalcBessi0(double x)
{
  double ax, ans;
  double y;

  ax = fabs(x);
  if (ax < 3.75)
  {
    y = x/3.75; 
    y = y*y;
    ans = 1.0+y*(3.5156229+y*(3.0899424+y*(1.2067492
            +y*(0.2659732+y*(0.360768e-1+y*0.45813e-2)))));
  }
  else
  {
    y = 3.75/ax;
    ans = (exp(ax)/sqrt(ax))*(0.39894228+y*(0.1328592e-1
          +y*(0.225319e-2+y*(-0.157565e-2+y*(0.916281e-2
                +y*(-0.2057706e-1+y*(0.2635537e-1)))))));
  }
  return ans;
}

void FIRCalcKaiserWindow(int length, double *window, double alpha)
{
  double denom = FIRCalcBessi0(PI*alpha);
  for (int i=0; i<length; i++)
  {
    window[i] = FIRCalcBessi0(PI*alpha*sqrt(1-pow((2*i/(length-1))-1,2))) / denom;
  }
}

