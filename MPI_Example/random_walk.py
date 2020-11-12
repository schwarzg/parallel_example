import numpy as np
import time
import matplotlib.pyplot as plt
from random_walker import random_walker

tmax=1000
nmax=10000

start=time.time()
x_tr=[]
y_tr=[]
rw=random_walker(tmax,seed=1)
for i in range(nmax):
	rw.reset()
	rw.run()
	x,y=rw.get_trajectory()	
	x_tr.append(x)
	y_tr.append(y)

end=time.time()
print("Serial code takes ",end-start," seconds!")
'''
	Plotting routines
'''
import matplotlib.pyplot as plt
for i in range(10):
	plt.plot(x_tr[i],y_tr[i],lw=1)
plt.xlabel(r"$x$ position")
plt.ylabel(r"$y$ position")
#plt.savefig("Random_work_trajectories.png",dpi=300,bbox_inches='tight')
plt.show()
