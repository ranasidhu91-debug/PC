#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <mpi.h>

struct Valuestruct
{
    int a;
    double b;
};

int main(int argc, char** argv)
{
    struct Valuestruct values;
    int my_rank;
    MPI_Datatype Valuetype;
    MPI_Datatype type[2] = {MPI_INT,MPI_DOUBLE}; //specify the number of type
    int blocklen[2] = {1,1};// defines the number of elements in the Valuestruct
    MPI_Aint disp[2]; // this mpi stores addresses,each element of struct

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    MPI_Get_address(&values.a,&disp[0]);
    MPI_Get_address(&values.b,&disp[1]);

    disp[1] = disp[1] - disp[0];
    disp[0] = 0;

    MPI_Type_create_struct(2,blocklen,disp,type,&Valuetype);
    MPI_Type_commit(&Valuetype);

    do
    {
        if (my_rank == 0)
        {
            printf("Enter a round number (>=0) and a real number: ");
            fflush(stdout);
            scanf("%d%lf",&values.a,&values.b);
        }
        MPI_Bcast(&values,2,Valuetype,0,MPI_COMM_WORLD);
        printf("Rank: %d. values.a = %d. values.b = %lf\n", my_rank, values.a, values.b);
        fflush(stdout);
    } while (values.a >= 0);

    MPI_Type_free(&Valuetype);
    MPI_Finalize();
    return 0;
}