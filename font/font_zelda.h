//
// Created by claiff on 5/15/21.
//

#ifndef TESTGAME_FONT_ZELDA_H
#define TESTGAME_FONT_ZELDA_H
//TODO перенести в cpp
//TODO comment
//TODO Проверить include
static const int LETTER_HEIGHT = 16;
static const int SCALE_FACTOR = 2;
static const int LINE_HEIGHT = 30;
static const int SHIFT_LETTER = 3;
static const int SPACE_WIDTH = 4;

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

public:
    void DrawText(sf::RenderWindow *window, std::string const& text, sf::Color const& color, int x, int y) override;
    void DrawMultiText(sf::RenderWindow *window, std::vector<std::pair<std::string, sf::Color>> const& text_color, int x, int y) override;
    sf::Rect<int> GetSizeMultiText(std::vector<std::pair<std::string, sf::Color>> const& text_color, int x, int y) override;

private:
    void AddCharInfo(char letter, int x, int y, uint8_t size);
    std::unordered_map<char, struct CharInfo> mCharInfo;
    int GetSizeText(const std::pair<std::string, sf::Color> &line);
};


#endif //TESTGAME_FONT_ZELDA_H
