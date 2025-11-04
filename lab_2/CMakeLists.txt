cmake_minimum_required(VERSION 3.28)
project(lab_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(lab_2
        include/CustomException.h
        include/Train.h
        include/TrainSchedule.h
        src/main.cpp
        src/main_task1.cpp
        src/main_task2.cpp
        src/Train.cpp
        src/TrainSchedule.cpp)
