/**************************************************************************
 *  $Id$
 *  File:	ComputeFFT.c - Computes the FFT magnitude spectrum of a signal
 *
 *  Purpose:	CS240 -II Assignment
 *
 *  Author:	Hema Murthy
 *
 *  Date:	Sat Mar  8 23:41:08 IST 2008
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 *
 **************************************************************************/

#include "stdio.h"
#include "unistd.h"
#include "math.h"
//#include "malloc.h"
#include "stdlib.h"
#include "FFT.h"
#include "AllocateMemory.h"

/*******************************************************************************
* 	the Following program computes the FFT Magnitude Spectrum
*	Input: dataFile, FFTOrder, FFTSize, 
*	Output :outPutFile

*******************************************************************************/       void Usage() {
           printf("Usage : ComputeFFT dataInFile FFTOrder FFTSize outputFile\n");
}
/*****************************************************************************/

int main (int argc, char *argv[])
{ 

  complex          *signalIn, *signalOut;
  int  	           i, fftOrder, fftSize;
  char             line[200];
  FILE            *fin, *fout;

 /******************************************************************************/ 
       if (argc != 5) {
         Usage();
         _exit(-1);
       }
       printf("%s %s %s %s\n", argv[1], argv[2], argv[3], argv[4]);
       fin = fopen(argv[1], "r");
       fout = fopen(argv[4], "w");
       
       sscanf(argv[2], "%d",&fftOrder);
       sscanf(argv[3], "%d",&fftSize);

       signalIn = (complex *) calloc(fftSize+1, sizeof(complex));
       signalOut = (complex *) calloc(fftSize+1, sizeof(complex));
       i = 1;
       while ((fgets (line, 200, fin) != NULL) && (i <= fftSize)){ 
         sscanf(line, "%f", &signalIn[i].re);
         signalIn[i].im = 0;
         i++;
       }
       Cstore(fftSize);
       Cfft(signalIn, signalOut, fftOrder, fftSize, -1);
       for (i = 1; i <= fftSize; i++)
         fprintf(fout, "%f\n",
		 sqrt (signalOut[i].re*signalOut[i].re + 
		       signalOut[i].im*signalOut[i].im));
       fclose(fin);
       fclose(fout);
       return(0);
}





/**************************************************************************
 * $Log$
 *
 *                        End of ComputeFFT.c
 **************************************************************************/
