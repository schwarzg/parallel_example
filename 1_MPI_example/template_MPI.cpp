#include<iostream>
#include<mpi.h>

int main(int argc,char* argv[])
{

	/*     MPI start    */
	int nproc,rank=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&nproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
	/*     System setting    */
	int n_ensemble;	
		
	//Ensemble loop - Parallelized!
	for ( int i = rank; i < n_ensemble; i += nproc )
	{
	
		/*     Calculate here    */

	
	}
	
	//MPI finish
	MPI_Finalize();
	return 0;
}
