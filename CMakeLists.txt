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
    src/font_back_decorator.cpp
    src/sound.cpp
    src/main_menu_sound.cpp
    src/level_builder.cpp
    src/level_factory.cpp
    src/main_level_factory.cpp
    src/main_level_builder.cpp
    src/level_text_reader.cpp
    src/simple_level_text_reader.cpp
    src/types_sprites.cpp
    src/landscape_type.cpp
    src/room_type.cpp
    src/monster_type.cpp )

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
    inc/font_back_decorator.h
    inc/sound.h
    inc/main_menu_sound.h
    inc/level_builder.h
    inc/level_factory.h
    inc/main_level_factory.h
    inc/main_level_builder.h
    inc/level_text_reader.h
    inc/simple_level_text_reader.h
    inc/types_sprites.h
    inc/landscape_type.h
    inc/room_type.h
    inc/monster_type.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDE})

add_subdirectory(SFML)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)


