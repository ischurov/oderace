from scipy.integrate import odeint
from math import cos, pi
from time import time

def Xdot(x,t,eps):
   cosx=cos(x[0])
   cosy=cos(x[1])
   return [cosx+1.4+cosy,eps]

def docycle(iterates=1000, eps=0.1, prec=1.4E-8):
    for i in xrange(iterates):
	odeint(Xdot,[0,0],[0,2*pi/eps],args=(eps,), rtol=prec,atol=prec,mxstep=10000)

if __name__ == '__main__':
    timer=time()
    docycle()
    print "The time is: %f" %(time()-timer)

