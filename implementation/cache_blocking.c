#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>



double *generateRandomMatrixOfSize(int size);

double *matrixOfZerosWithSize(int size);

int matrixMultiply(const double *const sourceA, 
    const double *const sourceB, 
    double *const destination, 
    const int size);
    
double rtclock();

int main(int argc, const char* argv[])
{
  
  
  
    int m_size = atoi(argv[1]);
    double startTime = 0, endTime = 0, time;

    double * a = generateRandomMatrixOfSize(m_size);
    double * b = generateRandomMatrixOfSize(m_size);
    double * c = matrixOfZerosWithSize(m_size);

     startTime = rtclock();
      matrixMultiply(a, b, c, m_size);
      endTime = rtclock();
    
    time = endTime - startTime;

    printf("Size: %d\n", m_size);
    printf("Time: %0.02f\n", time);
    

    

    //Free all memory used
    free(a);
    free(b);
    free(c);   

    
 
}

int matrixMultiply(const double *const sourceA, 
                   const double *const sourceB, 
                   double *const mult, 
                   const int size)
{
  int i, j, k,kk,jj,sum,bsize=size;
	
	for(kk=0; kk<size; kk+=bsize)
	 { 
	    for(jj=0; jj<size; jj+=bsize)
	      {
	        for(i=0; i<size ; i++)
	          {
	            for(j=jj; j<jj+bsize; j++)
	               {
	                  sum = mult[(i*size)+j];
	                   for(k=kk; k<kk+bsize ; k++)
	                     {
	                       sum = sum+sourceA[(i*size)+k] *sourceB[(k*size)+j];
	                     }
	                   mult[(i*size)+j] = sum;
	                }
	            }
	        }
	    }
}

/**
 * Helper Methods
 */

double *generateRandomMatrixOfSize(int size)
{
  int i, j;
  double *m = (double*) malloc(size*size*sizeof(double));
  for (i = 0; i < size; ++i)
    for (j = 0; j < size; ++j)
      m[(i*size)+j] = rand() % 100;
  
  return m;
}

double *matrixOfZerosWithSize(int size)
{
  int i, j;
  double *m = (double*) malloc(size*size*sizeof(double));
  for (i = 0; i < size; ++i)
    for (j = 0; j < size; ++j)
      m[(i*size)+j] = 0.0;
  
  return m;
}



double rtclock()
{
  struct timezone Tzp;
  struct timeval Tp;
  int stat;
  stat = gettimeofday (&Tp, &Tzp);
  if (stat != 0) printf("Error return from gettimeofday: %d",stat);
  return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}


