cmake_minimum_required(VERSION 3.10)
project(MyGame)

# Подключаем поддиректории engines и game
add_subdirectory(engine)
add_subdirectory(game)