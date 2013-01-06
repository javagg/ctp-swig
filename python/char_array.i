%typemap(in) (char **ARRAY, int SIZE) {
  if (PyList_Check($input)) {
    int size = PyList_Size($input);
    $2 = ($2_ltype)size;
    $1 = (char **) malloc((size+1)*sizeof(char *));
    int i = 0;
    for (i = 0; i < size; i++) {
      PyObject *o = PyList_GetItem($input,i);
      $1[i] = o;
    }
    $1[i] = 0;
  } else {
    $1 = 0; $2 = 0;
    %argument_fail(SWIG_TypeError, "char **ARRAY, int SIZE", $symname, $argnum);
  }
}

%typemap(freearg) (char **ARRAY, int SIZE) {
  free((char *)$1);
}
