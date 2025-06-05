#pragma once

// Важно: должен быть определён до включения glfw3.h
#define GLFW_STATIC
#include <GLFW/glfw3.h>

namespace engine {
    class Graphics {
    public:
        static bool Init(GLFWwindow*& window, int width, int height);
        static void Terminate();
    };
}