#ifdef _WIN32
  #include <windows.h>
  
#endif

#include <GL/gl.h>

void Renderer::init() {
    glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glEnable(GL_DEPTH_TEST);

QuantumCubeField::init();
}

void Renderer::draw()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

auto visual = Visualizer::current();
QuantumCubeField::update(visual.coherence);
QuantumCubeField::draw();

}