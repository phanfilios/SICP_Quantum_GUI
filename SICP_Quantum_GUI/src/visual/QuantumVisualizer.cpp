#include "Renderer.hpp"
#include "render/QuantumCubeField.hpp"
#include "render/Shader.hpp"
#include "render/Camera.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>


Shader* Renderer::s_shader = nullptr;
Camera* Renderer::s_camera = nullptr;

static float s_pulse = 0.0f;
static float s_intensity = 0.0f;



void Renderer::draw()
{
    static float time = 0.0f;
    time += 1.0f / 60.0f;


    float cx, cy, cz;
    QuantumCubeField::computeCenter(cx, cy, cz);

    glm::vec3 desiredTarget(cx, cy, cz);
    glm::vec3 desiredPosition(cx, cy + 5.0f, cz + 12.0f);

    s_camera->update(
        1.0f / 60.0f,
        desiredPosition,
        desiredTarget
    );


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    s_shader->use();


    glm::mat4 projection = glm::perspective(
        glm::radians(60.0f),
        1280.0f / 720.0f,   
        0.1f,
        100.0f
    );

    glm::mat4 view = s_camera->getViewMatrix();
    glm::mat4 mvp  = projection * view;


    s_shader->setMat4("u_mvp", mvp);
    s_shader->setFloat("u_time", time);
    s_shader->setVec2("u_resolution", glm::vec2(1280, 720));


    const auto& cubes = QuantumCubeField::cubes();

    for (const auto& cube : cubes)
    {
        glm::mat4 model = glm::translate(glm::mat4(1.0f),
            glm::vec3(cube.x, cube.y, cube.z));

        model = glm::rotate(
            model,
            glm::radians(cube.rotation),
            glm::vec3(0.f, 1.f, 0.f)
        );

        glm::mat4 cubeMVP = mvp * model;
        s_shader->setMat4("u_mvp", cubeMVP);

        drawWireCube(0.8f + cube.energy * 0.5f);
    }
}
void Renderer::shutdown()
{
    if (s_shader)
    {
        delete s_shader;
        s_shader = nullptr;
    }

    if (s_camera)
    {
        delete s_camera;
        s_camera = nullptr;
    }
}