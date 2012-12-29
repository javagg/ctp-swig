include_directories(${R_INCLUDE_DIRS})

set(CMAKE_SWIG_FLAGS "")
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR})

set(_target ctp-R)
set(WRAPPER_FILES ../ctp.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)

swig_add_module(${_target} R ${WRAPPER_FILES})
swig_link_libraries(${_target} ${R_LIBRARIES} ${CTP_LIBRARIES})
