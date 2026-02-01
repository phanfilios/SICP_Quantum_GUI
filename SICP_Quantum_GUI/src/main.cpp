#include <iostream>


#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include "kernel/Kernel.hpp"

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{

    if (!glfwInit())
    {
        std::cerr << "[SICP] Error: GLFW no pudo inicializarse\n";
        return -1;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(
        1280,
        720,
        "SICP Quantum GUI",
        nullptr,
        nullptr
    );

    if (!window)
    {
        std::cerr << "[SICP] Error: No se pudo crear la ventana\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "[SICP] Error: GLAD no pudo cargarse\n";
        return -1;
    }

    glEnable(GL_DEPTH_TEST);


    Kernel::init();
    Kernel::start();


    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        Kernel::tick();

        glfwSwapBuffers(window);
    }


    Kernel::shutdown();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}