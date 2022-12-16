# CMakeList.txt : CMake project for PrettyNumberCounter, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.20)

project ("PrettyNumberCounter")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

string(REPLACE "-O2" "-O0" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
string(REPLACE "-O2" "-O0" CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")

add_executable (PrettyNumberCounter  "PrettyNumberCounter.h" "Main.cpp")

set_property(TARGET PrettyNumberCounter PROPERTY CXX_STANDARD 20)
