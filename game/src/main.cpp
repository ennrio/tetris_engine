#include "game/Game.hpp"
#include <graphics/Graphics.h>


int main() {
    //setlocale(LC_ALL, "RUS");
    //game::Game game;
    //game.run();


    GLFWwindow* window;
    if (!engine::Graphics::Init(window, 800, 600)) {
        return -1;
    }

    // Главный цикл
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    engine::Graphics::Terminate();
    return 0;
}