#include "visual/Visualizer.hpp"
#include <cmath>

// ─────────────────────────────────────────────
// Estado interno
// ─────────────────────────────────────────────
float Visualizer::s_energy     = 0.0f;
float Visualizer::s_pulse      = 0.0f;
float Visualizer::s_glow       = 0.0f;
float Visualizer::s_distortion = 0.0f;

void Visualizer::init()
{
    s_energy     = 0.0f;
    s_pulse      = 0.0f;
    s_glow       = 0.0f;
    s_distortion = 0.0f;
}

void Visualizer::shutdown()
{
a
}

void Visualizer::map(float energy)
{

    if (energy < 0.0f) energy = 0.0f;
    if (energy > 1.0f) energy = 1.0f;

    s_energy = energy;

    // ─────────────────────────────────────────
    // Traducción cuántica → visual
    // ─────────────────────────────────────────


    s_pulse = 0.5f + std::sin(energy * 6.2831f) * 0.5f;


    s_glow = energy * energy;


    s_distortion = std::sin(energy * 3.1415f) * 0.15f;
}

// ─────────────────────────────────────────────
// Getters
// ─────────────────────────────────────────────
float Visualizer::pulse()
{
    return s_pulse;
}

float Visualizer::glow()
{
    return s_glow;
}

float Visualizer::distortion()
{
    return s_distortion;
}