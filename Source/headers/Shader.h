#ifndef SHADER_H_
#define SHADER_H_
#include <string>
#include <vector>
#include "glm/glm.hpp"
namespace LightMC
{
    class Shader
    {
    private:
        std::string shaderString;
        std::string ReadShaderStringFromFile(const char *_fileLocation);
        unsigned int shaderType;
        unsigned int shaderProgram;
        unsigned int CompileShader(unsigned int);
        unsigned int shaderId;

    public:
        Shader(const char *_fileLocation, unsigned int, std::vector<unsigned int> &);
        void EnableShader() const;
        void SetFloatUniform(const std::string _name, float _value) const;
        void SetBoolUniform(const std::string _name, bool _value) const;
        void SetIntUniform(const std::string _name, int _value) const;
        void SetMat4Uniform(const std::string _name, glm::mat4) const;
        void SetVec3Uniform(const std::string _name, glm::vec3) const;
    };
} // namespace LightMC
#endif