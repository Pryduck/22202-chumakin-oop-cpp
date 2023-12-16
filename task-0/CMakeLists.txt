cmake_minimum_required(VERSION 3.26)
project(task_0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Google_tests)
add_executable(task_0 main.cpp
        Parser.h
        Parser.cpp
        FileReader.h
        FileReader.cpp
        Statistic.h
        Statistic.cpp
        Writer.h
        Writer.cpp
)