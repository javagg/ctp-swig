# - Try to find Octave
# Once done this will define
#  OCTAVE_FOUND - System has octave
#  OCTAVE_INCLUDE_DIRS - The octave include directories
#  OCTAVE_LIBRARIES - The libraries needed to use octave

set(OCTAVE_FOUND FALSE)

execute_process(COMMAND octave-config -p OCTLIBDIR OUTPUT_VARIABLE OCTAVE_LIBDIR OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND octave-config -p OCTINCLUDEDIR OUTPUT_VARIABLE _INCDIR OUTPUT_STRIP_TRAILING_WHITESPACE)

find_path(OCTAVE_INCLUDE_DIR octave/oct.h PATHS ${_INCDIR} ${_INCDIR}/..)
find_library(OCTAVE_LIBRARY octave PATHS ${OCTAVE_LIBDIR} )

if(NOT (OCTAVE_INCLUDE_DIR AND OCTAVE_LIBRARY))
    if(OCTAVE_FIND_REQUIRED)
        message(FATAL_ERROR "OCTAVE required, please specify it's location.")
    else()
        message(STATUS "OCTAVE was not found.")
    endif()
elseif(OCTAVE_INCLUDE_DIR AND OCTAVE_LIBRARY)
    set(OCTAVE_FOUND TRUE)
endif()

list(APPEND OCTAVE_INCLUDE_DIRS ${OCTAVE_INCLUDE_DIR})
list(APPEND OCTAVE_LIBRARIES ${OCTAVE_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(liboctave DEFAULT_MSG OCTAVE_INCLUDE_DIRS OCTAVE_LIBRARIES)
mark_as_advanced(OCTAVE_INCLUDE_DIRS OCTAVE_LIBRARIES)


