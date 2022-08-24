#include "pch.h"
#include "framework.hpp"
#include <Tower/Managers/Director.hpp>

#include <iostream>

int main(void)
{
    Tower::p_Director director = Tower::Director::Instance();
    director->Init();

    if (director == nullptr)
    {
        std::cout << "Error!!!" << std::endl;
    }

    std::cout << "Hello World! We are up and running!" << std::endl;
}