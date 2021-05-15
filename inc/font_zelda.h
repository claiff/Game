//
// Created by claiff on 5/15/21.
//

#ifndef TESTGAME_FONT_ZELDA_H
#define TESTGAME_FONT_ZELDA_H

static const int LETTER_HEIGHT = 16;
static const int SCALE_FACTOR = 2;
static const int LINE_HEIGHT = 30;

static const int SHIFT_LETTER = 3;

#include "font.h"
#include "unordered_map"
struct CharInfo
{
    int x;
    int y;
    uint8_t size;
};
class FontZelda : public Font
{
public:
    FontZelda();

private:
    std::unordered_map<char, struct CharInfo> mCharInfo;
public:
    void DrawText(sf::RenderWindow *window, const std::string &text, sf::Color color, float x, float y) override;

    void DrawMultiText(sf::RenderWindow *window, const std::vector<std::pair<std::string, sf::Color>> &text_color, float x, float y) override;

private:
    void AddCharInfo(char letter, float x, float y, uint8_t size);
};


#endif //TESTGAME_FONT_ZELDA_H
