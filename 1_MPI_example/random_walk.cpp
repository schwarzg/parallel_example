#include<iostream>
#include<random>
#include<vector>
#include<time>
#include"random_walker.h"

int main(int argc,char* argv[])
{

	//Prepare parameters
	int t_max=100;
	int n_max=10000;
	std::normal_distribution<double> normal(0,1);
	
	//Initialize random walker and trajectory
	std::vector<double> x(t_max);
	std::vector<double> y(t_max);
	x[0]=0,	y[0]=0;
	int seed=0;
	random_walker rw(x[0],y[0],seed);	

	//Ensemble loop
	clock_t start=clock();
	for(int i=0;i<n_max;i++)
	{
		rw.reset(x[0],y[0]);		

		//Time step loop
		for(int t=1;t<t_max;t++)
		{
			rw.step(normal);
			x[t]=rw.x();
			y[t]=rw.y();
		
		}
	}
	clock_t end=clock();

	std::cout<<n_max<<" random walks - "
		<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<<std::endl;
	return 0;
}
