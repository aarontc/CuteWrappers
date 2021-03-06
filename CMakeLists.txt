project(CuteWrappers)
if(NOT DEFINED CuteWrappers_VERSION)
	find_package(Git)
	if(EXISTS ${GIT_EXECUTABLE})
		execute_process(COMMAND "${GIT_EXECUTABLE}"	describe --tags --abbrev=1
			RESULT_VARIABLE GIT_RESULT
			OUTPUT_VARIABLE CuteWrappers_VERSION
			WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
		)
		string(STRIP "${CuteWrappers_VERSION}" CuteWrappers_VERSION)
		if(NOT GIT_RESULT EQUAL 0)
			message(FATAL_ERROR "Cannot get 'git describe' version!")
		endif()
	else()
		message(FATAL_ERROR "No Git executable or valid Wireless Stickies version argument found.\nPlease pass a version to CMake e.g. cmake -DCuteWrappers_VERSION=1.0.0")
	endif()
endif()

string(REGEX MATCH "([0-9]+)\\.([0-9]+)\\.(.*)" CuteWrappers_VERSION "${CuteWrappers_VERSION}")
set(CuteWrappers_VERSION_MAJOR "${CMAKE_MATCH_1}")
set(CuteWrappers_VERSION_MINOR "${CMAKE_MATCH_2}")
set(CuteWrappers_VERSION_PATCH "${CMAKE_MATCH_3}")
set(CuteWrappers_VERSION_COUNT 3)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()



# Treat link_directories as relative
cmake_policy(SET CMP0015 NEW)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
find_package(Qt4 4.8.1 COMPONENTS QtCore REQUIRED)
include(UseQt4)
enable_testing()


# Allow the developer to select if Dynamic or Static libraries are built
option(BUILD_SHARED_LIBS "Build Shared Libraries" ON)
# Set the LIB_TYPE variable to STATIC
set(LIB_TYPE STATIC)
if(BUILD_SHARED_LIBS)
	# User wants to build Dynamic Libraries, so change the LIB_TYPE variable to CMake keyword 'SHARED'
	set(LIB_TYPE SHARED)
endif(BUILD_SHARED_LIBS)

message(STATUS "Building MadeByAI CuteWrappers ${CuteWrappers_VERSION} in ${CMAKE_BUILD_TYPE} mode, with ${LIB_TYPE} libraries" )


if(CMAKE_BUILD_TYPE MATCHES "^[Rr]elease$")
	add_definitions(-DQT_NO_DEBUG_OUTPUT)
else()
	message(WARNING	"Only build CuteWrappers in Debug mode if you are doing development!")
endif()



add_subdirectory(src)


# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND AND NOT Skip_Doxygen)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
	add_custom_target(Documentation ALL
		${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation with Doxygen" VERBATIM
	)
endif()
