#include<iostream>
#include<random>
#include<vector>

#include"random_walker.h"

int main(int argc,char* argv[])
{

	//Prepare parameters
	int t_max=100;
	int n_max=5;//0000;
	std::normal_distribution<double> normal(0,1);
	
	//Initialize random walker and trajectory
	std::vector<double> x(t_max);
	std::vector<double> y(t_max);
	x[0]=0;
	y[0]=0;
	int seed=0;
	random_walker rw(x[0],y[0],seed);	
		
	//Prepare gnuplot_related
	//Gnuplot gp;

	//Ensemble loop
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
/*
		//Plot trajectory
		if(i==0)
			gp << "plot '-' title 'rand' w l \n";
		else
			gp << "replot '-' title 'rand' w l \n";
		gp.send1d(boost::make_tuple(x,y));
*/
	}
	return 0;
}
