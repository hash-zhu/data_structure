cmake_minimum_required(VERSION 3.19)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structure main.cpp SqStack.h SqList.h BinarySortTree.h SequetailList.h PAT/B1001.cpp)
add_executable(B1001 PAT/B1001.cpp)
add_executable(B1032 PAT/B1032.cpp)
add_executable(C1934 PAT/C1934.cpp)
add_executable(Sort PAT/Sort.cpp)