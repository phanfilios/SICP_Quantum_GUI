#pragma once

struct QuantumVisualState {
    float coherence;
    float phase;
    float entropy;
};

class Visualizer {
public:
    static QuantumVisualState current();
    static void map();
};