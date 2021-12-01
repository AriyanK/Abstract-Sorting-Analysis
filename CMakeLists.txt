cmake_minimum_required(VERSION 3.16)
project(AbstractSorting)

set(EXE_NAME AbstractSorting)
set(default_build_type "Release")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(AbstractSorting main.cpp DSVector.h AVLTree.h AVLTree.cpp DSList.h DSListNode.h Runner.cpp Runner.h Algorithms.h)
