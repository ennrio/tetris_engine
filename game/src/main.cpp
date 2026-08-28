#include "game/Game.hpp"
//#include <glad/glad.h>
//#include <graphics/Graphics.hpp>



int main() {
    setlocale(LC_ALL, "RUS");
    game::Game game;
    game.run();

    return 0;
}


// Разобраться с библиотекой freetype
// Начать рисовать граффику
// реализовать игроваой цикл ??