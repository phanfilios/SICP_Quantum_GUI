#pragma once

class Visualizer
{
public:
    static void init();
    static void map(float energy);

    static float intensity();
    static float motion();
    static float glow();

private:
    static float s_intensity;
    static float s_motion;
    static float s_glow;
};