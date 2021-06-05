#pragma once

//TODO comment
#include "string"
class Utils
{
public:
    Utils() = default;
    static long GetTime();
    static int GetLCDWidth();
    static int GetLCDHeight();
    static const char * GetFontTexturePath();
    static const char * GetMainTexturePath();
    static const char * GetMainMusicPath();
    static const char * GetLevel1Path();
    static const char * GetLevelTexturePath();

};
