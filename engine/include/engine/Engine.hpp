#pragma once
#include "../src/Sprite.hpp"

namespace engine {
    class Engine {
    public:
        void start();
        void create_field(const int width, const int height);
        void drow_field();
        void create_sprite(std::vector<std::vector<char>> body);
        void add_field_sprite(const int x, const int y, const int spriteNumber);
    private:
        int width  = 0;
        int height = 0;
        std::vector<std::vector<char>> field;
        std::vector<Sprite*> arr_sprite;
    };
}