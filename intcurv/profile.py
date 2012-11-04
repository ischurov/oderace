#!/usr/bin/env python
# encoding: utf-8
# filename: profile.py

import pstats, cProfile

import pyximport
pyximport.install()

import intcurv_py

cProfile.runctx("intcurv_py.integral_curv(0,1,0,1,300,300)", globals(), locals(), "Profile.prof")

print "Pure python version"

s = pstats.Stats("Profile.prof")
s.strip_dirs().sort_stats("time").print_stats()

import intcurv
cProfile.runctx("intcurv.integral_curv(0,1,0,1,300,300)", globals(), locals(), "Profile.prof")

print "Cython version"

s = pstats.Stats("Profile.prof")
s.strip_dirs().sort_stats("time").print_stats()
