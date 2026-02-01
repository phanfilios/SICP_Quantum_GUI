#include "Kernel.hpp"

#include "quantum/QuantumState.hpp"
#include "neuro/NeuroInterface.hpp"
#include "visual/Visualizer.hpp"
#include "render/Renderer.hpp"
#include "render/QuantumCubeField.hpp"
#include "gui/GuiBridge.hpp"

void Kernel::init()
{

    QuantumState::init();
    NeuroInterface::init();
    Visualizer::init();
    QuantumCubeField::init(250); 
    Renderer::init();
    GuiBridge::init();
}

void Kernel::tick()
{

    QuantumState::evolve();


    NeuroInterface::sample();


    float energy = QuantumState::coherence();


    QuantumCubeField::update(energy);
    Visualizer::map(energy);


    Renderer::draw();


    GuiBridge::sync();
}

void Kernel::shutdown()
{

    GuiBridge::shutdown();
    Renderer::shutdown();
    Visualizer::shutdown();
    NeuroInterface::shutdown();
    QuantumState::shutdown();
}