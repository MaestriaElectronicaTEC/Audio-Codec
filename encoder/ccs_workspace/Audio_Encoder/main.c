#include <stdio.h>

#include "fft_routines.h"

#include <dsplib.h>

void call_random()
{
	rand16init();	// DSPlib init seed routine

	int random_return_value; 						// flag to read if there is overflow
	DATA random_data_array[5] = {0, 0, 0, 0, 0};	// struct where the random numbers will reside

	random_return_value = rand16(random_data_array, 5); // create 5 random numbers and store them on random_data_array, using DSPlib

	if(random_return_value) {
		printf("Return value is bigger than 0 \n");
	} else {
		printf("Return value is NOT bigger than 0 \n");
	}

	int i;
	for(i = 0; i < 100; i++)
	{
		printf("DATA: %i \n", random_data_array[i]);
	}

}

int main(void)
{
	call_random();

	return 0;
}
