#pragma once

class Kernel {
public:
    static void init();
    static void start();
    static void tick();
    static void shutdown();
};