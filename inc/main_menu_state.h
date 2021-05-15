//
// Created by claiff on 5/15/21.
//

#ifndef TESTGAME_MAIN_MENU_STATE_H
#define TESTGAME_MAIN_MENU_STATE_H

#include "state_game.h"
#include "font.h"
#include "memory"

static const char *const PATH_MAIN_BACK = "../Texture/Menu/main.png";
static const sf::Color UN_ACTIVE_COLOR = sf::Color::White;
static const sf::Color ACTIVE_COLOR = sf::Color::Red;


class MainMenuState : public StateGame
{
public:
    MainMenuState(sf::RenderWindow *window);
    static std::shared_ptr<MainMenuState> GetInstance(sf::RenderWindow *window);
    void PushUp(World *world) override;
    void PushDown(World *world) override;
    void PushLeft(World *world) override;
    void PushRight(World *world) override;
    void PushUse(World *world) override;
    void DrawContext() override;
    virtual ~MainMenuState();
private:
    static std::shared_ptr<MainMenuState> mInstance;
    std::shared_ptr<Font> m_font;
    std::vector<std::pair<std::string, sf::Color>> text_and_color;
    void DrawMainBack();

    void AddTextAndColor(const std::string &text, const sf::Color &color);
};


#endif //TESTGAME_MAIN_MENU_STATE_H
