cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

# set the project name
project(project1)

# add the executable
add_executable(
	final
	testfinal.cpp
)