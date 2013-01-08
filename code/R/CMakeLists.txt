include_directories(${R_INCLUDE_DIRS})

set(CMAKE_SWIG_FLAGS "")
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR})

set(_target callback-R)
set(WRAPPER_FILES ../callback.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)

swig_add_module(${_target} R ${WRAPPER_FILES})
swig_link_libraries(${_target} ${R_LIBRARIES})

set(REXT_DIR /home/alex/R/x86_64-pc-linux-gnu-library/2.15)
