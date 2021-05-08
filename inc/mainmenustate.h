#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../inc/stategame.h"
#include "../inc/utils.h"
#include "../inc/FontZelda.h"

#include <cmath>

static const sf::Color ACTIVE_MENU_COLOR = sf::Color::Red;
static const sf::Color UNACTIVE_MENU_COLOR = sf::Color::White;
static const int FREEZE_TIME = 200;
static const int START_DRAW_LEG_X = 200;
static const int START_DRAW_LEG_Y = 100;
static const int INDENT_LEGEND = 40;

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

    void PushUse() override;

private:
    std::unique_ptr<Font> m_font;

    std::vector<std::pair<std::string, sf::Color> > m_menu_array;
    int8_t m_pos_menu;
    sf::Sprite m_menu_backS;
    sf::Texture menu_backT;

    void ResetMenu();
    void IncMenu();
    void DecMenu();
    bool IsTimePressButton(long& prev_time);
};

#endif // MAINMENUSTATE_H
