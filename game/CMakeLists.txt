# Создаем исполняемый файл игры
add_executable(game
    src/main.cpp
    src/Game.cpp
    include/game/Game.hpp
    src/pch/game_pch.h
)


# разносим файлы по группам
source_group("Source Files" FILES src/main.cpp src/game.cpp)
source_group("Header Files" FILES include/game/Game.hpp)
source_group("Header Files\\PCH" FILES src/pch/game_pch.h)

# Подключаем заголовки игры
target_include_directories(game
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Связываем игру с библиотекой engines
target_link_libraries(game
    PRIVATE
        engine
)

# подключаем pch - precompile headers
target_precompile_headers(game PRIVATE
    src/pch/game_pch.h
)