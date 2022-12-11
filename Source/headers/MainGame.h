#ifndef MAINGAME_H_
#define MAINGAME_H_
#include "windowHanlder.h"
#include "Camera.h"
#include "Shader.h"
namespace LightMC
{
    class MainGame
    {
    private:
        WindowHandler *windowHandler;
        static inline void WindowLoopCallback(void *);

    public:
        float deltaTime = 0.0f; // 当前帧与上一帧的时间差
        float lastFrame = 0.0f; // 上一帧的时间
        static inline LightMC::Camera *camera = nullptr;
        static inline float FOV = 45;
        unsigned int VBO, targetVAO, EBO, lightVAO;

        Shader *vertexShaderForObj;
        Shader *fragmentShaderForObj;
        unsigned int shaderProgram = 0;
        void StartGame();
        void TerminateGame();
    };
}

#endif