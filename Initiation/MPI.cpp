#include<iostream>

#include<mpi.h>

int main(int argc,char* argv[])
{

	int nproc,rank=0;
	
	MPI_Init(&argc,&argv);
	//From here
	MPI_Comm_size(MPI_COMM_WORLD,&nproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	//All cores works separately
	std::cout<<"I am core "<<rank<<" of "<<nproc<<std::endl;
	
	//Until  here
	MPI_Finalize();

	return 0;
}
