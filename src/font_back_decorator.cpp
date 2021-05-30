//
// Created by claiff on 5/15/21.
//

#include "../inc/font_back_decorator.h"

static const int BORDER_WIDTH = 20;
static const int BACK_WIDTH = 240;
static const int BACK_HEIGHT = 71;
static const int BACK_X = 0;
static const int BACK_Y = 49;
static const char *const FONT_PATH = "../Texture/Menu/font.png";

FontBackDecorator::FontBackDecorator(FontPtr const& font) : DecoratorFont(font)
{}

void FontBackDecorator::DrawText(sf::RenderWindow *window, const std::string &text, const sf::Color &color, int x, int y)
{}

void FontBackDecorator::DrawMultiText(sf::RenderWindow *window, std::vector<std::pair<std::string, sf::Color>> const& text_color, int x, int y)
{
    auto rect = mFont->GetSizeMultiText(text_color, x, y);
    sf::Texture mainBackT;
    sf::Sprite mainBackS;
    mainBackT.loadFromFile(FONT_PATH);
    mainBackS.setTexture(mainBackT);

    mainBackS.setTextureRect(sf::IntRect(BACK_X, BACK_Y, BACK_WIDTH, BACK_HEIGHT));

    auto pos = GetPosition(rect);
    auto scale = GetFactorScale(rect);

    mainBackS.setPosition(pos.first, pos.second);
    mainBackS.setScale(scale.first, scale.second);
    window->draw(mainBackS);
    mFont->DrawMultiText(window, text_color, x, y);
}

std::pair<float, float> FontBackDecorator::GetPosition(const sf::Rect<int> &rect)
{
    auto position_x = rect.left - BORDER_WIDTH;
    auto position_y = rect.top - BORDER_WIDTH;
    return {position_x, position_y};
}

std::pair<float, float> FontBackDecorator::GetFactorScale(const sf::Rect<int> &rect)
{
    auto scale_x = static_cast<float>(rect.width + BORDER_WIDTH * 2) / BACK_WIDTH;
    auto scale_y = static_cast<float>(rect.height + BORDER_WIDTH * 2) / BACK_HEIGHT;
    return {scale_x, scale_y};
}
