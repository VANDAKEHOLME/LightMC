#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <direct.h>
#include "DebugTools.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/// @brief To read the shader file.
/// @param _fileLocation
/// @return Shader string
std::string LightMC::Shader::ReadShaderStringFromFile(const char *_fileLocation)
{
    std::ifstream ifs;
    ifs.open(_fileLocation, std::ios::in);
    if (!ifs.is_open())
    {
        LightMC::DebugTools::DebugOutput("Failed to load shader files", LightMC::DebugTools::MsgType::Error);
        return nullptr;
    }
    std::stringstream strstream;
    strstream << ifs.rdbuf();
    std::string fileString;
    fileString = strstream.str();
    ifs.close();
    return fileString;
}
/// @brief To create a shader
/// @param _fileLocation
/// @param _shaderType
LightMC::Shader::Shader(const char *_fileLocation, GLenum _shaderType, GLenum &_shaderProgram)
{
    this->shaderString = ReadShaderStringFromFile(_fileLocation);
    shaderId = CompileShader(_shaderType);
    if (_shaderProgram == 0)
        _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, shaderId);
    glLinkProgram(_shaderProgram);
    int result;
    char infoLog[512];
    glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(_shaderProgram, 512, NULL, infoLog);        
        LightMC::DebugTools::DebugOutput(infoLog, LightMC::DebugTools::MsgType::Error);
    }
    glDeleteShader(shaderId);
    glUseProgram(_shaderProgram);
}
/// @brief To compile a shader
/// @param _shaderType
/// @return The shader's id
GLenum LightMC::Shader::CompileShader(GLenum _shaderType)
{
    const char* shaderChar = shaderString.c_str();
    unsigned int shader;
    shader = glCreateShader(_shaderType);
    glShaderSource(shader, 1, &shaderChar, NULL);
    glCompileShader(shader);
    int result;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        LightMC::DebugTools::DebugOutput(infoLog, LightMC::DebugTools::MsgType::Error);
    }
    return shader;
}