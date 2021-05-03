#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>

class Utils
{
public:
    Utils();
    static long GetTime();
    static int GetLCDWidth();
    static int GetLCDHeight();
};

#endif // UTILS_H
