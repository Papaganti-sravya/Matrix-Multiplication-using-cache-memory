#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>



void generateRandomMatrixOfSize(int firstMatrix[][500],
				 int secondMatrix[][500],
				 int size);
	      


void multiplyMatrices(int firstMatrix[][500],
		      int secondMatrix[][500],
		      int multResult[][500],
		      int size);


void display(int mult[][500], int size);

int main()
{
	int firstMatrix[500][500], secondMatrix[500][500], mult[500][500], size, i, j, k;
	double starttime, endtime, elapsed;
	struct timeval start,end;

	printf("Enter size matrix: ");
	scanf("%d", &size);


	

	// Function to take matrices data
        generateRandomMatrixOfSize(firstMatrix, secondMatrix, size);

       // To start the time 
	starttime= gettimeofday(&start,NULL);

        // Function to multiply two matrices.
        for(int i=0; i<1000; i++)
        {
        	multiplyMatrices(firstMatrix, secondMatrix, mult, size);
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

	printf("Elapsed time kji: %.3f\n", elapsed);
	return 0;
}

void generateRandomMatrixOfSize(int firstMatrix[][500], int secondMatrix[][500], int size)
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

void multiplyMatrices(int firstMatrix[][500], int secondMatrix[][500], int mult[][500],int size)
{
	int i, j, k;

	// Initializing elements of matrix mult to 0.
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{
			mult[i][j] = 0;
		}
	}

	// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
	for(k = 0; k < size; k++)
	{
		for(j = 0; j < size; j++)
		{
			for(i=0; i<size;i++)
			{
				mult[i][j] += firstMatrix[k][j] * secondMatrix[i][k];
			}
		}
	}
}

void display(int mult[][500], int size)
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
