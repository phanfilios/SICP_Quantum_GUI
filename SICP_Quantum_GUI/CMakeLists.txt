cmake_minimum_required(VERSION 3.16)

project(SICP_Quantum_GUI LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third_party)


find_package(OpenGL REQUIRED)


add_subdirectory(${THIRD_PARTY_DIR}/glfw)


add_library(glad STATIC
    ${THIRD_PARTY_DIR}/glad/src/glad.c
)

target_include_directories(glad PUBLIC
    ${THIRD_PARTY_DIR}/glad/include
)


add_library(glm INTERFACE)
target_include_directories(glm INTERFACE
    ${THIRD_PARTY_DIR}/glm
)


file(GLOB_RECURSE PROJECT_SOURCES
    ${SRC_DIR}/*.cpp
)

add_executable(SICP_Quantum_GUI
    ${PROJECT_SOURCES}
)

target_include_directories(SICP_Quantum_GUI PRIVATE
    ${SRC_DIR}
)


target_link_libraries(SICP_Quantum_GUI
    PRIVATE
        OpenGL::GL
        glfw
        glad
        glm
)


if (WIN32)
    target_link_libraries(SICP_Quantum_GUI PRIVATE opengl32)
    target_compile_definitions(SICP_Quantum_GUI PRIVATE NOMINMAX)
endif()