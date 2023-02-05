#include <stdio.h>
#include <omp.h>
#include<math.h>
#include<stdbool.h>
#include <time.h>
#define N 100

int main()
{
    struct timespec start, end, start_s, end_s;
    double time_taken_parallel;
    double time_taken_serial;
    int dotProduct = 0;
    int a[N],b[N];
    int c[N],d[N];

    clock_gettime(CLOCK_MONOTONIC, &start_s); 
    #pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = i*3;
    }
    clock_gettime(CLOCK_MONOTONIC, &end_s);
    time_taken_parallel = (end_s.tv_sec - start_s.tv_sec) * 1e9; 

    printf("Parallel Time: %lf\n", time_taken_parallel);
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < N; i++)
    {
        c[i] = i;
        d[i] = i*3;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken_serial = (end.tv_sec - start.tv_sec) *1e9;
    printf("Processing time (non-parallelizable)(Read)(s): %lf\n", time_taken_serial);
    // #pragma omp parallel for reduction(+:dotProduct)
    // for (int i = 0; i < N; i++)
    // {
    //     dotProduct += a[i] * b[i];
    // }

    printf("Dot Product is:%d\n",dotProduct);
    fflush(stdout);
    return 0;
}