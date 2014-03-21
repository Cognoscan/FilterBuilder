/* @file main.c
 * @brief FIRCalc Reference Implementation
 * @author Richard Scott Teal
 * @date 2014-03-20
 * @copyright
 *
 * Copyright 2014 Richard Scott Teal
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <cstring.h>
#include <stdlib.h>

#include "FIRCalc.h"

/// Main terminal program
int main( int argc, int *argv[])
{
  int success = 0;

  if (argc != 5) {
    printf("Usage: %s ORDER CUTOFF TYPE WINDOW", argv[0]);
    return 1;
  }

  int length;
  double cutoff;
  double *coeffs;

  sscanf("%i", length); length += 1; // Length is 1 greater than the order
  sscanf("%lf", cutoff);

  coeffs = (double *) malloc(length * sizeof(double));

  if (strcmp(argv[4], "hamming") == 0)
  {
    FIRCalcHamming(order, cutoff, coeffs);
  } else {
    printf("Not a valid window type\n");
    success = 1;
  }

  if (success == 0)
  {
    for (int i=0; i<length; i++)
    {
      printf("%3i, %8.5f\n", i, coeffs[i]);
    }
  }

  free(coeffs);

  return success;

}

