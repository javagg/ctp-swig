if(MONO_FOUND)
    include(${MONO_USE_FILE})
    set(CS_COMPLIER ${MCS_EXECUTABLE})
elseif(CSharp_FOUND)
    set(CS_COMPLIER ${CSC_EXECUTABLE})
endif()

set(_target callback-cs)
set(SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/src)
set(CMAKE_SWIG_OUTDIR ${SRC_DIR})
file(MAKE_DIRECTORY ${SRC_DIR})

set(_namespace Swigmt)
set(CMAKE_SWIG_FLAGS "-namespace" ${_namespace} -dllimport ${_target})

set(WRAPPER_FILES ../callback.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)
swig_add_module(${_target} csharp ${WRAPPER_FILES})
swig_link_libraries(${_target})

file(COPY Runme.cs DESTINATION ${CMAKE_SWIG_OUTDIR})

set(CS_SOURCES "${CMAKE_SWIG_OUTDIR}/*.cs")
set(BIN_FILE "Runme.exe")

add_custom_command(
    OUTPUT _complie_runme
    COMMAND ${CS_COMPLIER} /nologo ${CS_SOURCES}
    DEPENDS ${_target}
)

add_custom_target(runcs ALL DEPENDS _complie_runme)
