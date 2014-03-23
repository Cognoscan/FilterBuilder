#ifndef FIRCALC_H_
#define FIRCALC_H_

void FIRCalcWindow(int length, double cutoff, double *coeffs, double *window);
void FIRCalcHann(int length, double cutoff, double *coeffs);
void FIRCalcHamming(int length, double cutoff, double *coeffs);
void FIRCalcBlackman(int length, double cutoff, double *coeffs, double alpha);
void FIRCalcExactBlackman(int length, double cutoff, double *coeffs);
void FIRCalcBlackmanHarris(int length, double cutoff, double *coeffs);
void FIRCalcKaiser(int length, double cutoff, double *coeffs, double alpha);

#endif
