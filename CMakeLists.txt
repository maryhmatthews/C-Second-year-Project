cmake_minimum_required(VERSION 3.6)
project(Ex3_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp functions.cpp functions.h random.h random.cpp Box.h Box.cpp Vector.h Vector.cpp Particle.h Particle.cpp)
add_executable(Ex3_3 ${SOURCE_FILES})