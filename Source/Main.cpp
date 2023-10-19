#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>

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
    const U32 BASIC_SHADER_ID = 1;
    const U32 CRATE_TEXTURE_ID = 1;

    //Tower::p_Director director = Tower::Director::Instance();

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
    Tower::Director::Instance()->GetShaderManager()->RegisterShader(BASIC_SHADER_ID, basicShader);

    //
    // Initialize Textures
    //
    Tower::Director::Instance()->GetTextureManager()->LoadTexture(CRATE_TEXTURE_ID, "..\\..\\Assets\\Default\\Textures\\container.jpg");

    p_Editor editor = std::make_shared<Editor>();
    editor->v_Init();

    Tower::Director::Instance()->CreateWorld();
    Tower::Director::Instance()->GetActiveWorld()->SetHuman(editor);

    // TODO: Move into its own object? Maybe a class, or maybe a factory of some sort
    Tower::p_Object container = std::make_shared<Tower::Object>();
    Tower::p_Model containerModel = std::make_shared<Tower::Model>();
    containerModel->LoadFromFile("..\\..\\Assets\\Default\\Models\\cube.glb", basicShader);
    containerModel->SetTexture(Tower::Director::Instance()->GetTextureManager()->GetTexture(CRATE_TEXTURE_ID));
    container->SetModel(containerModel);

    Tower::Director::Instance()->GetActiveWorld()->AddObject(container);


    while (!Tower::Director::Instance()->ShouldProgramClose())
    {
        Tower::Director::Instance()->Update();
        Tower::Director::Instance()->Draw();
    }

    Tower::Director::Instance()->Cleanup();

    std::cout << "Successful shutdown!" << std::endl;

    return 0;
}