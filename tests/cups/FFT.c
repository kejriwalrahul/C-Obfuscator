/**************************************************************************
 *  $Id$
 *  File:	FFT.c - functions for computing FFT of a signal
 *
 *  Purpose:	Compute the Forward/Inverse Fourier transform of a signal
 *
 *  Author:	Hema Murthy
 *
 *  Date:	Sat Mar  8 23:15:38 IST 2008
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 *
 **************************************************************************/
#include "math.h"
#include "stdio.h"
#include "unistd.h"
#include "FFT.h"
#include "AllocateMemory.h"

#define PI            3.1415926535898

/* definitions for complex number arithmetic */

/* temporary variable definitions for complex arithmetic */

 float  rp_a,im_a,rp_b,im_b;

/* add complex no's a and b and store the result in c */

# define cadd(c,a,b) rp_a = a.re; im_a = a.im; \
                     rp_b = b.re; im_b = b.im; \
                     c.re = rp_a + rp_b;       \
                     c.im = im_a + im_b

/* conjugate f complex number a stored in c */

# define conjg(c,a) rp_a = a.re; im_a = a.im; \
                   c.re = rp_a; \
                   c.im = -im_a
 
/* subtract b from a and store the result in c */ 

# define csub(c,a,b) rp_a = a.re; im_a = a.im; \
                     rp_b = b.re; im_b = b.im; \
                     c.re = rp_a - rp_b;       \
                     c.im = im_a - im_b

/* multiply a and b and store in c */

# define cmul(c,a,b) rp_a = a.re; im_a = a.im;     \
                     rp_b = b.re; im_b = b.im;     \
                     c.re = rp_a*rp_b - im_a*im_b; \
                     c.im = rp_a*im_b + im_a*rp_b

/* divide a by b and store the result in c */

# define cdiv(c,a,b) rp_a = a.re; im_a = a.im; \
                     rp_b = b.re; im_b = b.im; \
                     c.re = ( rp_a*rp_b + im_a*im_b ) \
                           /( rp_b*rp_b + im_b*im_b );\
                     c.im = ( im_a*rp_b - rp_a*im_b ) \
                           /( rp_b*rp_b + im_b*im_b )

# define cabs(b) ((float)sqrt((double)(b.re*b.re+b.im*b.im)))

# define cabs2(b) (float) (b.re*b.re+b.im*b.im)


/* Global definitions for fft computation  */

static     int *iBit;
static     float *twiddleReal, *twiddleImag;


/*-------------------------------------------------------------------------
 *  Cstore -- Computes Twiddle factors used in FFT Computation
 *    Args:	FFT size
 *    Returns:	Writes Twiddle factors to global arrays, 
 *              iBit, twiddleReal, twiddleImag
 *    Bugs:	
 * -------------------------------------------------------------------------*/
 void Cstore(int n)
 /*  int n;*/        /* FFT order */
 {
   int               nv2, nm1, ix, ix1, j, i, k;
   float             pi2byn;

   iBit = (int *) AllocIntArray(iBit, n+1);
   twiddleReal = (float *) AllocFloatArray(twiddleReal, n/2+1);
   twiddleImag = (float *) AllocFloatArray(twiddleImag, n/2+1);
   nv2 = n/2;
   nm1 = n-1;
   iBit[1] = 1;
   iBit[n] = n;
   ix = 0;
   for (i=2; i <= nm1; i++){
     j = 0;
     k = nv2;
     ix1 = ix;     
     while (ix1 >= k) { j = j+k; ix1 = ix1-k; k = k/2; };
     ix = ix + k - j;
     iBit[i] = ix + 1;
   };
   pi2byn = (float)(8.0*atan((double)1.0)/(double)n);
   for (i=1; i <= nv2; i++) {
     k = i-1;
     twiddleReal[i] = (float)cos((double)(pi2byn * k));
     twiddleImag[i] = (float)sin((double)(pi2byn * k));
   }
 }

/* ----------------------------------------------------------------------------


Cfft computes the FT of a complex signal.
        inputs - 
                a - complex signal of length n
                  n - FFT order
                m - m such that 2**m = n
                nsign -  -1  forward
                          1  inverse
        
        outputs - 
                 b - complex array of length n            

-----------------------------------------------------------------------------*/

void Cfft(complex *a, complex *b, int m, int n, int nsign)
{
  int                       nv2, nm1;
  int                       i, j, ip, k, le, le1, le2, l;
  static                    float log2; 
  static                    int flag = 0;
  complex                   u,t;

  if ((int)pow(2,m)!=n){
    printf("ERROR from Cfft: 2**m != n\n");
    _exit(1);
  }
  if (flag == 0) {
    log2 = log((double)2.0);
    flag = 1;
  } 
  nv2 = n/2;
  nm1 = n-1;
  for ( i=1; i<=n; i++ ) b[iBit[i]] = a[i]; 
  
  for ( i=1; i<=n; i+=2 )
    {
      ip = i+1;
      t = b[ip];
      csub( b[ip],b[i],t ); /* b[ip] = b[i] - t  */
      cadd( b[i],b[i],t );  /* b[i] = b[i] + t   */
    };
  
  for( i=1; i<=n; i+=4 )
    {
      ip = i+2;
      t = b[ip];
      csub( b[ip],b[i],t ); /* b[ip] = b[i] - t  */
      cadd( b[i],b[i],t );  /* b[i] = b[i] + t   */
    };

 for( i = 2; i <= n; i += 4 )
    {
     ip = i+2;
     t.re = -nsign * b[ip].im;
     t.im =  nsign * b[ip].re;
     csub( b[ip],b[i],t ); /* b[ip] = b[i] - t  */
     cadd( b[i],b[i],t );  /* b[i] = b[i] + t   */
    };

 for( l = 3; l <= m; l++ )
    {
     le2 = (int) (exp(log((double)2.0)*(m-l)) + 
		  (double)0.5);  /* le2 = 2**(m-l) */
     le = (int) (exp(log2*(double)l)+(double)0.5);   /* le = 2**l */
     le1 = le/2;
     for ( j = 1; j <= le1; j++ )
        {
         k = (j-1)*le2+1;
         u.re = twiddleReal[k];
         u.im = nsign*twiddleImag[k];
         for ( i = j; i <= n; i += le )
            {
             ip = i+le1;
             cmul(t,b[ip],u);   /*  t = b[ip]*u  */
             csub( b[ip],b[i],t ); /* b[ip] = b[i] - t  */
             cadd( b[i],b[i],t );  /* b[i] = b[i] + t   */
            };
        };
    };
 if(nsign==1) for ( i = 1; i <= n; i++ ) 
   { b[i].re=b[i].re/(float)n;
     b[i].im=b[i].im/(float)n; };
}


/**************************************************************************
 * $Log$
 *
 *                        End of FFT.c
 **************************************************************************/
