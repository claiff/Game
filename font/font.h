//
// Created by claiff on 5/8/21.
//

#ifndef TESTGAME_FONT_H
#define TESTGAME_FONT_H

//TODO comment
//TODO Проверить include
#include <string>
#include <SFML/Graphics.hpp>
#include "memory"
class Font
{
public:
    Font() = default;
    virtual ~Font() = default;
    virtual void DrawText(sf::RenderWindow *window, std::string const& text, sf::Color const& color, int x, int y) = 0;
    virtual void DrawMultiText(sf::RenderWindow *window, std::vector<std::pair<std::string, sf::Color> > const& text_color, int x, int y) = 0;
    virtual sf::Rect<int> GetSizeMultiText(std::vector<std::pair<std::string, sf::Color>> const& text_color, int x, int y);
};
using FontPtr = std::shared_ptr<Font>;

#endif //TESTGAME_FONT_H
