include(FindPackageHandleStandardArgs)

if(WIN32)
    find_program(MAVEN_EXECUTABLE NAMES mvn.bat)
else()
    find_program(MAVEN_EXECUTABLE NAMES mvn)
endif()

find_package_handle_standard_args(Maven DEFAULT_MSG MAVEN_EXECUTABLE)
mark_as_advanced(MAVEN_EXECUTABLE)
