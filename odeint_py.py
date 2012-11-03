from scipy.integrate import odeint
from math import cos, pi

def Xdot(x,t,eps):
   cosx=cos(x[0])
   cosy=cos(x[1])
   return [cosx+1.4+cosy,eps]

eps=0.01
prec=1.4E-8
trajpoints=100

def docycle(iterations):
    for i in xrange(iterations):
	odeint(Xdot,[0,0],[0,2*pi/eps],args=(eps,), rtol=prec,atol=prec,mxstep=10000)


