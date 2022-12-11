#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <direct.h>
#include "DebugTools.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "glm/gtc/type_ptr.hpp"

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
LightMC::Shader::Shader(const char *_fileLocation, GLenum _shaderType, GLenum &shaderProgram)
{
    this->shaderString = ReadShaderStringFromFile(_fileLocation);
    shaderId = CompileShader(_shaderType);
    if (shaderProgram == 0)
    {
        shaderProgram = glCreateProgram();
    }
    _shaderProgram = shaderProgram;
    glAttachShader(shaderProgram, shaderId);
    glLinkProgram(shaderProgram);
    int result;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
    if (!result)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        LightMC::DebugTools::DebugOutput(infoLog, LightMC::DebugTools::MsgType::Error);
    }
    glDeleteShader(shaderId);
    if (shaderProgram != GL_VERTEX_SHADER)
        glUseProgram(shaderProgram);
}
/// @brief To compile a shader
/// @param _shaderType
/// @return The shader's id
GLenum LightMC::Shader::CompileShader(GLenum _shaderType)
{
    const char *shaderChar = shaderString.c_str();
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
/// @brief To enable a shader.
void LightMC::Shader::EnableShader() const
{
    glUseProgram(_shaderProgram);
}
/// @brief To send a uniform float to vertex shader.
/// @param _name
/// @param _value
void LightMC::Shader::SetFloatUniform(const std::string _name, float _value) const
{
    int location = glGetUniformLocation(this->_shaderProgram, _name.c_str());
    glUniform1f(location, _value);
}
/// @brief To send a uniform boolean to shader.
/// @param _name
/// @param _value
void LightMC::Shader::SetBoolUniform(const std::string _name, bool _value) const
{
    int location = glGetUniformLocation(this->_shaderProgram, _name.c_str());
    glUniform1i(location, _value);
}
/// @brief To send a uniform int to shader.
/// @param _name
/// @param _value
void LightMC::Shader::SetIntUniform(const std::string _name, int _value) const
{
    int location = glGetUniformLocation(this->_shaderProgram, _name.c_str());
    glUniform1i(location, _value);
}
/// @brief To send a uniform 4x4 matrix to shader.
/// @param _name
/// @param _value
void LightMC::Shader::SetMat4Uniform(const std::string _name, glm::mat4 _value) const
{
    int location = glGetUniformLocation(this->_shaderProgram, _name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(_value));
}
/// @brief To send a uniform vector with 3 parameters to shader.
/// @param _name
/// @param _value
void LightMC::Shader::SetVec3Uniform(const std::string _name, glm::vec3 _value) const
{
    int location = glGetUniformLocation(this->_shaderProgram, _name.c_str());
    glUniform3fv(location, 1, glm::value_ptr(_value));
}