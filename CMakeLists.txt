cmake_minimum_required(VERSION 3.21)
project(generateur_de_phrase C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(generateur_de_phrase
        generator.c
        generator.h
        main.c
        read.c
        read.h
        tree.c
        tree.h
        tree_research.c
        tree_research.h flech.c flech.h)
