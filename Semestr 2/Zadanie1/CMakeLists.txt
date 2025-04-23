cmake_minimum_required(VERSION 3.26)
project(Zadanie1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Zadanie1 main.cpp
        setSimple.h
        SortedList.h
        setLinked.h
        A_complexity.cpp
        dictionarySimple.h)
