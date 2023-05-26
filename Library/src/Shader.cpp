#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Log.h"


namespace small {

    unsigned int Shader::compileShader(unsigned int type, const char* source)
    {
        unsigned int shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, NULL);
        glCompileShader(shader);

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            SmallWarn("Shader compilation error:\n {}", infoLog);
        }

    return shader;
    }

    unsigned int Shader::createShaderProgram(const char* vsource,const char* fsource)
    {
        unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vsource);
        unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fsource);

        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        int success;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            char infoLog[512];
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            SmallWarn("Shader program linking error:\n {}", infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return shaderProgram;
    }
}