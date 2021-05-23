//
// Created by claiff on 5/15/21.
//

#include "../inc/font_back_decorator.h"
static const int BORDER_WIDTH = 20;
FontBackDecorator::FontBackDecorator(Font *font) : DecoratorFont(font)
{
}

FontBackDecorator::~FontBackDecorator()=default;

void FontBackDecorator::DrawText(sf::RenderWindow *window, const std::string &text, sf::Color color, int x, int y)
{}

void FontBackDecorator::DrawMultiText(sf::RenderWindow *window, const std::vector<std::pair<std::string, sf::Color>> &text_color, int x, int y)
{
    auto rect = m_font->GetSizeMultiText(text_color, x, y);
    sf::Texture mainBackT;
    sf::Sprite mainBackS;
    mainBackT.loadFromFile("../Texture/Menu/font.png");
    mainBackS.setTexture(mainBackT);

    mainBackS.setTextureRect(sf::IntRect(0 , 49, 240, 71));

    auto pos = GetPosition(rect);
    auto scale = GetFactorScale(rect);

    mainBackS.setPosition(pos.first, pos.second);
    mainBackS.setScale(scale.first, scale.second);
    window->draw(mainBackS);
    m_font->DrawMultiText(window, text_color, x, y);
}

std::pair<float, float> FontBackDecorator::GetFactorScale(const sf::Rect<int> &rect) const
{
    auto scale_x = static_cast<float>(rect.width + BORDER_WIDTH * 2) / 240;
    auto scale_y = static_cast<float>(rect.height + BORDER_WIDTH * 2) / 71;
    return {scale_x, scale_y};
}

std::pair<float, float> FontBackDecorator::GetPosition(const sf::Rect<int> &rect) const
{
    auto position_x = rect.left - BORDER_WIDTH;
    auto position_y = rect.top - BORDER_WIDTH;
    return {position_x, position_y};
}
