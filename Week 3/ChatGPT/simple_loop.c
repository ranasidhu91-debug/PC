#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
    int total = 0;

    #pragma omp parallel
    {
        int lSum = 0;
        #pragma omp for
        {
            for (i = 0; i < 20; i++)
            {
                lSum += i;
            }
        }
        total += lSum;
    }

    printf("Total:%d\n",total);
    return 0;
}