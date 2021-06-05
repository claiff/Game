//
// Created by claiff on 5/15/21.
//

#include "font_zelda.h"
#include "../other/utils.h"
FontZelda::FontZelda()
{
    AddCharInfo('A', 0, 0, 8);
    AddCharInfo('a', 9, 0, 6);
    AddCharInfo('B', 16, 0, 7);
    AddCharInfo('b', 25, 0, 6);
    AddCharInfo('C', 32, 0, 7);
    AddCharInfo('c', 41, 0, 5);
    AddCharInfo('D', 48, 0, 7);
    AddCharInfo('d', 57, 0, 6);
    AddCharInfo('E', 65, 0, 6);
    AddCharInfo('e', 73, 0, 6);
    AddCharInfo('F', 81, 0, 6);
    AddCharInfo('f', 89, 0, 5);
    AddCharInfo('G', 96, 0, 7);
    AddCharInfo('g', 105, 0, 6);
    AddCharInfo('H', 113, 0, 6);
    AddCharInfo('h', 121, 0, 6);
    AddCharInfo('I', 129, 0, 6);
    AddCharInfo('i', 139, 0, 2);
    AddCharInfo('J', 145, 0, 6);
    AddCharInfo('j', 153, 0, 5);
    AddCharInfo('K', 161, 0, 6);
    AddCharInfo('k', 169, 0, 6);
    AddCharInfo('L', 177, 0, 6);
    AddCharInfo('l', 186, 0, 3);
    AddCharInfo('M', 192, 0, 8);
    AddCharInfo('m', 200, 0, 8);
    AddCharInfo('N', 0, 16, 8);
    AddCharInfo('n', 9, 16, 5);
    AddCharInfo('O', 17, 16, 6);
    AddCharInfo('o', 25, 16, 6);
    AddCharInfo('P', 33, 16, 6);
    AddCharInfo('p', 41, 16, 6);
    AddCharInfo('Q', 49, 16, 6);
    AddCharInfo('q', 57, 16, 6);
    AddCharInfo('R', 65, 16, 6);
    AddCharInfo('r', 73, 16, 6);
    AddCharInfo('S', 81, 16, 6);
    AddCharInfo('s', 90, 16, 4);
    AddCharInfo('T', 96, 16, 8);
    AddCharInfo('t', 106, 16, 4);
    AddCharInfo('U', 112, 16, 8);
    AddCharInfo('u', 122, 16, 5);
    AddCharInfo('V', 128, 16, 8);
    AddCharInfo('v', 137, 16, 6);
    AddCharInfo('W', 144, 16, 8);
    AddCharInfo('w', 152, 16, 7);
    AddCharInfo('X', 161, 16, 6);
    AddCharInfo('x', 169, 16, 5);
    AddCharInfo('Y', 177, 16, 6);
    AddCharInfo('y', 185, 16, 5);
    AddCharInfo('Z', 192, 16, 8);
    AddCharInfo('z', 202, 16, 4);
    AddCharInfo(' ', 206, 16, SPACE_WIDTH);
}

void FontZelda::AddCharInfo(char letter, int x, int y, uint8_t size)
{
    mCharInfo[letter].x = x;
    mCharInfo[letter].y = y;
    mCharInfo[letter].size = size;
}

void FontZelda::DrawText(sf::RenderWindow *window, std::string const& text, sf::Color const& color, int x, int y)
{
    sf::Texture mainBackT;
    sf::Sprite mainBackS;
    int letter_shift = 0;
    auto path = Utils::GetFontTexturePath();
    mainBackT.loadFromFile(path);
    mainBackS.setTexture(mainBackT);

    for(auto letter : text)
    {
        auto letter_x = mCharInfo[letter].x;
        auto letter_y = mCharInfo[letter].y;
        auto size = mCharInfo[letter].size;

        mainBackS.setTextureRect(sf::IntRect(letter_x , letter_y, size, LETTER_HEIGHT));
        mainBackS.setPosition(static_cast<float>(x + letter_shift), static_cast<float>(y));
        mainBackS.setScale(SCALE_FACTOR, SCALE_FACTOR);
        mainBackS.setColor(color);

        window->draw(mainBackS);
        letter_shift += size * SCALE_FACTOR + SHIFT_LETTER;
    }
}

void FontZelda::DrawMultiText(sf::RenderWindow *window, std::vector<std::pair<std::string, sf::Color>> const& text_color, int x, int y)
{
    auto local_y = y;
    for(const auto& line_text : text_color)
    {
        auto text = line_text.first;
        auto color = line_text.second;
        DrawText(window, text, color, x, local_y);
        local_y += LINE_HEIGHT;
    }
}

sf::Rect<int> FontZelda::GetSizeMultiText( std::vector<std::pair<std::string, sf::Color>> const& text_color, int x, int y)
{
    int height = 0;
    int width = 0;

    for(auto& line : text_color)
    {
        auto temp_width = GetSizeText(line);
        if(temp_width > width)
        {
            width = temp_width;
        }
        height += LINE_HEIGHT;
    }
    return {x, y, width, height};
}

int FontZelda::GetSizeText( std::pair<std::string, sf::Color> const& line)
{
    int size = 0;
    for(auto& letter : line.first)
    {
        size += mCharInfo[letter].size * SCALE_FACTOR;
        size += SHIFT_LETTER;
    }
    return size;
}
