#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <mpi.h>

int main(int argc,char* argv[])
{
    int my_rank;
    int size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    int val = -1;
    double val2 = -1.0;
    do
    {
        if (my_rank == 0)
        {
            printf("Enter a round Number(>= 0) and a real number: ");
            fflush(stdout);
            scanf("%d%lf",&val,&val2);
        }
        MPI_Bcast(&val,1,MPI_INT,0,MPI_COMM_WORLD);
        MPI_Bcast(&val2,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
        printf("Processors: %d. Received Round Number: %d. Received Real Number: %lf\n", my_rank, val, val2);
        fflush(stdout);
    } while (val >= 0);

    MPI_Finalize();
    return 0;
}