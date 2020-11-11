#System setting
n_max=10000

#MPI start when mpi4py is imported
from mpi4py import MPI

comm = MPI.COMM_WORLD
nproc = comm.Get_size()
rank = comm.Get_rank()

#Ensemble loop - parallized
for i in range(rank,nmax,nproc):
	#Calculate here

#Finish MPI
MPI.COMM_WORLD.Barrier()
MPI.Finalize()
