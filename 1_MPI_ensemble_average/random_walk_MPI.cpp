#include<iostream>
#include<random>
#include<vector>
#include<mpi.h>

#include"random_walker.h"

int main(int argc,char* argv[])
{

	//MPI start
	int nproc,rank=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&nproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	std::cout<<nproc<<" "<<rank<<std::endl;
	
	//Prepare parameters
	int t_max=100;
	int n_max=10000;
	std::normal_distribution<double> normal(0,1);
	
	//Initialize random walker and trajectory
	std::vector<double> x(t_max);
	std::vector<double> y(t_max);
	x[0]=0;
	y[0]=0;
	random_walker rw(x[0],y[0],rank);	
		
	//Ensemble loop
	for(int i=rank;i<n_max;i+=nproc)
	{
		rw.reset(x[0],y[0]);		
		std::cout<<i<<std::endl;
		//Time step loop
		for(int t=1;t<t_max;t++)
		{
			rw.step(normal);
			x[t]=rw.x();
			y[t]=rw.y();
		
		}
	}
	MPI_Finalize();
	return 0;
}
