/*
 * main.c
 */


#include <math.h>
#include <tms320.h>
#include <dsplib.h>

#include <stdio.h>

#include "t8.h"

int main(void) {
	
	rfft(x,NX,SCALE);

	int index;
	for (index = 0; index < NX; index++) {
		printf("Sample %i: %i\n", index, x[index]);
	}

	return 0;
}
