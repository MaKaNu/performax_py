cmake_minimum_required(VERSION 3.4...3.18)
project(py_performax)

add_subdirectory(pybind11)
add_subdirectory(lib)

add_library(performax SHARED PerformaxCom.lib PerformaxCom.dll)

pybind11_add_module(py_performax src/main.cpp)
target_link_libraries(py_performax PRIVATE performax)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(py_performax
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})