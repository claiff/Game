#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../inc/stategame.h"
#include "../inc/utils.h"

static const sf::Color ACTIVE_MENU_COLOR = sf::Color::Red;
static const sf::Color UNACTIVE_MENU_COLOR = sf::Color::White;
static const int FREEZE_TIME = 200;

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
    int8_t m_pos_menu;
    sf::Sprite m_menu_backS;
    sf::Texture menu_backT;

    //Текстуры надписей меню
    sf::Texture m_menu_new_gameT;
    sf::Texture m_menu_load_gameT;
    sf::Texture m_menu_exit_gameT;

    //Спрайты надписей меню
    sf::Sprite m_menu_new_gameS;
    sf::Sprite m_menu_load_gameS;
    sf::Sprite m_menu_exit_gameS;

    void ResetMenu();
    void IncMenu();
    void DecMenu();
    void SetMenu();
    bool IsTimePressButton(long& prev_time);
};

#endif // MAINMENUSTATE_H
