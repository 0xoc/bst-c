cmake_minimum_required(VERSION 3.25)
project(bst C)

set(CMAKE_C_STANDARD 11)

add_executable(main.c bst.c bst.h)
