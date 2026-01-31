#pragma once

#include <glm/glm.hpp>

class Shader;
class Camera;

class Renderer
{
public:
    // Inicializa recursos gráficos (shader, estados OpenGL)
    static void init();

    // Dibuja un frame completo
    static void draw();

private:
    // Shader activo (fondo + color base)
    static Shader* s_shader;

    // Cámara global del render
    static Camera s_camera;
};