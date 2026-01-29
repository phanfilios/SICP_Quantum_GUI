#include "Kernel.hpp"
#include "quantum/QuantumState.hpp"
#include "neuro/NeuroInterface.hpp"
#include "visual/Visualizer.hpp"
#include "render/Renderer.hpp"
#include "gui/GuiBridge.hpp"

void Kernel::init() {}
void Kernel::start() {}

void Kernel::tick()
{
    QuantumState::evolve();
    NeuroInterface::sample();
    Visualizer::map();
    Renderer::draw();
    GuiBridge::sync();
}

void Kernel::shutdown() {}