cmake_minimum_required(VERSION 3.16)

project(SICP_Quantum_GUI LANGUAGES CXX)

# ─────────────────────────────────────────────
# Configuración general
# ─────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ─────────────────────────────────────────────
# Fuentes del proyecto
# ─────────────────────────────────────────────
file(GLOB_RECURSE SICP_SOURCES
    src/*.cpp
)

file(GLOB_RECURSE SICP_HEADERS
    src/*.hpp
)

add_executable(SICP_Quantum_GUI
    ${SICP_SOURCES}
    ${SICP_HEADERS}
)

# ─────────────────────────────────────────────
# Includes del proyecto
# ─────────────────────────────────────────────
target_include_directories(SICP_Quantum_GUI PRIVATE
    src
    third_party
    third_party/glm
    third_party/glad/include
)


find_package(OpenGL REQUIRED)

target_link_libraries(SICP_Quantum_GUI PRIVATE
    OpenGL::GL
)


add_subdirectory(third_party/glfw)

target_link_libraries(SICP_Quantum_GUI PRIVATE
    glfw
)


add_library(glad
    third_party/glad/src/glad.c
)

target_include_directories(glad PUBLIC
    third_party/glad/include
)

target_link_libraries(SICP_Quantum_GUI PRIVATE
    glad
)


if (WIN32)
    target_link_libraries(SICP_Quantum_GUI PRIVATE
        opengl32
    )
endif()