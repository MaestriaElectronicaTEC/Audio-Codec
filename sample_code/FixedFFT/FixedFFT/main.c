//
//  main.c
//  FixedFFT
//
//  Created by Luis Alonso Murillo Rojas on 11/4/18.
//  Copyright © 2018 TEC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "fix_fft.h"
#include "libwav/wave.h"

FILE*fp;

#define FFT_SAMP (9)

#define BLOCKSIZE   256

static inline size_t container_size(size_t sample_size)
{
    size_t ret = 1;
    int i = 0;
    
    do {
        if (ret >= sample_size) {
            return ret;
        }
        ++i;
        ret <<= 1;
    } while (i < 8*sizeof(size_t));
    
    return (size_t)1 << (i - 1);
}

char help[] = "usage: <in> <out> <inverse? 1 : 0>";
int main(int argc, char** argv)
{
    /* Try to open the given file */
    WaveFile *waveFile = wave_open(/*argv[1]*/"music_test_0.wav", "rb");
    if (!waveFile) {
        printf("File not found!\n");
        return 0;
    }
    int nch = wave_get_num_channels(waveFile);
    short **inBuf = (short**)malloc(nch * sizeof(short*));
    if(!inBuf){
        wave_close(waveFile);
        return 1;
    }
    
    int blockSize = (1<<FFT_SAMP)*2;
    int i;
    for (i=0; i<nch; ++i) {
        inBuf[i] = malloc(container_size(wave_get_sample_size(waveFile)) * blockSize);
    }
    
    /* try to create a file */
    FILE* out = fopen(/*argv[2]*/"out.txt", "wb");
    if(out==NULL){
        wave_close(waveFile);
        free(inBuf);
        printf("%s couldn't be created!\n", argv[2]);
    }
    
    size_t readlen;
    do {
        readlen = wave_read((void**)inBuf, blockSize, waveFile);
        fix_fftr(inBuf[0], FFT_SAMP, 0);
        short coeff = *inBuf[0];
        fwrite(inBuf[0], 1, blockSize, out);
    } while (readlen == blockSize);
    
    wave_close(waveFile);
    fclose(out);
    free(inBuf);
    return 1;
}

