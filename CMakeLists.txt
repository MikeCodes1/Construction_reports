cmake_minimum_required(VERSION 3.28)
project(Construction_reports)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(SOURCE_FILES main.cpp)

add_executable(Construction_reports main.cpp
        House.cpp
        House.h
        Contractor.cpp
        Contractor.h
        El_Paso.cpp
        El_Paso.h
        Temple.cpp
        Temple.h
        College_Station.cpp
        College_Station.h
        #[[testmain.cpp]])
