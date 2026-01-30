#include "Visualizer.hpp"
#include <cmath>

static QuantumVisualState state;

void Visualizer::map()
{
    static float t = 0.0f;
    t += 0.016f;

    state.coherence = std::sin(t) * 0.5f + 0.5f;
    state.phase     = std::cos(t);
    state.entropy   = 1.0f - state.coherence;
}

QuantumVisualState Visualizer::current()
{
    return state;
}