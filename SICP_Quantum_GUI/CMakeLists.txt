cmake

cmake_minimum-required(version 3.16)

project(SCIP-Quantum_GUI LANGUAGES CXX)

set(CMAKE-CXX-STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    src
)

# Archivos fuente

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(SICP_Quantum_GUI ${SOURCES})