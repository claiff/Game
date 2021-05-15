#include "../inc/world.h"
#include "../inc/utils.h"
#include "../inc/main_menu_state.h"

static const int GAME_WIDTH = 500;
static const int GAME_HEIGHT = 364;

World::World()
{
    sf::Vector2i tempCenter(Utils::GetLCDWidth()/2 - GAME_WIDTH/2,
                            Utils::GetLCDHeight()/2 - GAME_HEIGHT/2);
    m_prev_time = Utils::GetTime();
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "SFML works!");
    window->setPosition(tempCenter);
    m_state_game = MainMenuState::GetInstance(window.get());
};

void World::Redraw()
{
    if(!IsRateTime())
    {
        return;
    }
    if (sf::Keyboard::isKeyPressed(INPUT_UP))
    {
        m_state_game->PushUp(this);
    }
    if (sf::Keyboard::isKeyPressed(INPUT_DOWN))
    {
        m_state_game->PushDown();
    }
    if (sf::Keyboard::isKeyPressed(INPUT_LEFT))
    {
        m_state_game->PushLeft();
    }
    if (sf::Keyboard::isKeyPressed(INPUT_RIGHT))
    {
        m_state_game->PushRight();
    }
    if (sf::Keyboard::isKeyPressed(INPUT_USE))
    {
        m_state_game->PushUse(this);
    }
    m_state_game->DrawContext();
    window->display();
}

bool World::IsOpen()
{
    return window->isOpen();
}

bool World::IsRateTime() const
{
    auto time = Utils::GetTime();
    auto rate_time = 1000 / FPS_RATE;
    auto diff = time - m_prev_time;
    return diff > rate_time;
}

void World::ChangeState(StateGame *newState)
{
    m_state_game = newState;
}


