#ifndef FIRCALCWINDOWS_H_
#define FIRCALCWINDOWS_H_

double FIRCalcBessi0(double x);

void FIRCalcHannWindow(int length, double *window);
void FIRCalcHammingWindow(int length, double *window);
void FIRCalcBlackmanWindow(int length, double *window, double alpha);
void FIRCalcExactBlackmanWindow(int length, double *window);
void FIRCalcBlackmanHarrisWindow(int length, double *window);
void FIRCalcKaiserWindow(int length, double *window, double beta);

#endif
