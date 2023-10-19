#include "pch.h"
#include "Editor/Editor.hpp"

using namespace TowerGameClient_Editor;

Editor::Editor(void) :
    _controller(nullptr)
{

}

Editor::~Editor(void)
{

}

void Editor::v_PerformActions(F32 delta)
{
    if (_controller->IsKeyboardBindingActive("exit_game"))
    {
        Tower::Director::Instance()->CloseProgram();
    }
}

void Editor::v_Init(void)
{
    _controller = std::make_shared<Tower::InputController>();
    _controller->AddKeyboardBinding("exit_game", Tower::InputButton::ESCAPE, Tower::InputButtonState::PRESS);
    Tower::Director::Instance()->RegisterInputWithWindow(_controller);
}
