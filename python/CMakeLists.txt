include_directories(${PYTHON_INCLUDE_DIRS})
set(CMAKE_SWIG_FLAGS -features autodoc=1 -keyword)
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR})

set(_target ctp-python)
set(WRAPPER_FILES ../ctp.i)

set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)
swig_add_module(${_target} python ${WRAPPER_FILES})
swig_link_libraries(${_target} ${PYTHON_LIBRARIES} ${CTP_LIBRARIES})
