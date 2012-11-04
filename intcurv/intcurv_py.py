from sympy import Symbol, cos as s_cos, sin as s_sin
from math import cos, sin

x=Symbol('x')
y=Symbol('y')
f=1.4+s_cos(x)+s_sin(y)
fxx=f.diff(x,2)
fyy=f.diff(y,2)

def curv(f_x, f_y):
    subst=[(s_cos(x),cos(f_x)),(s_sin(y),sin(f_y))]
#    subst=[(x,f_x),(y,f_y)]
    return fxx.subs(subst)+fyy.subs(subst)


def integral_curv(xmin,  xmax,  ymin,  ymax,  xsteps,  ysteps):
    sum=0
    xstep=(xmax-xmin)/xsteps
    ystep=(ymax-ymin)/ysteps
    for i in xrange(xsteps):
	for j in xrange(ysteps):
	    sum+=curv(xmin+i*xstep, ymin+j*ystep)*xstep*ystep
    return sum

