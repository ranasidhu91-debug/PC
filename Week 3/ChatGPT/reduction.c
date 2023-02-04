#include <stdio.h>
#include <omp.h>

int main()
{
    int n = 10;
    int i;
    int sum = 0;
    int values[10];

    #pragma omp parallel for 
    for (i = 0; i < n; i++)
        {
            values[i] = i*i;
            printf("%dth iteration: Value:%d\n",i,values[i]);
        }
    #pragma omp parallel for reduction(+:sum)
    for ( i = 0; i < n; i++)
        {
            sum += values[i];
        }
    printf("Sum:%d\n",sum);
    return 0;
    
}