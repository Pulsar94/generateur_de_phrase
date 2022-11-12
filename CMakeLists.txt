cmake_minimum_required(VERSION 3.21)
project(Projet C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet main.c read.c read.h tree.c tree.h generator.c generator.h)
