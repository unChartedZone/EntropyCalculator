cmake_minimum_required(VERSION 3.5)
project(EntropyCalculator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES entropy_calculator.cpp entropy_calculator.h entropy_error.h)
add_executable(EntropyCalculator entropy_calculator.cpp ${SOURCE_FILES})
