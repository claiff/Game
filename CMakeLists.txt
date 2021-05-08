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
    src/w_pistol.cpp
    src/player.cpp
    src/world.cpp
    src/stategame.cpp
    src/mainmenustate.cpp
    src/utils.cpp
    src/Font.cpp
    src/FontZelda.cpp)
set(INCLUDE
    inc/weapon.h
    inc/w_pistol.h
    inc/player.h
    inc/world.h
    inc/stategame.h
    inc/mainmenustate.h
    inc/utils.h
    inc/Font.h
    inc/FontZelda.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDE})

add_subdirectory(SFML)
target_link_libraries(${PROJECT_NAME} sfml-graphics)


