#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../inc/stategame.h"

class MainMenuState : public StateGame
{
public:
    explicit MainMenuState(sf::RenderWindow* window);
    virtual ~MainMenuState() override;

    void DrawContext() override;
    void PushUp() override;
    void PushDown() override;
    void PushLeft() override;
    void PushRight() override;
private:
    std::vector<sf::Sprite> m_menu_array;
    uint8_t m_pos_menu;
};

#endif // MAINMENUSTATE_H
