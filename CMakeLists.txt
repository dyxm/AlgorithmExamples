cmake_minimum_required(VERSION 3.8)
project(AlgorithmExamples)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp dynamicProgramming/MatrixChain.h dynamicProgramming/LCS.h dynamicProgramming/MaxSubSum.h)
add_executable(AlgorithmExamples ${SOURCE_FILES})