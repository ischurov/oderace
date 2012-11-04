Some ODE solvers benchmarks

== The testcase ==

The following differential equation is used as a testcase:

x'=cos(x)+cos(y)+a,

y'=eps,

where a=1.4

If eps is small, it is an example of the so-called slow-fast equation. One is interested in the Poincare map from x=0 to x=2pi (so the time is 2pi/eps).

== Implementations ==

=== rk_c ===

rk_c.cpp is a simple C++ implementation of RK4 method (see http://en.wikipedia.org/wiki/Runge-Kutta for details). 

g++ rk_c.cpp -o rk_c && ./rk_c

Note that only 'wall time' is calculated.

=== odeint ===

odeint_py.py uses scipy.integrate.odeint method which is based on LSODE solver.

One can use odeint_py.py as a standalone executable

python ./odeint_py.py

Or as a module. E.g. with isympy:

In [2]: from odeint_py import docycle

In [3]: time docycle(10)

CPU times: user 0.13 s, sys: 0.01 s, total: 0.14 s
Wall time: 0.13 s

=== Contacts ===

More details: http://ivoyager.livejournal.com/tag/oderace

More contacts: http://ilya.schurov.com/

