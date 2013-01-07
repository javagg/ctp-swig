%typemap(in) (char **ARRAY, int SIZE) {
  if (PyList_Check($input)) {
    int i = 0;
    $2 = PyList_Size($input);
    $1 = (char **)malloc(($2+1)*sizeof(char *));
    for (; i < $2; i++) {
      PyObject *o = PyList_GetItem($input,i);
      if (PyString_Check(o))
	$1[i] = PyString_AsString(PyList_GetItem($input,i));
      else {
	PyErr_SetString(PyExc_TypeError,"list must contain strings");
	free($1);
	return NULL;
      }
    }
    $1[i] = 0;
  } else {
    PyErr_SetString(PyExc_TypeError, "not a list");
    return NULL;
  }
}

%typemap(freearg) (char **ARRAY, int SIZE) {
  free((char *)$1);
}
