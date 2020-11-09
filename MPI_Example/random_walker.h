#include<iostream>
#include<random>
#include<vector>

class random_walker
{
public:
	random_walker(double& x_ini,double& y_ini,int seed):_x(x_ini),_y(y_ini)
	{
		set_seed(seed);
	}

	void set_seed(int& seed)
	{
		_mt_x.seed(seed);	
		_mt_y.seed(seed+1);	
	}

	void reset(double& x_ini,double& y_ini)
	{
		_x=x_ini;
		_y=y_ini;	
	}

	void step(std::normal_distribution<double>& step_size)
	{
		_x+=step_size(_mt_x);
		_y+=step_size(_mt_y);	
	}

	double x(){ return _x;}
	double y(){ return _y;}
	
private:
	//interal state
	double _x;
	double _y;
	std::mt19937 _mt_x;
	std::mt19937 _mt_y;
};

