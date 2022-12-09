#ifndef DEBUG_TOOLS_H_
#define DEBUG_TOOLS_H
#include <windows.h>
namespace LightMC
{
    /// @brief The class to debug.
    class DebugTools
    {
        public:
        /// @brief The type of the message to output.
        enum MsgType
        {
            Error,
            Normal
        };
        static void DebugOutput(const char*, MsgType);
        static void DebugToolsInitialize();
    };
}

#endif