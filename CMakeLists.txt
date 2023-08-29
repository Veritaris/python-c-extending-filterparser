cmake_minimum_required(VERSION 3.20)
project(filterparser C)

set(CMAKE_C_STANDARD 11)

add_library(
        filterparser
        library.c
        struct.c
)
find_package(PythonInterp 3.10 REQUIRED)
find_package(PythonLibs 3.10 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(filterparser ${PYTHON_LIBRARIES})
