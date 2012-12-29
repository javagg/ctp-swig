set(MONO_FOUND FALSE)

find_program(MONO_EXECUTABLE mono)
find_program(MCS_EXECUTABLE mcs)
find_program(GMCS_EXECUTABLE gmcs)
find_program(SMCS_EXECUTABLE smcs)
find_program(GACUTIL_EXECUTABLE gacutil)
find_program(ILASM_EXECUTABLE ilasm)
find_program(SN_EXECUTABLE sn)

if(MONO_EXECUTABLE AND MCS_EXECUTABLE)
    set(MONO_FOUND TRUE)
    execute_process(COMMAND ${MONO_EXECUTABLE} --version OUTPUT_VARIABLE MONO_VERSION_OUTPUT)
    string(REGEX MATCH "([0-9]*)([.])([0-9]*)([.]*)([0-9]*)" MONO_VERSION ${MONO_VERSION_OUTPUT})
endif()

if(NOT MONO_FOUND)
    if(NOT MONO_FIND_QUIETLY AND MONO_FIND_REQUIRED)
        message(FATAL_ERROR "MONO was not found. Please specify mono/mcs executable location")
    else()
        message(STATUS "MONO was not found. Please specify mono/mcs executable location")
    endif()
endif()

set(MONO_USE_FILE ${CMAKE_MODULE_PATH}/UseMono.cmake)

mark_as_advanced(MONO_EXECUTABLE MCS_EXECUTABLE GMCS_EXECUTABLE SMCS_EXECUTABLE ILASM_EXECUTABLE SN_EXECUTABLE GACUTIL_EXECUTABLE)
