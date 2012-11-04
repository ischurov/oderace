from math import cos
from time import time

def docycle(iterations=100000000):
    for i in xrange(iterations):
	cos(i+0.1)

if __name__=='__main__':
    timer=time()
    docycle()
    print "The total time is %f" % (time()-timer)
