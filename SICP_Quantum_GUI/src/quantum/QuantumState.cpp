#include "QuantumState.hpp"
#include <cmath>

static BlochVector blochVec;
static float theta = 0.0f;


void QuantumState::evolve()
{
    theta += 0.01f;

    blochVec.x = std::sin(theta);
    blochVec.y = std::cos(theta);
    blochVec.z = std::sin(theta * 0.5f);
}


BlochVector QuantumState::bloch()
{
    return blochVec;
}
float QuantumState::coherence()
{
    float mag = std::sqrt(
        blochVec.x * blochVec.x +
        blochVec.y * blochVec.y +
        blochVec.z * blochVec.z
    );

    if (mag > 1.0f)
        mag = 1.0f;

    return mag;
}
