#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>



void generateRandomMatrixOfSize(int firstMatrix[][100],
				 int secondMatrix[][100],
				 int size);
	      


void cachemultiplyMatrices(int firstMatrix[][100],
		      int secondMatrix[][100],
		      int multResult[][100],
		      int size,
		      int blocksize);


void display(int mult[][100], int size);

int main()
{
	int firstMatrix[100][100], secondMatrix[100][100], mult[100][100], size,blocksize, i, j, k;
	double starttime, endtime, elapsed;
	struct timeval start,end;

	printf("Enter size matrix: ");
	scanf("%d", &size);

	blocksize = 3;
	

	// Function to take matrices data
        generateRandomMatrixOfSize(firstMatrix, secondMatrix, size);

       // To start the time 
	starttime= gettimeofday(&start,NULL);

        // Function to multiply two matrices.
        for(int iter=0; iter<1000;iter++)
        {
        	cachemultiplyMatrices(firstMatrix, secondMatrix, mult, size, blocksize);
        }
        endtime= gettimeofday(&end, NULL);
        
        elapsed =((end.tv_sec*1000000.0 + end.tv_usec) - 
                  (start.tv_sec*1000000.0 + start.tv_usec)) / 1000000.00;
        
        
        // Function to display resultant matrix after multiplication.
       /* printf("first Matrix :\n");
        display(firstMatrix, size);
        printf("Second Matrix :\n");
        display(secondMatrix, size);
        printf("Result Matrix :\n");
        display(mult, size);*/

	printf("Elapsed time : %.3f\n", elapsed);
	return 0;
}

void generateRandomMatrixOfSize(int firstMatrix[][100], int secondMatrix[][100], int size)
{
	int i, j;
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{
			firstMatrix[i][j] = rand() % 100;
		}
	}

	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{
			secondMatrix[i][j] = rand() % 100;
		}
	}
}

void cachemultiplyMatrices(int firstMatrix[][100], int secondMatrix[][100], int mult[][100],int size, int bsize)
{
	int i, j, k,kk,jj,sum;
	
	for(i=0; i<size; i++)
	  { 
	    for(j=0; j< size ; j++)
	      {
	         mult[i][j] = 0;
	      }
	   }
	   
	
	for(kk=0; kk<size; kk+=bsize)
	 { 
	    for(jj=0; jj<size; jj+=bsize)
	      {
	        for(i=0; i<size ; i++)
	          {
	            for(j=jj; j<jj+bsize; j++)
	               {
	                  sum = mult[i][j];
	                   for(k=kk; k<kk+bsize ; k++)
	                     {
	                       sum = sum+firstMatrix[i][k] *secondMatrix[k][j];
	                     }
	                   mult[i][j] = sum;
	                }
	            }
	        }
	    }
	   	
}

void display(int mult[][100], int size)
{
	int i, j;
	printf("\nOutput Matrix:\n");
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{ 
			printf("%d\t  ", mult[i][j]);
			
		}
	   printf("\n");
	}
}
