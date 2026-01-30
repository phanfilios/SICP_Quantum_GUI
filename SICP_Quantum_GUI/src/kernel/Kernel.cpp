#include "Kernel.hpp"
#include "quantum/QuantumState.hpp"
#include "neuro/NeuroInterface.hpp"
#include "visual/Visualizer.hpp"
#include "render/Renderer.hpp"
#include "gui/GuiBridge.hpp"

void Kernel::init()
{
    // Inicialización del núcleo SICP
}

void Kernel::start()
{
    // Arranque de subsistemas
    GuiBridge::init();
}

void Kernel::tick()
{
    // Ciclo principal del sistema

    QuantumState::evolve();     // Evolución cuántica
    NeuroInterface::sample();   // Captura neuroeléctrica
    Visualizer::map();          // Mapeo estado → visual
    Renderer::draw();           // Renderizado
    GuiBridge::sync();          // Sincronización GUI
}

void Kernel::shutdown()
{
    // Apagado ordenado del sistema
    GuiBridge::shutdown();
}
