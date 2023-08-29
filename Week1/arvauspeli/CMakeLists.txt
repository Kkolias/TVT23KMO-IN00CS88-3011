cmake_minimum_required(VERSION 3.5)

project(arvauspeli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(arvauspeli main.cpp)

install(TARGETS arvauspeli
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
