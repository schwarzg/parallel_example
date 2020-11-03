#include<iostream>

int main(int argc,char* argv[])
{
	#pragma omp parallel
	{
		std::cout<<thid<<" is working on!"<<std::endl;

	}

	return 0;
}
