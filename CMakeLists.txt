cmake_minimum_required(VERSION 3.29)
project(finalProject_draft)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(finalProject_draft
    date.cpp
    date.h
    lesson.cpp
    lesson.h
    main.cpp
    person.cpp
    person.h)
