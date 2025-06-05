cmake_minimum_required(VERSION 3.15)
project(engine)

set(SOURCES 
    src/Engine.cpp 
    src/Sprite.cpp
)

set(HEADERS 
    include/engine/Engine.hpp 
    src/Sprite.hpp
)


set(GLFW_BUILD_STATIC ON CACHE BOOL "Build static GLFW library")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build GLFW documentation")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build GLFW examples")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build GLFW tests")


# Добавить поддиректорию GLFW
add_subdirectory(libs/glfw)


# Создаем библиотеку engines
add_library(engine STATIC
    ${SOURCES} 
    ${HEADERS} 
    src/pch/engine_pch.h
    src/graphics/Graphics.cpp
)

set(GRAPHICS_FILES 
    graphics/Graphics.h 
    graphics/Graphics.cpp
)

source_group("Source Files" FILES ${SOURCES})
source_group("Header Files" FILES ${HEADERS})
source_group("Graphics Files" FILES ${GRAPHICS_FILES})
#source_group("Header Files\\PCH" FILES src/pch/engine_pch.h)

#add_subdirectory(libs/glfw)
#target_link_libraries(engine PRIVATE glfw)

# Делаем заголовки доступными для других целей
target_include_directories(engine PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include  # Путь к Engine.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/include  # Для #include <GLFW/glfw3.h>
        ${CMAKE_CURRENT_SOURCE_DIR}/src  # Для приватных заголовков
)

# Связать с GLFW и системными библиотеками
target_link_libraries(engine PRIVATE
    glfw  # статическая библиотека GLFW
)

target_link_libraries(engine PRIVATE
    opengl32.lib
    gdi32.lib
)
    
# Определить макрос для статической линковки
target_compile_definitions(engine PRIVATE GLFW_STATIC)

# Подключаю pch - precompiled headers
target_precompile_headers(engine PRIVATE
    <${CMAKE_CURRENT_SOURCE_DIR}/src/pch/engine_pch.h>
)