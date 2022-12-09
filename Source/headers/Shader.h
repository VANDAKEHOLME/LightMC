#include <string>
namespace LightMC
{
    class Shader
    {
    private:
        std::string shaderString;
        std::string  ReadShaderStringFromFile(const char *_fileLocation);
        unsigned int shaderType;
    public:
        Shader(const char* _fileLocation, unsigned int, unsigned int&);
        unsigned int CompileShader(unsigned int);
        unsigned int shaderId;
    };
} // namespace LightMC
