#include "game/Game.hpp"
#include <glad/glad.h>
#include <graphics/Graphics.h>



int main() {
    //setlocale(LC_ALL, "RUS");
    //game::Game game;
    //game.run();


    //GLFWwindow* window;
    //if (!engine::Graphics::Init(window, 800, 600)) {
    //    return -1;
    //}

    //// Главный цикл
    //while (!glfwWindowShouldClose(window)) {
    //    glClear(GL_COLOR_BUFFER_BIT);
    //    glfwSwapBuffers(window);
    //    glfwPollEvents();
    //}


    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Tetris", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

    engine::Graphics::Terminate();
    return 0;
}