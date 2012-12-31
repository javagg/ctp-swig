include_directories(${JAVA_INCLUDE_PATH} ${JNI_INCLUDE_DIRS})
set(_package_name "org.freequant.ctp")
string(REPLACE "." "/" _package_dir ${_package_name})
set(_package_top_dir "org")
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR}/${_package_dir})
set(CMAKE_SWIG_FLAGS "-package" ${_package_name})
set(WRAPPER_FILES ../ctp.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)
swig_add_module(ctp java ${WRAPPER_FILES})
swig_link_libraries(ctp ${CTP_LIBRARIES})

set(SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/build)
file(MAKE_DIRECTORY ${SOURCE_DIR})
file(MAKE_DIRECTORY ${BINARY_DIR})

set(JAVA_SOURCES ${CMAKE_SWIG_OUTDIR}/*.java)
set(BIN_FILE "ctp.jar")
set(DOC_FILE "ctp-doc.jar")
set(SRC_FILE "ctp-src.jar")

foreach(_file ${CTP_SHAREDLIBFILES})
    file(COPY ${_file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    get_filename_component(_rfile ${_file} NAME)
    list(APPEND _ctpfiles ${_rfile})
endforeach()
get_target_property(_target_location ctp LOCATION)
get_filename_component(_target_name ${_target_location} NAME)

add_custom_command(OUTPUT _ctp_java_jar
    COMMENT "Creating jar file..."
    COMMAND ${Java_JAVAC_EXECUTABLE} -d ${BINARY_DIR} ${JAVA_SOURCES}
    COMMAND ${Java_JAR_EXECUTABLE} cf ${CMAKE_CURRENT_BINARY_DIR}/${BIN_FILE} -C ${BINARY_DIR} ${_package_top_dir}
    COMMAND ${Java_JAR_EXECUTABLE} uf ${CMAKE_CURRENT_BINARY_DIR}/${BIN_FILE} ${_ctpfiles} ${_target_name}
  #  COMMAND ${Java_JAVADOC_EXECUTABLE} -quiet -d ${BINARY_DIR}/javadoc -sourcepath ${SOURCE_DIR} ${_package_name}
  #  COMMAND ${Java_JAR_EXECUTABLE} cf ${CMAKE_CURRENT_BINARY_DIR}/${DOC_FILE} -C ${BINARY_DIR}/javadoc ${_package_top_dir}
    COMMAND ${Java_JAR_EXECUTABLE} cf ${CMAKE_CURRENT_BINARY_DIR}/${SRC_FILE} ${_package_top_dir}
    DEPENDS ctp
)

add_custom_target(do_ctp_java_jar ALL DEPENDS _ctp_java_jar)
