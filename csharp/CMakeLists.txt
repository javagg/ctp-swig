if(MONO_FOUND)
    include(${MONO_USE_FILE})
    set(CS_COMPLIER ${MCS_EXECUTABLE})
elseif(CSharp_FOUND)
    set(CS_COMPLIER ${CSC_EXECUTABLE})
endif()

set(_target ctp-cs)
set(SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/src CACHE INTERNAL "")
set(BIN_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin CACHE INTERNAL "")
file(MAKE_DIRECTORY ${SRC_DIR})
file(MAKE_DIRECTORY ${BIN_DIR})
set(CMAKE_SWIG_OUTDIR ${SRC_DIR})

set(_namespace FreeQuant.Ctp)
set(CMAKE_SWIG_FLAGS "-namespace" ${_namespace})

set(WRAPPER_FILES ../ctp.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)
swig_add_module(${_target} csharp ${WRAPPER_FILES})
swig_link_libraries(${_target} ${CTP_LIBRARIES})

set(CS_SOURCES ${CMAKE_SWIG_OUTDIR}/*.cs)
set(BIN_FILE "ctp.dll")

add_custom_command(OUTPUT _ctp_cs_dll
    COMMENT "Creating cs dll..."
    COMMAND ${CS_COMPLIER} /nologo /target:library /out:${BIN_DIR}/${BIN_FILE} ${CS_SOURCES}
    DEPENDS ${_target}
)

add_custom_target(do_ctp_cs_dll ALL DEPENDS _ctp_cs_dll)
