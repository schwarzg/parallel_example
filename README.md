Example of Parallel programming
===================
Time is the most important resources in our life. It is also important to us, graduate students in statistical physics communities, because our time to graduate is limited. However, we have too many computational jobs to generate reliable dataset. In order to reduce the time cost, we should use everything that we can use.

Parallel computing uses multiple computing resources at once to accelerate computation. The calculation efficiency improves since many cores participate in the computation at the same time. Although this technique is powerful, many collages feel hard to apply the methods on their work. So I decide to share my tips to start parallel programming. 

This repository provides the basic examples of parallel programming in c++ and python for statistical physics community. I choose some examples in which the statistical physicist may face frequently. I suggest the useful template and examples for each problems with various languague (usually, c++ and python). 

This repository will be slowly, but continuely updated. If you have comments or question on this repository, contact me 

<schwarzg1104@gmail.com>

Helpful reference to understand scheme briefly: [SamsungSDS](https://www.samsungsds.com/kr/story/1233713_4655.html)

# Initiation
This folder contains basic format of parallization libraries.

Massage passing interface libraries:

(C/C++)

[MPICH](https://www.mpich.org)

[openMPI](https://www.open-mpi.org)

(Python)

[mpi4py](https://mpi4py.readthedocs.io/en/stable/)

Simple examples, compile shell, running shells are included in this folder.

### C
Compile
	mpicc -o (execute) (source) (links)   
Run 
	mpiexec -n (number of cores) (execute)   

### C++
Compile
	mpic++ -o (execute) (source) (links)   
Run
	mpiexec -n (number of cores) (execute)   

### Python
Run
	 mpiexec -n (number of cores) python (execute)   

# MPI_example
This folder contains examples of parallization using Message passing interface (MPI). 

Sample example : two-dimensional random walk problem   
Parallelization type : data parallelize using MPI   

### C++
Compile
	mpic++ -o random_walk_MPI.x random_walk_MPI.cpp   
Run
	mpiexec -n (number of cores) ./random_walk_MPI.x   

### Python
Run
	mpiexec -n (number of cores) python3 random_walk_MPI.py

