import multiprocess as mp

def introduce(rank):
	print("I am core "+rank)

mp.pool(5)


