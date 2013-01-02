cmake_minimum_required(VERSION 2.8)
project(ctp-swig)

set(BUILD_SHARED_LIBS true)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_VERBOSE_MAKEFILE true)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

if(WIN32)
    set(CTP_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/ctp/api/trade/win/public)
    set(CTP_LIBRARY_DIRS ${PROJECT_SOURCE_DIR}/ctp/api/trade/win/lib ${PROJECT_SOURCE_DIR}/ctp/api/risk/lib)
elseif(UNIX)
    set(CTP_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/ctp/api/trade/linux64/public)
    set(CTP_LIBRARY_DIRS ${PROJECT_SOURCE_DIR}/ctp/api/trade/linux64/lib)
endif()

if(WIN32)
    find_library(CTP_MDUSER_LIBRARY NAMES thostmduserapi PATHS ${CTP_LIBRARY_DIRS})
    find_library(CTP_TRADE_LIBRARY NAMES thosttraderapi PATHS ${CTP_LIBRARY_DIRS})
    find_library(CTP_RISK_LIBRARY NAMES riskuserapi PATHS ${CTP_LIBRARY_DIRS})
    if(CTP_MDUSER_LIBRARY AND CTP_TRADE_LIBRARY AND CTP_RISK_LIBRARY)
        set(CTP_LIBRARIES ${CTP_MDUSER_LIBRARY} ${CTP_TRADE_LIBRARY} ${CTP_RISK_LIBRARY})
        set(CTP_SHAREDLIBFILES ${PROJECT_SOURCE_DIR}/ctp/api/risk/lib/riskuserapi.dll
            ${PROJECT_SOURCE_DIR}/ctp/api/trade/win/lib/thostmduserapi.dll
            ${PROJECT_SOURCE_DIR}/ctp/api/trade/win/lib/thosttraderapi.dll
        )
    endif()
elseif(UNIX)
    find_library(CTP_MDUSER_LIBRARY thostmduserapi PATHS ${CTP_LIBRARY_DIRS})
    find_library(CTP_TRADE_LIBRARY thosttraderapi PATHS ${CTP_LIBRARY_DIRS})
    if(CTP_MDUSER_LIBRARY AND CTP_TRADE_LIBRARY)
        set(CTP_LIBRARIES ${CTP_MDUSER_LIBRARY} ${CTP_TRADE_LIBRARY})
        set(CTP_SHAREDLIBFILES ${CTP_LIBRARIES})
    endif()
endif()
include_directories(${CTP_INCLUDE_DIRS})

find_package(SWIG REQUIRED)
if(SWIG_FOUND)
    include(${SWIG_USE_FILE})
    find_package(Java)
    find_package(JNI)
    find_package(Ruby)
    find_package(PythonInterp)
    find_package(PythonLibs)
    find_package(R)
    find_package(CSharp)
    find_package(Mono)
    # use $ENV{LUA_DIR}
    find_package(Lua51)
    find_package(PerlLibs)
    find_package(TCL)
    find_package(Octave)

    if(JNI_FOUND)
#        add_subdirectory(java)
    endif()

    if(RUBY_FOUND)
        add_subdirectory(ruby)
    endif(RUBY_FOUND)

    if(R_FOUND)
#        add_subdirectory(R)
    endif(R_FOUND)

    if(PYTHONLIBS_FOUND)
        add_subdirectory(python)
    endif(PYTHONLIBS_FOUND)

    if(CSharp_FOUND OR MONO_FOUND)
#        add_subdirectory(csharp)
    endif()

    if(LUA51_FOUND)
        add_subdirectory(lua)
    endif(LUA51_FOUND)

    if(TCL_FOUND)
#        add_subdirectory(tcl)
    endif(TCL_FOUND)

    if(PERLLIBS_FOUND)
#        add_subdirectory(perl)
    endif(PERLLIBS_FOUND)

    if(OCTAVE_FOUND)
#        add_subdirectory(octave)
    endif(OCTAVE_FOUND)
endif()

add_subdirectory(test)
