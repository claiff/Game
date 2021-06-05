//
// Created by claiff on 5/15/21.
//

#ifndef TESTGAME_FONT_BACK_DECORATOR_H
#define TESTGAME_FONT_BACK_DECORATOR_H

#include "decorator_font.h"
//TODO comment
//TODO Проверить include
class FontBackDecorator : public DecoratorFont
{
public:
    FontBackDecorator(FontPtr const& font);
    virtual ~FontBackDecorator() = default;
    void DrawText(sf::RenderWindow *window, std::string const& text, sf::Color const& color, int x, int y) override;
    void DrawMultiText(sf::RenderWindow *window,  std::vector<std::pair<std::string, sf::Color>> const& text_color, int x, int y) override;
    static std::pair<float, float> GetPosition(sf::Rect<int> const& rect) ;
    static std::pair<float, float> GetFactorScale(sf::Rect<int> const& rect) ;
};


#endif //TESTGAME_FONT_BACK_DECORATOR_H
