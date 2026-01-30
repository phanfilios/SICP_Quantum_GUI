cmake_minimum_required(VERSION 3.20)

project(SICP_Quantum_GUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ejecutable principal

add_executable(SICP_Quantum_GUI
    main.cpp

    app/Application.cpp
    kernel/Kernel.cpp

    quantum/QuantumState.cpp
    neuro/NeuroInterface.cpp

    visual/Visualizer.cpp
    render/Renderer.cpp
    gui/GuiBridge.cpp
)

# Includes globales

target_include_directories(SICP_Quantum_GUI PRIVATE
    ${PROJECT_SOURCE_DIR}
)