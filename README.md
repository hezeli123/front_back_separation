# Front back separation features
1. SWIG(Simplified Wrapper and Interface Generator, swig.org), Front and back ends separated by swig
2. APIs and specific function realization separated by factory mode
3. C++ realizes specific functions
4. SWIG: std::string& and void* is solved trickly.
5. Class Registration mechanism.

# Demo

## python
1. swig -c++ -python -o worker_wrap.cxx worker.i
2. mv api/worker_wrap.cxx impl/
3. bazel build //impl:_worker.so
4. mv bazel-bin/impl/_worker.so ./
5. python python_test.py

## java
1. swig -c++ -java -package com.simple.front_back_separation -o java_simple_worker.cxx -outdir ./java_swig/ worker.i
2. mv java_simple_worker.cxx impl/
3. modify WORKSPACE for java headers dir, and impl/BUILD
4. bazel build //impl:java_worker.so
5. mv bazel-bin/impl/java_worker.so ./
6. test ...

# Depends
test pass by using bazel 0.24.1 and gcc 7.3.1
SWIG: 4.0.2
python: 2.7
java: 1.6.0_25
