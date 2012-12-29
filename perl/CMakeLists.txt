include_directories(${PERL_INCLUDE_PATH})

set(CMAKE_SWIG_FLAGS "")
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR})

set(_target ctp-perl)
set(WRAPPER_FILES ../ctp.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)

swig_add_module(${_target} perl ${WRAPPER_FILES})
swig_link_libraries(${_target} ${PERL_LIBRARIES} ${CTP_LIBRARIES})
