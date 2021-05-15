//
// Created by claiff on 5/15/21.
//

#include "../inc/font_zelda.h"

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
    AddCharInfo('m', 200, 0, 208);
    AddCharInfo('N', 0, 16, 8);
    AddCharInfo('n', 9, 16, 5);
    AddCharInfo('O', 17, 16, 6);
    AddCharInfo('o', 25, 16, 6);
    AddCharInfo('P', 33, 16, 6);
    AddCharInfo('p', 41, 16, 6);
}

void FontZelda::AddCharInfo(char letter, float x, float y, uint8_t size)
{
    mCharInfo[letter].x = x;
    mCharInfo[letter].y = y;
    mCharInfo[letter].size = size;
}

void FontZelda::DrawText(sf::RenderWindow *window, const std::string &text, sf::Color color, float x, float y)
{
    sf::Texture mainBackT;
    sf::Sprite mainBackS;
    float letter_shift = 0;
    mainBackT.loadFromFile("../Texture/Menu/font.png");
    mainBackS.setTexture(mainBackT);

    for(auto letter : text)
    {
        auto letter_x = mCharInfo[letter].x;
        auto letter_y = mCharInfo[letter].y;
        auto size = mCharInfo[letter].size;

        mainBackS.setTextureRect(sf::IntRect(letter_x , letter_y, size, LETTER_HEIGHT));
        mainBackS.setPosition(x + letter_shift, y);
        mainBackS.setScale(SCALE_FACTOR, SCALE_FACTOR);

        window->draw(mainBackS);
        letter_shift += size * SCALE_FACTOR + SHIFT_LETTER;
    }
}

void FontZelda::DrawMultiText(sf::RenderWindow *window, const std::vector<std::pair<std::string, sf::Color>> &text_color, float x, float y)
{
    auto local_y = y;
    for(auto line_text : text_color)
    {
        auto text = line_text.first;
        auto color = line_text.second;
        DrawText(window, text, color, x, local_y);
        local_y += LINE_HEIGHT;
    }
}
