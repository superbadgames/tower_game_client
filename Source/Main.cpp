#include "pch.h"
#include "framework.hpp"
#include <Tower/Managers/Director.hpp>

#include <GLFW/glfw3.h>


#include <iostream>

int main(void)
{
    Tower::p_Director director = Tower::Director::Instance();

    if (!director->Init(Tower::WindowType::OPEN_GL, "Encounters", 1280, 1024))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    std::cout << "We are up and running!" << std::endl;

    while (!director->ShouldProgramClose())
    {
        director->Tick();
        director->ProcessEvents();
        director->Tock();
    }

    director->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}