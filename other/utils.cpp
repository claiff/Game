#include "utils.h"
#include <chrono>
#include <SFML/Graphics.hpp>

static const char *const PATH_MAIN_BACK = "../texture/Menu/main.png";
static const char *const PATH_FONT = "../texture/Menu/font.png";
static const char *const MUSIC_PATH = "../sound/music/Nintendo - The Legend Of Zelda Theme Song.wav";
static const char *const PATH_LEVEL1 = "../levels/Levels/level1";
static const char *const PATH_LEVELS = "../texture/Levels/Overworld.png";

long Utils::GetTime()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int Utils::GetLCDWidth()
{
    return static_cast<int>(sf::VideoMode::getDesktopMode().width);

}

int Utils::GetLCDHeight()
{
    return static_cast<int>(sf::VideoMode::getDesktopMode().height);
}

const char * Utils::GetFontTexturePath()
{
    return PATH_FONT;
}

const char * Utils::GetMainTexturePath()
{
    return PATH_MAIN_BACK;
}

const char * Utils::GetMainMusicPath()
{
    return MUSIC_PATH;
}

const char *Utils::GetLevel1Path()
{
    return PATH_LEVEL1;
}

const char *Utils::GetLevelTexturePath()
{
    return PATH_LEVELS;
}

