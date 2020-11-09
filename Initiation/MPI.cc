#include<stdio.h>

#include<mpi.h>

int main(int argc,char* argv[])
{

	int nproc,rank=0;
	
	MPI_Init(&argc,&argv);
	//From here
	MPI_Comm_size(MPI_COMM_WORLD,&nproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	//All cores works separately
	printf("I am core %d of %d\n",rank,nproc);
	
	//Until  here
	MPI_Finalize();

	return 0;
}
