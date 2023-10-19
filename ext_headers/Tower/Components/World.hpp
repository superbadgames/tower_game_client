#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/Director.hpp"
#include "Tower/Object.hpp"
#include "Tower/Entity.hpp"
#include "Tower/Rendering/Camera.hpp"
#include <vector>

namespace Tower
{
    class World
    {
    public:
        World(void);

        ~World(void);

        void Load(/*string filepath,*/);

        void Update(F32 delta);

        void Render(const glm::mat4& viewMatrix);

        inline void SetEntities(std::vector<p_Entity> entities)
        {
            _entities.clear();
            _entities = entities;
        }

        inline void SetObjects(std::vector<p_Object> objects)
        {
            _objects.clear();
            _objects = objects;
        }

        inline void AddObject(p_Object object)
        {
            _objects.push_back(object);
        }

        inline p_Entity GetHuman(void)
        {
            return _human;
        }

        inline void SetHuman(p_Entity human)
        {
            _human = human;
        }

    protected:
        p_Entity _human;
        std::vector<p_Object> _objects;
        std::vector<p_Entity> _entities;

    };
    typedef shared_ptr<World> p_World;
}