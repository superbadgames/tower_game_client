#pragma once

#include "pch.h"
#include <Tower/framework.h>
#include <Tower/Managers/Director.hpp>
#include <Tower/Entity.hpp>
#include <Tower/Input/InputController.hpp>

namespace TowerGameClient_Editor
{
    class Editor : public Tower::Entity
    {
    public:
        Editor(void);

        ~Editor(void);

        virtual void v_PerformActions(F32 delta) final;

        virtual void v_Init(void) final;

        inline Tower::p_InputController GetInputController(void) const
        {
            return _controller;
        }

    private:
        Tower::p_InputController _controller;

    };
    typedef shared_ptr<Editor> p_Editor;
}
