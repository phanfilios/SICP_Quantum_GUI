#pragma once

#include <vector>
#include "render/QuantumCube.hpp"

class QuantumCubeField {
public:
    static void init();
    static void update(float coherence);
    static void draw();
};