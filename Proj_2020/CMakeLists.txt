cmake_minimum_required(VERSION 3.15)
project(Proj_2020)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proj_2020 main.cpp Person.h Person.cpp Car.cpp Car.h Graph.cpp Graph.h MutablePriorityQueue.h BuildGraph.cpp BuildGraph.h UserInterface.cpp UserInterface.h)