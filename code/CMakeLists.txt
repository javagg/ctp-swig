set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_executable(tCallback Main.cpp Callback.cpp)
add_library(callback Callback.cpp)
include_directories(.)

find_package(SWIG REQUIRED)
if(SWIG_FOUND)
    include(${SWIG_USE_FILE})
    find_package(Java)
    find_package(JNI)
    find_package(Ruby)
#    find_package(PythonInterp)
#    find_package(PythonLibs 2.7)
    find_package(R)
    find_package(CSharp)
    find_package(Mono)
    # use $ENV{LUA_DIR}
    find_package(Lua51)
    find_package(PerlLibs)
    find_package(TCL)
    find_package(Octave)

    if(CSharp_FOUND OR MONO_FOUND)
        add_subdirectory(csharp)
    endif()

    if(JNI_FOUND)
#        add_subdirectory(java)
    endif()

    if(RUBY_FOUND)
#        add_subdirectory(ruby)
    endif(RUBY_FOUND)

    if(PYTHONINTERP_FOUND AND PYTHONLIBS_FOUND)
#        add_subdirectory(python)
    endif()
endif()
