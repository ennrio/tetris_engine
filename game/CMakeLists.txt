# Создаем исполняемый файл игры
add_executable(game
    src/main.cpp
    src/Game.cpp
    include/game/Game.hpp
    src/pch/game_pch.h
)

# Добавить glad.c в исходные файлы
add_library(glad ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/src/glad.c)
#target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)


# разносим файлы по группам
source_group("Source Files" FILES src/main.cpp src/game.cpp)
source_group("Header Files" FILES include/game/Game.hpp)
source_group("Header Files\\PCH" FILES src/pch/game_pch.h)

# Подключаем заголовки игры
target_include_directories(game
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include)

# Связываем игру с библиотекой engines
target_link_libraries(game
    PRIVATE
        engine
        glad
        
)

# подключаем pch - precompile headers
target_precompile_headers(game PRIVATE
    src/pch/game_pch.h
)