cmake_minimum_required(VERSION 3.28)
project(lab_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(lab_1
        src/Book.cpp
        src/Book.h
        src/CustomException.h
        src/Keeper.cpp
        src/Keeper.h
        src/main.cpp
        src/Stationery.cpp
        src/Stationery.h
        src/StoreItem.cpp
        src/StoreItem.h
        src/Textbook.cpp
        src/Textbook.h)
