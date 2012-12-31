include_directories(${RUBY_INCLUDE_DIRS})
set(CMAKE_SWIG_FLAGS -autorename -module ctp -prefix "freequant::")
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR})

set(_target ctp-ruby)
set(WRAPPER_FILES ../ctp.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)
swig_add_module(${_target} ruby ${WRAPPER_FILES})
swig_link_libraries(${_target} ${RUBY_LIBRARY} ${CTP_LIBRARIES})
