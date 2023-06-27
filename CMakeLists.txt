cmake_minimum_required(VERSION 3.21)
project(Army)

set(CMAKE_CXX_STANDARD 20)

add_executable(Army main.cpp ARMY_INFO.h ARMY_INFO.cpp FORWARD_LIST.h FORWARD_LIST_ITERATOR.h FORWARD_LIST_NODE.h)
