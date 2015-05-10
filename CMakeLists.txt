cmake_minimum_required (VERSION 2.6)
project (erstat)

enable_testing()
SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

add_executable(erstat main.cpp interface.cpp)

add_test(NAME "SimpleRun" COMMAND erstat)
