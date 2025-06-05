#include "graphics/Graphics.h"


bool engine::Graphics::Init(GLFWwindow*& window, int width, int height) {
    if (!glfwInit()) {
        return false;
    }

    // Настройка окна
    window = glfwCreateWindow(width, height, "GLFW Window", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    return true;
}

void engine::Graphics::Terminate() {
    glfwTerminate();
}