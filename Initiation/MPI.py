from mpi4py import MPI
#MPI initiated from import of mpi4py

comm = MPI.COMM_WORLD
nproc = comm.Get_size()
rank = comm.Get_rank()

print("I am %d of %d"%(nproc,rank))

comm.Barrier()
MPI.Finalize()
#MPI Finalized and run serial code sequentially.

#Or not, MPI finish at the end of program automatically
