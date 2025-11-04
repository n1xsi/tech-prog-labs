cmake_minimum_required(VERSION 3.28)
project(lab_1)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск всех исходных файлов в "src"
file(GLOB SOURCES "src/*.cpp")

# Создание исполняемого файла из исходников
add_executable(lab_1 ${SOURCES})

# Поиск заголовочных файлов в "include"
target_include_directories(lab_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)