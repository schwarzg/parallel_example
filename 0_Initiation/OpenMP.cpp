#include<iostream>
#include<omp.h>
int main(int argc,char* argv[])
{
	#pragma omp parallel 
	{
		int thid=omp_get_thread_num();	
		#pragma omp for
		for (int i=0;i<10;i++)
		{
			std::cout<<"Thread "<< thid<<" is working on!"<<std::endl;
		}
	}
	
	return 0;
}
