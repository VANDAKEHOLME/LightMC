#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <glad/glad.h>
namespace LightMC
{
    /// @brief The class to control a texture.
    class Texture
    {
    private:
    public:
        struct TextureStyle
        {
            int textureLevel;
            unsigned int textureWrapS;
            unsigned int textureWrapT;
            unsigned int textureMagFilter;
            unsigned int textureMinFilter;
            unsigned int textureUnitIndex;
        };
        Texture(const char *, TextureStyle = {0, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST_MIPMAP_NEAREST, GL_TEXTURE0});
    };
}
#endif