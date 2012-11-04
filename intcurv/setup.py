from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules=[
    Extension("intcurv",
              ["intcurv.pyx"],
              libraries=["m"]) # Unix-like specific
]

setup(
  name = "Integrate curvature benchmark",
  cmdclass = {"build_ext": build_ext},
  ext_modules = ext_modules
)

