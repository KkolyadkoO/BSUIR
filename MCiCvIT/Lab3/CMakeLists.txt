cmake_minimum_required(VERSION 3.24)

project(LAB)

add_definitions(-DSOME_IMPORTANT_DEFINITION)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
  
add_executable(${PROJECT_NAME}
    var_3.cpp
)

