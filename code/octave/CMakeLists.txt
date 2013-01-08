include_directories(${OCTAVE_INCLUDE_DIRS})

set(CMAKE_SWIG_FLAGS "-Wall")
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR})

set(_target callback-octave)
set(WRAPPER_FILES ../callback.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)

swig_add_module(${_target} octave ${WRAPPER_FILES})
swig_link_libraries(${_target} ${OCTAVE_LIBRARIES})

set_target_properties(${SWIG_MODULE_${_target}_REAL_NAME} PROPERTIES OUTPUT_NAME "callback")
set_target_properties(${SWIG_MODULE_${_target}_REAL_NAME} PROPERTIES SUFFIX ".oct" PREFIX "")

execute_process(COMMAND octave-config --oct-site-dir OUTPUT_VARIABLE _oct_site_dir OUTPUT_STRIP_TRAILING_WHITESPACE)

install(TARGETS ${SWIG_MODULE_${_target}_REAL_NAME} DESTINATION ${_oct_site_dir})
