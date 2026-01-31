#include "Renderer.hpp"
#include "render/QuantumCubeField.hpp"

#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>

// ─────────────────────────────────────────────
// ESTÁTICOS
// ─────────────────────────────────────────────
Shader* Renderer::s_shader = nullptr;
Camera  Renderer::s_camera;

// ─────────────────────────────────────────────
// Helper: cubo wireframe estilo PS2
// ─────────────────────────────────────────────
static void drawWireCube(float size)
{
    float s = size * 0.5f;

    glBegin(GL_LINES);

    // base
    glVertex3f(-s, -s, -s); glVertex3f( s, -s, -s);
    glVertex3f( s, -s, -s); glVertex3f( s, -s,  s);
    glVertex3f( s, -s,  s); glVertex3f(-s, -s,  s);
    glVertex3f(-s, -s,  s); glVertex3f(-s, -s, -s);

    // top
    glVertex3f(-s,  s, -s); glVertex3f( s,  s, -s);
    glVertex3f( s,  s, -s); glVertex3f( s,  s,  s);
    glVertex3f( s,  s,  s); glVertex3f(-s,  s,  s);
    glVertex3f(-s,  s,  s); glVertex3f(-s,  s, -s);

    // verticals
    glVertex3f(-s, -s, -s); glVertex3f(-s,  s, -s);
    glVertex3f( s, -s, -s); glVertex3f( s,  s, -s);
    glVertex3f( s, -s,  s); glVertex3f( s,  s,  s);
    glVertex3f(-s, -s,  s); glVertex3f(-s,  s,  s);

    glEnd();
}

// ─────────────────────────────────────────────
// INIT
// ─────────────────────────────────────────────
void Renderer::init()
{
    s_shader = new Shader(
        "shaders/basic.vert",
        "shaders/basic.frag"
    );

    glEnable(GL_DEPTH_TEST);
}

// ─────────────────────────────────────────────
// DRAW
// ─────────────────────────────────────────────
void Renderer::draw()
{
    // Centro del campo cuántico
    float cx, cy, cz;
    QuantumCubeField::computeCenter(cx, cy, cz);

    glm::vec3 desiredTarget(cx, cy, cz);
    glm::vec3 desiredPosition(cx, cy + 5.0f, cz + 12.0f);

    s_camera.update(
        1.0f / 60.0f,
        desiredPosition,
        desiredTarget
    );

    // Limpieza
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Cámara
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(s_camera.getViewMatrix()));

    // Shader (solo uniforms por ahora)
    if (s_shader)
    {
        s_shader->use();
        s_shader->setFloat("u_time", 0.0f); // luego lo conectamos al reloj
        s_shader->setVec2("u_resolution", glm::vec2(1280, 720));
    }

    // Cubos
    const auto& cubes = QuantumCubeField::cubes();

    for (const auto& cube : cubes)
    {
        float e = cube.energy;
        glColor3f(0.2f + e * 0.6f, 0.3f + e * 0.6f, 1.0f);

        glPushMatrix();
        glTranslatef(cube.x, cube.y, cube.z);
        glRotatef(cube.rotation, 0.f, 1.f, 0.f);
        drawWireCube(0.8f + e * 0.5f);
        glPopMatrix();
    }
}