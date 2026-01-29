#include "Application.hpp"
#include "kernel/Kernel.hpp"

void Application::run()
{
    Kernel::init();
    Kernel::start();

    while (true)
    {
        Kernel::tick();
    }

    Kernel::shutdown();
}