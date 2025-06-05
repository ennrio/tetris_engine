set(SOURCES 
    src/Engine.cpp 
    src/Sprite.cpp
)

set(HEADERS 
    include/engIne/Engine.hpp 
    src/Sprite.hpp
)

# Создаем библиотеку engines
add_library(engine STATIC
    ${SOURCES} 
    ${HEADERS} 
    src/pch/engine_pch.h
)

source_group("Source Files" FILES Engine.cpp)
source_group("Header Files" FILES Egine.hpp)
source_group("Header Files\\PCH" FILES src/pch/engine_pch.h)

# Делаем заголовки доступными для других целей
target_include_directories(engine
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include  # Путь к Engine.hpp
)

# Подключаю pch - precompiled headers
target_precompile_headers(engine PRIVATE
    src/pch/engine_pch.h
)