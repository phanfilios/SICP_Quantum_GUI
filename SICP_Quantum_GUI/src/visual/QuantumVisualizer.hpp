#pragma once

class QuantumVisualizer
{
public:
    static void init();
    static void map(float energy);
    static void shutdown();

    static float pulse();
    static float intensity();
};