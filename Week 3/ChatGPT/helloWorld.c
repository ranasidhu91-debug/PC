#include <stdio.h>
#include <omp.h>


int main()
{
    int number = omp_get_num_threads();
    printf("Number of threads:%d\n",number);
    fflush(stdout);
    #pragma omp parallel for
    for (int i = 0; i < number; i++)
    {
        printf("Hello World from thread %d\n",number);
    }
    
    return 0;
}