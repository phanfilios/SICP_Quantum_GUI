#pragma once

struct BlochVector {
    float x;
    float y;
    float z;
};

class QuantumState {
public:
    static void evolve();
    static BlochVector bloch();
};