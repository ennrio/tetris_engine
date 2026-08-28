#include "game/Game.hpp"
#include <engine/Engine.hpp>
//#include "engine/Engine.hpp"
#include "pch/game_pch.h"




void game::Game::run() {
    engine::Engine engine;
    engine.testSpdlog();
    engine.start();
    engine.create_field(30, 60);
    //engine.drow_field();
    std::cout << "Game is running!" << std::endl;
    engine.create_sprite(std::vector<std::vector<char>>{
        { '*', '#', '*', '#', '#' },
        { '*','#','#','#','*' },
        { '#','#','#','#','#' },
        { '*','*','*','*','*' }  
    });
    engine.add_field_sprite(4, 6,0);
    engine.drow_field();
    engine.init_window(600,800,EWindowMode::flexWindow, true);
    engine.drowTriangle();
    
} 
