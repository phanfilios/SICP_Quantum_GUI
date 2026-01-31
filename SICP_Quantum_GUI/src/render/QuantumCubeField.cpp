#include "render/QuantumCubeField.hpp"
#include <cstdlib>
#include <cmath>

std::vector<QuantumCube> QuantumCubeField::s_cubes;

void QuantumCubeField::init(unsigned int cubeCount)
{
    s_cubes.clear();
    s_cubes.reserve(cubeCount);

    for (unsigned int i = 0; i < cubeCount; ++i)
    {
        QuantumCube cube;

        cube.x = (std::rand() % 200 - 100) / 10.0f;
        cube.y = (std::rand() % 200 - 100) / 10.0f;
        cube.z = (std::rand() % 200 - 100) / 10.0f;

        cube.rotation = static_cast<float>(std::rand() % 360);
        cube.energy = 0.0f;

        s_cubes.push_back(cube);
    }
}

void QuantumCubeField::update(float quantumEnergy)
{
    if (quantumEnergy < 0.0f) quantumEnergy = 0.0f;
    if (quantumEnergy > 1.0f) quantumEnergy = 1.0f;

    for (auto& cube : s_cubes)
    {
        cube.energy = quantumEnergy;
        cube.rotation += 0.2f + quantumEnergy;
        cube.y += std::sin(cube.rotation * 0.01f) * 0.002f;
    }
}

const std::vector<QuantumCube>& QuantumCubeField::cubes()
{
    return s_cubes;
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
