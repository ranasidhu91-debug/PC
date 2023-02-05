#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
    int total = 0;
    int numbers[10];
    
    #pragma omp parallel for
    for (i = 0; i < 10; i++)
    {
        numbers[i] = i+1;
    }

    #pragma omp parallel for reduction (+:total)
    for (i = 0; i < 10; i++)
    {
        total += numbers[i];
    }
    printf("Total Sum:%d\n",total);
    return 0;
}