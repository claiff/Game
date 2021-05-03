#include "../inc/world.h"
#include "../inc/utils.h"

static const int GAME_WIDTH = 500;
static const int GAME_HEIGHT = 364;

World::World()
{
    sf::Vector2i tempCenter(Utils::GetLCDWidth()/2 - GAME_WIDTH/2,
                            Utils::GetLCDHeight()/2 - GAME_HEIGHT/2);
    m_prev_time = Utils::GetTime();
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "SFML works!");
    window->setPosition(tempCenter);
    m_state_game = new MainMenuState(window.get());
};

void World::Redraw()
{
    window->display();
    if(!IsRateTime())
    {
        return;
    }
    m_state_game->DrawContext();
}

bool World::IsOpen()
{
    return window->isOpen();
}

bool World::IsRateTime()
{
    auto time = Utils::GetTime();
    auto rate_time = 1000 / FPS_RATE;
    auto diff = time - m_prev_time;
    return diff > rate_time;
}
