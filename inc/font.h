//
// Created by claiff on 5/8/21.
//

#ifndef TESTGAME_FONT_H
#define TESTGAME_FONT_H


#include <string>
#include <SFML/Graphics.hpp>

class Font
{
public:
    Font();
    virtual void DrawText(sf::RenderWindow *window, const std::string &text, sf::Color color, float x, float y) = 0;
    virtual void DrawMultiText(sf::RenderWindow *window, const std::vector<std::pair<std::string, sf::Color> > &text_color, float x, float y) = 0;
    virtual sf::Rect<float> GetSizeMultiText(const std::vector<std::pair<std::string, sf::Color>> &text_color, float x, float y);
    virtual ~Font();
};


#endif //TESTGAME_FONT_H
