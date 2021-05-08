#include "../inc/utils.h"
#include <chrono>

Utils::Utils()
{
}

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

