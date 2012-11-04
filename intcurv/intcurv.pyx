# vim: set expandtab:
# cython: profile=True

from libc.math cimport sin, cos
from sympy import Symbol, cos as s_cos, sin as s_sin
x=Symbol('x')
y=Symbol('y')
f=1.4+s_cos(x)+s_sin(y)
fxx=f.diff(x,2)
fyy=f.diff(y,2)

cpdef double curv(double f_x, double f_y):
#    subst=[(s_cos(x),cos(f_x)),(s_sin(y),sin(f_y))]
    subst=[(x,f_x),(y,f_y)]
    return fxx.subs(subst)+fyy.subs(subst)

def integral_curv(double xmin, double xmax, double ymin, double ymax, int xsteps, int ysteps):
    cdef int i
    cdef int j
    cdef double sum=0
    cdef double xstep=(xmax-xmin)/xsteps
    cdef double ystep=(ymax-ymin)/ysteps
    for i in xrange(xsteps):
        for j in xrange(ysteps):
            sum+=curv(xmin+i*xstep, ymin+j*ystep)*xstep*ystep
    return sum
