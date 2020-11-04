import numpy as np
import time

class random_walker:
	def __init__(self,t_max,x_ini=0,y_ini=0,seed=None):
		self.t_max=t_max
		self.x_tr=np.zeros(t_max)
		self.y_tr=np.zeros(t_max)
		
		self.t_now=0
		self.x_tr[0]=x_ini
		self.y_tr[0]=y_ini
			
		if seed is None:
			rng=np.random.default_rng()
		else:
			rng=np.random.default_rng(seed)
		
		xyseeds=rng.integers(2**31,size=2)
		self.x_rng=np.random.default_rng(xyseeds[0])
		self.y_rng=np.random.default_rng(xyseeds[1])
		
		return

	def get_trajectory(self):
		return self.x_tr,self.y_tr

	def reset(self,x_ini=0,y_ini=0):
		self.t_now=0
		self.x_tr=np.zeros(self.t_max)
		self.y_tr=np.zeros(self.t_max)
		self.x_tr[0]=x_ini
		self.y_tr[0]=y_ini
		return

	def run(self,t_max=None):
		if self.t_now != 0:
			print("May be not initialized!")
			self.reset()
		if t_max is None:
			t_max=self.t_max
		x_dis=self.x_rng.standard_normal(t_max-1)
		y_dis=self.y_rng.standard_normal(t_max-1)
		#x_dis=np.random.normal(size=t_max-1)
		#y_dis=np.random.normal(size=t_max-1)
		for i in range(t_max-1):
			self.x_tr[self.t_now+1]=self.x_tr[self.t_now]+x_dis[self.t_now]
			self.y_tr[self.t_now+1]=self.y_tr[self.t_now]+y_dis[self.t_now]
			self.t_now=self.t_now+1
		
		return 
			

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
