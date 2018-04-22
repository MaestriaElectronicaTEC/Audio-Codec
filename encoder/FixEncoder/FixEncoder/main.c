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
#include "libfixmath/fixmath.h"

FILE*fp;
FILE* out;

#define FFT_SAMP (10)
#define BLOCKSIZE 1024
#define MIN_FREC 20
#define MAX_FREC 20000

fix16_t _minFrec = 1310720;     //20Hz
fix16_t _maxFrec = 1310720000;  //20000Hz

void storeCoeff(short **inBuf, size_t fs, int ch) {
    for (int index = 0; index < (BLOCKSIZE/2); index++) {
        fix16_t frec = fix16_mul(fix16_from_int(index), fix16_div(fix16_from_int((int)fs), fix16_from_int(BLOCKSIZE)));
        
        if (_minFrec > frec || _maxFrec < frec) {
            //printf("Frecuency out of audible: %f\n", fix16_to_float(frec));
        }
    }
}

char help[] = "usage: <in> <out>";
int main(int argc, char** argv)
{
    if(argc < 3){
        printf("%s\n", help);
        return 0;
    }
    
    /* Try to open the given file */
    WaveFile *waveFile = wave_open(argv[1], "rb");
    if (!waveFile) {
        printf("File not found!\n");
        return 0;
    }
    
    /* Wave information */
    uint32_t sampleRate = wave_get_sample_rate(waveFile);
    printf("Sample rate: %i\n", sampleRate);
    uint32_t waveFormat = wave_get_format(waveFile);
    printf("Format: %i\n", waveFormat);
    uint32_t bps = wave_get_valid_bits_per_sample(waveFile);
    printf("BPS: %i\n", bps);
    int nch = wave_get_num_channels(waveFile);
    printf("Channels: %i\n", nch);

    short **inBuf = (short**)malloc(nch * sizeof(short*));
    if(!inBuf){
        wave_close(waveFile);
        return 1;
    }
    
    int i;
    for (i=0; i<nch; ++i) {
        inBuf[i] = malloc(BLOCKSIZE);
    }
    
    /* try to create a file */
    out = fopen(argv[2], "wb");
    if(out==NULL){
        wave_close(waveFile);
        free(inBuf);
        printf("%s couldn't be created!\n", argv[2]);
    }
    
    size_t index = 0;
    size_t readlen;
    do {
        readlen = wave_read((void**)inBuf, BLOCKSIZE, waveFile);
        fix_fftr(inBuf[0], FFT_SAMP, 0);
        //storeCoeff(inBuf, sampleRate, 0);
        fwrite(inBuf[0], 1, BLOCKSIZE, out);
        fix_fftr(inBuf[1], FFT_SAMP, 0);
        //storeCoeff(inBuf, sampleRate, 1);
        fwrite(inBuf[1], 1, BLOCKSIZE, out);
        
        index++;
    } while (readlen == BLOCKSIZE);
    
    wave_close(waveFile);
    fclose(out);
    free(inBuf);
    return 1;
}

