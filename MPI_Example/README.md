Example 1
==============

# 2D random walk

	x(t+dt)=x(t)+\delta x(t) 
	y(t+dt)=y(t)+\delta y(t)

calculate 10000 random trajectory for 10000 time steps 

### C++

	template_MPI.cpp   
Provide example of embrassingly parallelization

	random_walk.cpp
Serial code to generate random walk trajectories

	random_walker.h
Header file constain random walker class

	random_walk_MPI.cppp
Parallelized code to generate random wakl trajectories

### Python

	template_MPI.py
Provide example of embrassingly parallelization

	random_walker.py
Contain random walker class

	random_walk.py
Serial code to generate random walk trajectories

	random_walker_MPI.py
MPI parallelized code to generate random walk trajectoires
