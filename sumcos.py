from math import cos, pi, sqrt
from time import time

def docycle(iterations=10000, experiments=10000):
    step=pi*sqrt(2)
    for i in xrange(experiments):
	sum=0
	x=0
	for j in xrange(experiments):
	    x+=step
	    sum+=cos(x)

if __name__=='__main__':
    timer=time()
    docycle()
    print "Total time : %f" % (time()-timer)

	




