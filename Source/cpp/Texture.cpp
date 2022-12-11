#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "DebugTools.h"

LightMC::Texture::Texture(const char *_fileLocation, TextureStyle _textureStyle)
{
    int width, height, channelNumber;
    stbi_set_flip_vertically_on_load(true);
    // Last parameter 0 to keep it as is.
    unsigned char *data = stbi_load(_fileLocation, &width, &height, &channelNumber, 0);
    if (data)
    {
        unsigned int texture;
        glGenTextures(1, &texture);
        glActiveTexture(_textureStyle.textureUnitIndex);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _textureStyle.textureWrapS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _textureStyle.textureWrapT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _textureStyle.textureMagFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _textureStyle.textureMinFilter);
        if (channelNumber == 3)
            glTexImage2D(GL_TEXTURE_2D, _textureStyle.textureLevel, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        if (channelNumber == 4)
            glTexImage2D(GL_TEXTURE_2D, _textureStyle.textureLevel, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        
    }
    else
    {
        LightMC::DebugTools::DebugOutput("Failed to load the image at", LightMC::DebugTools::Error);
        LightMC::DebugTools::DebugOutput(_fileLocation, LightMC::DebugTools::Error);
    }
    stbi_image_free(data);
}