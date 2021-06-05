cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE DEBUG)
project(TestGame)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(SFML/include)
set(MAIN
    main/main.cpp
    main/world.cpp
    main/world.h)
set(STATE
        state/load_game_state.h
        state/load_game_state.cpp
        state/main_level_state.h
        state/main_level_state.cpp
        state/main_menu_state.cpp
        state/main_menu_state.h
        state/state_game.cpp
        state/state_game.h)
set(FONT
        font/decorator_font.cpp
        font/decorator_font.h
        font/font.cpp
        font/font.h
        font/font_back_decorator.cpp
        font/font_back_decorator.h
        font/font_zelda.cpp
        font/font_zelda.h)
set(SOUND
        sound/main_menu_sound.cpp
        sound/main_menu_sound.h
        sound/sound.cpp
        sound/sound.h)
set(LEVELS
        levels/level_builder.cpp
        levels/level_builder.h
        levels/level_factory.cpp
        levels/level_factory.h
        levels/main_level_builder.cpp
        levels/main_level_builder.h
        levels/main_level_factory.cpp
        levels/main_level_builder.h)
set(LEVELS_TYPES
        levels/types/landscape_type.h
        levels/types/landscape_type.cpp
        levels/types/monster_type.cpp
        levels/types/monster_type.h
        levels/types/room_type.cpp
        levels/types/room_type.h
        levels/types/types_sprites.cpp
        levels/types/types_sprites.h)
set(LEVELS_READER
        levels/reader/level_text_reader.cpp
        levels/reader/level_text_reader.h
        levels/reader/simple_level_text_reader.cpp
        levels/reader/simple_level_text_reader.h)
set(OTHER
       other/utils.cpp
       other/utils.h)

add_executable(${PROJECT_NAME} ${MAIN}
                               ${STATE}
                               ${FONT}
                               ${SOUND}
                               ${LEVELS}
                               ${LEVELS_TYPES}
                               ${LEVELS_READER}
                               ${OTHER})

add_subdirectory(SFML)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)


