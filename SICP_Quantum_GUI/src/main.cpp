#include <iostream>


#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include "kernel/Kernel.hpp"


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


int main()
{

    if (!glfwInit())
    {
        std::cerr << "❌ Error: GLFW init failed\n";
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
        std::cerr << "❌ Error: Window creation failed\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "❌ Error: GLAD init failed\n";
        return -1;
    }


    glEnable(GL_DEPTH_TEST);
    glClearColor(0.02f, 0.02f, 0.05f, 1.0f);


    Kernel::init();
    Kernel::start();


    while (!glfwWindowShouldClose(window))
    {

        Kernel::tick();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    Kernel::shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}