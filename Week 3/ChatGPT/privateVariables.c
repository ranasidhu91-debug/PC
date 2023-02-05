#include <stdio.h>
#include <omp.h>
#define SIZE 100

int main()
{
    int i;
    int sum;
    int average;

    int numbers[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = i;
    }

    #pragma omp parallel private(i,sum)
    {
        #pragma omp for
        for (int i = 0; i < SIZE; i++)
        {
            sum += numbers[i];

        }
        printf("Sum is:%d\n",sum);
        fflush(stdout);

        #pragma omp critical
        {
            average += (sum/SIZE);
        }
        
    }
    printf("Average is %d\n",average);
    fflush(stdout);
    return 0;
}