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

#define FFT_SAMP (10)

#define BLOCKSIZE   1024

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
    int nch = wave_get_num_channels(waveFile);
    short **inBuf = (short**)malloc(nch * sizeof(short*));
    if(!inBuf){
        wave_close(waveFile);
        return 1;
    }
    
    //int blockSize = (1<<FFT_SAMP)*2;
    int i;
    for (i=0; i<nch; ++i) {
        inBuf[i] = malloc(BLOCKSIZE);
    }
    
    /* try to create a file */
    FILE* out = fopen(argv[2], "wb");
    if(out==NULL){
        wave_close(waveFile);
        free(inBuf);
        printf("%s couldn't be created!\n", argv[2]);
    }
    
    size_t readlen;
    do {
        readlen = wave_read((void**)inBuf, BLOCKSIZE, waveFile);
        fix_fftr(inBuf[0], FFT_SAMP, 0);
        fwrite(inBuf[0], 1, BLOCKSIZE, out);
        fix_fftr(inBuf[1], FFT_SAMP, 0);
        fwrite(inBuf[1], 1, BLOCKSIZE, out);
    } while (readlen == BLOCKSIZE);
    
    wave_close(waveFile);
    fclose(out);
    free(inBuf);
    return 1;
}

