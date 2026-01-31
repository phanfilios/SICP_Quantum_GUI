#pragma once
#include <vector>

struct QuantumCube
{
    float x, y, z;
    float rotation;
    float energy;
};

class QuantumCubeField
{
public:
    static void init(unsigned int cubeCount);
    static void update(float quantumEnergy);
    static const std::vector<QuantumCube>& cubes();
    static void computeCenter(float& x, float& y, float& z);

private:
    static std::vector<QuantumCube> s_cubes;
};