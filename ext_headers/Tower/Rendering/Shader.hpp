#pragma once
#include "pch.h"
#include "Tower/framework.h"
#include <GL/glew.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <map>

namespace Tower
{
    struct ShaderFilepaths
    {
        string vertext;
        string fragment;
    };

    class Shader
    {
    public:
        Shader(void);

        Shader(const Shader& other);

        Shader& operator=(const Shader& other);

        ~Shader(void);

        void Load(string vertexFilepath, string fragmentFilepath);

        void UseProgram(bool state);

        void SetUniformFloat(string name, const F32 val);

        void SetUniformVec2(string name, const glm::vec2& vec);

        void SetUniformVec3(string name, const glm::vec3& vec);

        void SetUniformVec4(string name, const glm::vec4& vec);

        void SetUniformMat4(string name, const glm::mat4& mat);

        void SetUniformSampler(string name, S32 texSlot);

    private:
        GLuint _shaderHandle;
        std::map<string, S32> _attributeLocations;
        std::map<string, S32> _uniformLocations;

        GLuint _CompileShader(string filepath, GLenum type);

        bool _Link(GLuint vertexShader, GLuint fragmentShader);

        string _ReadShaderSource(string path);

        GLuint _GetUniformLocation(string name);

        void _PopulateAttributes(void);

    };
    typedef shared_ptr<Shader> p_Shader;
}