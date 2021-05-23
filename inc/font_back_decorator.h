//
// Created by claiff on 5/15/21.
//

#ifndef TESTGAME_FONT_BACK_DECORATOR_H
#define TESTGAME_FONT_BACK_DECORATOR_H

#include "decorator_font.h"

class FontBackDecorator : public DecoratorFont
{
public:
    FontBackDecorator(Font *font);

    void DrawText(sf::RenderWindow *window, const std::string &text, sf::Color color, int x, int y) override;

    void DrawMultiText(sf::RenderWindow *window, const std::vector<std::pair<std::string, sf::Color>> &text_color, int x, int y) override;

    virtual ~FontBackDecorator();

    std::pair<float, float> GetPosition(const sf::Rect<int> &rect) const;

    std::pair<float, float> GetFactorScale(const sf::Rect<int> &rect) const;
};


#endif //TESTGAME_FONT_BACK_DECORATOR_H
