include_directories(${RUBY_INCLUDE_DIRS})
set(CMAKE_SWIG_FLAGS -autorename)
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR})

set(_target ctp-ruby)
set(WRAPPER_FILES ../ctp.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)
swig_add_module(${_target} ruby ${WRAPPER_FILES})
swig_link_libraries(${_target} ${RUBY_LIBRARY} ${CTP_LIBRARIES})
set_target_properties(${_target} PROPERTIES PREFIX "" SUFFIX ".so")
set_target_properties(${_target} PROPERTIES OUTPUT_NAME "ctp")

execute_process(COMMAND ${RUBY_EXECUTABLE} -e "print RbConfig::CONFIG['sitearchdir']" OUTPUT_VARIABLE _ruby_site_dir)
install(TARGETS ${_target} DESTINATION ${_ruby_site_dir})

add_custom_command(
    OUTPUT runmd.rb
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/runmd.rb ${CMAKE_CURRENT_BINARY_DIR}/runmd.rb
    DEPENDS ${_target})
#add_custom_target(run ALL DEPENDS runmd.rb)

find_program(GEM_EXECUTABLE gem)
if(GEM_EXECUTABLE)
    add_custom_command(
        OUTPUT _make_and_install_gem
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/ctp.gemspec ${CMAKE_CURRENT_BINARY_DIR}/ctp.gemspec
#        COMMAND ${GEM_EXECUTABLE} build ${CMAKE_CURRENT_BINARY_DIR}/ctp.gemspec
#        COMMAND ${GEM_EXECUTABLE} install ctp-0.0.1-x86_64-linux.gem
        DEPENDS ${_target}
    )
endif()

add_custom_target(run ALL DEPENDS runmd.rb _make_and_install_gem)
