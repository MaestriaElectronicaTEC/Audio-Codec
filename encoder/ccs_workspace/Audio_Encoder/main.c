#include <stdio.h>

#include "fft_routines.h"

#include <dsplib.h>


void call_random();
void call_random()
{
	ushort random_return_value; // flag to read if overflow
	DATA *random_data_array;	// struct where the random numbers will reside

	random_return_value = rand16(random_data_array, 100); // create 100 random numbers and store them on random_data_array

	int i;
	for(i = 0; i < 100; i++)
	{
		printf("DATA: %i \n", random_data_array[i]);
	}
}

int main(void) {
	printf("Hello World!\n");

	call_random();



	return 0;
}
