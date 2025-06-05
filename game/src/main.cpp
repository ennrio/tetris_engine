#include "game/Game.hpp"

int main() {
    setlocale(LC_ALL, "RUS");
    game::Game game;
    game.run();
    return 0;
}