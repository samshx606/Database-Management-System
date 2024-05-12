cmake_minimum_required(VERSION 3.28)
project(DS_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(DS_Project main.cpp
        Employee.h
        LinkedList.h
        tools.h
        Employee_Manger.h
)
