/*
 * main.c
 */

#include <math.h>
#include <tms320.h>
#include <dsplib.h>

#include "t8.h"

#include <stdio.h>

int main(void) {
	
	 rifft(x,NX,SCALE);

	 int index;
	 for (index = 0; index < NX; index++) {
		 printf("Sample %i: %i\n", index, x[index]);
	 }

	return 0;
}
