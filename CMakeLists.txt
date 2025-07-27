cmake_minimum_required(VERSION 3.31)
project(MonteCarloEngine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -ffast-math -flto -fno-exceptions -fno-rtti -march=native -ftree-vectorize -fstrict-aliasing -fno-common")

add_executable(MonteCarloEngine src/main.cpp
        src/PiCalculation.cpp
        src/RandomPointGenerator.cpp
)