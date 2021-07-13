%module worker
%{
      #include "api/worker.h"
%}
%include <cpointer.i>
%pointer_functions(int, intp)
%include "std_string.i"
%include "api/worker.h"

