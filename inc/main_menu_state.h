//
// Created by claiff on 5/15/21.
//

#ifndef TESTGAME_MAIN_MENU_STATE_H
#define TESTGAME_MAIN_MENU_STATE_H

#include "state_game.h"
#include "font.h"
#include "decorator_font.h"
#include "memory"

static const char *const PATH_MAIN_BACK = "../Texture/Menu/main.png";
static const sf::Color UN_ACTIVE_COLOR = sf::Color::White;
static const sf::Color ACTIVE_COLOR = sf::Color::Red;
static const sf::Vector2<int> MENU_COORDINATE = {200,140};

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

    void RealizeDown(World *world) override;

    void RealizeRight(World *world) override;

    void RealizeLeft(World *world) override;

    void RealizeUp(World *world) override;

    void DrawContext() override;
    virtual ~MainMenuState();
private:
    void DrawMainBack();

    static std::shared_ptr<MainMenuState> mInstance;
    std::shared_ptr<DecoratorFont> mDecoratorFont;
    std::vector<std::pair<std::string, sf::Color>> m_text_and_color;
    int8_t mPosition;

    void ResetPosition();

    void SetPosition();

    void SetText(const std::string &text);

    void IncrementPosition();

    void DecrementPosition();
};


#endif //TESTGAME_MAIN_MENU_STATE_H
