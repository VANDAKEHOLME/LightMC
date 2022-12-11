#include <string>
#include "glm/glm.hpp"
namespace LightMC
{
    class Shader
    {
    private:
        std::string shaderString;
        std::string ReadShaderStringFromFile(const char *_fileLocation);
        unsigned int shaderType;
        unsigned int _shaderProgram;
        unsigned int CompileShader(unsigned int);
        unsigned int shaderId;

    public:
        Shader(const char *_fileLocation, unsigned int, unsigned int &);
        void EnableShader() const;
        void SetFloatUniform(const std::string _name, float _value) const;
        void SetBoolUniform(const std::string _name, bool _value) const;
        void SetIntUniform(const std::string _name, int _value) const;
        void SetMat4Uniform(const std::string _name, glm::mat4) const;
    };
} // namespace LightMC
