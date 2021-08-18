#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>


double *generateRandomMatrixOfSize(int size);

double *matrixOfZerosWithSize(int size);

int matrixMultiply(const double *const sourceA, 
    const double *const sourceB, 
    double *const destination, 
    const int size);

void printMatrix(const double *const m, const int size, const char *name);

double rtclock();


int main(int argc, const char* argv[])
{ 
 
    int m_size = atoi(argv[1]);
    double startTime, endTime, time;

    
    
    double * a = generateRandomMatrixOfSize(m_size);
    double * b = generateRandomMatrixOfSize(m_size);
    double * c = matrixOfZerosWithSize(m_size);
    

    //Register blocking NB = N
    
    
    
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
   int i,j,k;
    for( i = 0; i < size; ++i)
     {
       for( j = 0; j < size; ++j)
	{
	 for( k=0; k<size; ++k)
	   {
	     mult[(i*size)+j] += sourceA[(i*size)+k] * sourceB[(k*size)+j];
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

void printMatrix(const double *const m, const int size, const char *name)
{
  int i, j;
  printf("%s\n", name);
  for (i = 0; i < size; ++i) 
  {
    for (j = 0; j < size; ++j) 
    {
    printf("%.0f ", m[(i*size)+j]);
    }
    printf("\n");
  }
  printf("\n");
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

