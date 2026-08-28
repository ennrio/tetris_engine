#pragma once

// Важно: должен быть определён до включения glfw3.h
#include <glad/glad.h>
#define GLFW_STATIC
#include <GLFW/glfw3.h>
#include "../../include/Engine/Enums.hpp"


namespace engine {
    class Graphics {
    public:
        static bool Init(EWindowMode mode, int width, int height, bool frame);
        static void Terminate();
    };
}