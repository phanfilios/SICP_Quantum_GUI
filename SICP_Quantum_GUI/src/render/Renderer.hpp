#pragma once

#include <glm/glm.hpp>

class Shader;
class Camera;

class Renderer
{
public:

    static void init();
    static void draw();
    static void shutdown();

private:

    static Shader* s_shader;
    static Camera* s_camera;

    Renderer() = delete;
};