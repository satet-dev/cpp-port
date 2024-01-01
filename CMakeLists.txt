cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
project(hello VERSION 1.0.0 LANGUAGES C CXX)

# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)  # Includes the contents of the conanbuildinfo.cmake file.
# conan_basic_setup()

# set(CMAKE_CXX_STANDARD 17) # using 17 since it is recommended for ZXing-CPP

add_library(hello SHARED hello.cpp)
add_executable(libhello hello.cpp) # adding my file to be built as an executable

# target_link_libraries(libhello ${CONAN_LIBS}) # used in Conan package manager

find_package(ZXing REQUIRED) # used when installed on local machine
target_link_libraries(libhello PUBLIC ZXing) # linked via local machine

# I tried using add_subdirectory and linkers, but that didn't work as well.
# I've omitted that code here, but it's pretty trivial.

# set_target_properties(hello PROPERTIES
#     PUBLIC_HEADER hello.h
#     VERSION ${PROJECT_VERSION}
#     SOVERSION 1
#     OUTPUT_NAME "hello"
#     XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
# )