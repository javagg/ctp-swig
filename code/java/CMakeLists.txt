include_directories(${JAVA_INCLUDE_PATH} ${JNI_INCLUDE_DIRS})

set(_package_name "swigmt")
set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR}/${_package_name})
set(CMAKE_SWIG_FLAGS "-package" ${_package_name})

set(WRAPPER_FILES ../callback.i)
set_source_files_properties(${WRAPPER_FILES} PROPERTIES CPLUSPLUS ON)
swig_add_module(callback-java java ${WRAPPER_FILES})
swig_link_libraries(callback-java)

set(SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/build)
file(MAKE_DIRECTORY ${SOURCE_DIR})
file(MAKE_DIRECTORY ${BINARY_DIR})

get_target_property(_target_location callback-java LOCATION)
get_filename_component(_target_name ${_target_location} NAME)

file(COPY Runme.java DESTINATION ${CMAKE_SWIG_OUTDIR})

set(BIN_FILE "callback.jar")

add_custom_command(OUTPUT _complie_java
    COMMAND ${Java_JAVAC_EXECUTABLE} -d ${BINARY_DIR} ${CMAKE_SWIG_OUTDIR}/*.java
    COMMAND ${Java_JAR_EXECUTABLE} cf ${CMAKE_CURRENT_BINARY_DIR}/${BIN_FILE} -C ${BINARY_DIR} swigmt
    COMMAND ${Java_JAR_EXECUTABLE} uf ${CMAKE_CURRENT_BINARY_DIR}/${BIN_FILE} ${_target_name}
  #  COMMAND ${Java_JAVADOC_EXECUTABLE} -quiet -d ${BINARY_DIR}/javadoc -sourcepath ${SOURCE_DIR} ${_package_name}
  #  COMMAND ${Java_JAR_EXECUTABLE} cf ${CMAKE_CURRENT_BINARY_DIR}/${DOC_FILE} -C ${BINARY_DIR}/javadoc ${_package_top_dir}
#    COMMAND ${Java_JAR_EXECUTABLE} cf ${CMAKE_CURRENT_BINARY_DIR}/${SRC_FILE} ${_package_top_dir}
    DEPENDS callback-java
)

add_custom_target(run ALL DEPENDS _complie_java)
