//
//  main.c
//  FixDecoder
//
//  Created by Luis Alonso Murillo Rojas on 22/4/18.
//  Copyright © 2018 TEC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "fix_fft.h"
#include "libwav/wave.h"

#define FORMAT 1
#define CHANNELS 2
#define SAMPLE_RATE 8000
#define BPS 16
#define SAMPLE_SIZE 2

#define FFT_SAMP (10)
#define BLOCKSIZE 1024

char help[] = "usage: <in> <out>";
int main(int argc, const char * argv[]) {
    
    if(argc < 3){
        printf("%s\n", help);
        return 0;
    }
    
    FILE* fp = fopen(argv[1], "rb");
    if(fp==NULL){
        printf("%s couldn't be created!\n", argv[1]);
    }
    
    /* Init a wave file */
    WaveFile *waveFile = wave_open((char *)argv[2], "wb");
    wave_set_format(waveFile, FORMAT);
    wave_set_num_channels(waveFile, CHANNELS);
    wave_set_sample_rate(waveFile, SAMPLE_RATE);
    wave_set_valid_bits_per_sample(waveFile, BPS);
    wave_set_sample_size(waveFile, SAMPLE_SIZE);
    
    /* Setup the buffer */
    short **inBuf = (short**)malloc(CHANNELS * sizeof(short*));
    if(!inBuf){
        wave_close(waveFile);
        fclose(fp);
        return 1;
    }
    int i;
    for (i=0; i<CHANNELS; ++i) {
        inBuf[i] = malloc(BLOCKSIZE);
    }
    
    size_t readlen;
    do {
        //Read coefficients of channel 1
        readlen = fread(inBuf[0], BLOCKSIZE, 1, fp);
        fix_fftr(inBuf[0], FFT_SAMP, 1);
        
        //Read coefficients of channel 2
        readlen = fread(inBuf[1], BLOCKSIZE, 1, fp);
        fix_fftr(inBuf[1], FFT_SAMP, 1);
        
        //Write the WAV
        wave_write((void**)inBuf, BLOCKSIZE, waveFile);
    } while (readlen == BLOCKSIZE);
    
    wave_close(waveFile);
    fclose(fp);
    free(inBuf);
    
    return 0;
}
