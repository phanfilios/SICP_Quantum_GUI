#include "render/QuantumCubeField.hpp"
#include "opengl/gl_compat.hpp"

#include <cstdlib>
#include <cmath>

static std::vector<QuantumCube> cubes;

void QuantumCubeField::init()
{
    const int count = 64;

    cubes.clear();
    for (int i = 0; i < count; ++i)
    {
        QuantumCube c;
        c.x = (rand() % 100 - 50) / 10.0f;
        c.y = (rand() % 100 - 50) / 10.0f;
        c.z = -(rand() % 100) / 10.0f;
        c.size = (rand() % 10 + 5) / 100.0f;
        c.phase = (rand() % 100) / 10.0f;
        c.speed = (rand() % 10 + 1) / 500.0f;
        cubes.push_back(c);
    }
}

void QuantumCubeField::update(float coherence)
{
    for (auto& c : cubes)
    {
        c.phase += c.speed;
        c.y += std::sin(c.phase) * 0.001f * coherence;
        c.z += c.speed * coherence * 0.2f;

        if (c.z > 0.0f)
            c.z = -10.0f;
    }
}

void drawCube(const QuantumCube& c)
{
    glPushMatrix();
    glTranslatef(c.x, c.y, c.z);
    glScalef(c.size, c.size, c.size);

    glBegin(GL_QUADS);
    glColor4f(0.6f, 0.7f, 1.0f, 0.3f);

    // Cara frontal
    glVertex3f(-1, -1, 1);
    glVertex3f( 1, -1, 1);
    glVertex3f( 1,  1, 1);
    glVertex3f(-1,  1, 1);

    glEnd();
    glPopMatrix();
}

void QuantumCubeField::draw()
{
    for (const auto& c : cubes)
        drawCube(c);
}
