cmake_minimum_required(VERSION 3.15)
project(engine)

set(SOURCES 
    src/Engine.cpp 
    src/Sprite.cpp
    src/Log.cpp
)

set(HEADERS 
    include/engine/Engine.hpp 
    src/Sprite.hpp
    src/Log.hpp
)

set(GRAPHICS_FILES 
    include/graphics/Graphics.hpp 
    src/graphics/Graphics.cpp
)

# Настройки GLFW (только если используем add_subdirectory)
set(GLFW_BUILD_STATIC ON CACHE BOOL "Build static GLFW library")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build GLFW documentation")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build GLFW examples")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build GLFW tests")

# Добавляем поддиректории (один раз!)
add_subdirectory(libs/glfw)
add_subdirectory(libs/spdlog)

# Создаем библиотеку Glad
add_library(glad STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/src/glad.c
)

# Создаем основную библиотеку
add_library(engine STATIC
    ${SOURCES} 
    ${HEADERS} 
    src/pch/engine_pch.h
    src/graphics/Graphics.cpp
)

# Группировка файлов
source_group("Source Files" FILES ${SOURCES})
source_group("Header Files" FILES ${HEADERS})
source_group("Graphics Files" FILES ${GRAPHICS_FILES})

# Директории include
target_include_directories(engine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include
)

target_include_directories(glad PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include
)

# Линковка библиотек
target_link_libraries(engine PRIVATE
    glad
    glfw  # из add_subdirectory
    spdlog
)

if(WIN32)
    find_package(OpenGL REQUIRED)
    target_link_libraries(engine PUBLIC OpenGL::GL)
endif()
    
# Определить макрос для статической линковки
target_compile_definitions(engine PRIVATE 
    GLFW_STATIC
)

# Precompiled headers
target_precompile_headers(engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pch/engine_pch.h
)