cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE DEBUG)
project(TestGame)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(SFML/include)
set(SOURCES
    src/main.cpp
    src/weapon.cpp
    src/player.cpp
    src/world.cpp
    src/state_game.cpp
    src/main_menu_state.cpp
    src/utils.cpp
    src/font.cpp
    src/font_zelda.cpp
    src/load_game_state.cpp
    src/main_level_state.cpp
    src/decorator_font.cpp
    src/font_back_decorator.cpp)
set(INCLUDE
    inc/weapon.h
    inc/player.h
    inc/world.h
    inc/state_game.h
    inc/main_menu_state.h
    inc/utils.h
    inc/font.h
    inc/font_zelda.h
    inc/main_level_state.h
    inc/load_game_state.h
    inc/decorator_font.h
    inc/font_back_decorator.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDE})

add_subdirectory(SFML)
target_link_libraries(${PROJECT_NAME} sfml-graphics)


