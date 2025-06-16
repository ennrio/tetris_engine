#include <iostream>
#include "engine/Engine.hpp"
#include "graphics/Graphics.hpp"
#include "spdlog/spdlog.h"
#include "Log.hpp"

void engine::Engine::start() {
    spdlog::info("Engine started!");
    //std::cout << "Engine started!" << std::endl;
}

void engine::Engine::create_field(const int width, const int height)
{
    this->width = width;
    this->height = height;
    for (int i = 0; i < width; i++) {
        std::vector<char> help;
        for (int j = 0; j < height; j++) {
            help.push_back('*');
        }
        this->field.push_back(help);
    }
}

void engine::Engine::drow_field()
{
    for (int i = 0; i < this->field.size(); i++) {
        for (int j = 0; j < this->field[i].size(); j++) {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}

void engine::Engine::create_sprite(std::vector<std::vector<char>> body)
{
    Sprite* sprite = new Sprite(body);
    this->arr_sprite.push_back(sprite);
}

void engine::Engine::add_field_sprite(const int x, const int y, const int spriteNumber)
{
    //drow_field();
    for (int i = y; i < y + arr_sprite[spriteNumber]->getBody().size(); i++) {
        for (int j = x; j < x + arr_sprite[spriteNumber]->getBody()[i-y].size(); j++) {
            field[i][j] = arr_sprite[spriteNumber]->getBody()[(i-y)][j-x];
        }
    }
}

void engine::Engine::drowTriangle()
{
    engine::Graphics::Init(800,600);
    engine::Graphics::Terminate();
}

void engine::Engine::testSpdlog()
{

    LOG_INFO("Hello, spdlog!");
    LOG_ERROR("this a error");
    LOG_WARN("This is a warning!");
    LOG_CRIT("This is an error");
}

