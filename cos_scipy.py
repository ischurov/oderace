from scipy import cos
from time import time

def docycle(iterations=1000000): 
    #note that the default number of iterations is
    #100 times smaller then in cos.py and cos.cpp
    #as it takes too long

    for i in xrange(iterations):
	cos(i+0.1)

if __name__=='__main__':
    timer=time()
    docycle()
    print "The total time is %f" % (time()-timer)
