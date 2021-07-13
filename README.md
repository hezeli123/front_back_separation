# Front back separation features
1. SWIG(Simplified Wrapper and Interface Generator, swig.org), Front and back ends separated by swig
2. APIs and specific function realization separated by factory mode
3. C++ realizes specific functions

# Demo
## python
cd api
swig -c++ -python -o worker_wrap.cxx worker.i
"#include "worker.h" -> "#include "api/worker.h"  in worker_wrap.cxx
cd ..
mv api/worker_wrap.cxx impl/
bazel build //impl:_worker.so

# Depends
test pass by using bazel 0.24.1 and gcc 7.3.1
SWIG: 4.0.2
python: 2.7
java:
