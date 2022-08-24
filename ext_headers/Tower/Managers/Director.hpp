#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/EntityManager.hpp"
#include "Tower/Managers/ComponentManager.hpp"
#include "Tower/Managers/SystemManager.hpp"
#include "Tower/Systems/TimeSystem.hpp"

namespace Tower
{
    class Director
    {
    public:
        ~Director(void);

        static shared_ptr<Director> Instance(void);

        void Init(void);

        void Tick(void);

        void Tock(void);

    private:
        static shared_ptr<Director> _instance;

        Director(void);

        TimeSystem _time;
    };
    typedef shared_ptr<Director> p_Director;
}