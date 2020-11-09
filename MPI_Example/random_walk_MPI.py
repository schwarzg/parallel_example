import numpy as np
import time

from random_walker import random_walker

tmax=1000
nmax=10000

start=time.time()

#MPI start when mpi4py is imported
from mpi4py import MPI

comm = MPI.COMM_WORLD
nproc = comm.Get_size()
rank = comm.Get_rank()

x_tr=[]
y_tr=[]
rw=random_walker(tmax,seed=1)
for i in range(rank,nmax,nproc):
	rw.reset()
	rw.run()
	x,y=rw.get_trajectory()	
	x_tr.append(x)
	y_tr.append(y)

end=time.time()
MPI.Barrier()
MPI.Finalize()
print(end-start)
'''
	Plotting routines
import matplotlib.pyplot as plt
for i in range(10):
	plt.plot(x_tr[i],y_tr[i],lw=1)
plt.xlabel(r"$x$ position")
plt.ylabel(r"$y$ position")
#plt.savefig("Random_work_trajectories.png",dpi=300,bbox_inches='tight')
plt.show()
'''
