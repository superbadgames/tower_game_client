#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Managers/ShaderManager.hpp>
#include <Tower/Managers/TextureManager.hpp>

#include <Tower/Object.hpp>
#include <Tower/Rendering/Model.hpp>

#include "Editor/Editor.hpp"

#include <GLFW/glfw3.h>


#include <iostream>

using namespace TowerGameClient_Editor;

int main(void)
{
    // TODO: This should come from a config file
    const U32 WINDOW_WIDTH = 1200;
    const U32 WINDOW_HEIGHT = 800;

    if (!Tower::Director::Instance()->Init(Tower::WindowType::OPEN_GL, "Tower Sandbox", WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        std::cout << "Error! Unable to initialize." << std::endl;
        return 1;
    }

    //
    // Initialize shaders
    //
    Tower::p_Shader basicShader = std::make_shared<Tower::Shader>();
    basicShader->Load("..\\..\\Assets\\Default\\Shaders\\basic_vertex.glsl", "..\\..\\Assets\\Default\\Shaders\\basic_fragment.glsl");
    Tower::ShaderManager::Instance()->RegisterShader("basic2d", basicShader);

    //
    // Initialize Textures
    //
    Tower::TextureManager::Instance()->LoadTexture("container", "..\\..\\Assets\\Default\\Textures\\container.jpg");

    p_Editor editor = std::make_shared<Editor>();
    editor->v_Init();



    while (!Tower::Director::Instance()->ShouldProgramClose())
    {

    }

    Tower::Director::Instance()->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}