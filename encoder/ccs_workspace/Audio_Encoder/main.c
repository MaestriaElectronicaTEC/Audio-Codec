#include <stdio.h>

#include "fft_routines.h"

#include "t8.h"

#include <dsplib.h>

void call_random()
{

	rfft(x, NX, SCALE);

	int i;
	for (i = 0; i < NX; i++)
	{
		printf("DATA: %i \n", x[i]);
	}

}

int main(void)
{
	call_random();

	return 0;
}
