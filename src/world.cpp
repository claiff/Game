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
    window->setFramerateLimit(FPS_RATE);
};

void World::Redraw()
{
    sf::Event event;
    window->pollEvent(event);
    if (event.type == sf::Event::KeyReleased && event.key.code == INPUT_UP)
    {
        m_state_game->RealizeUp(this);
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == INPUT_DOWN)
    {
        m_state_game->RealizeDown(this);
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == INPUT_LEFT)
    {
        m_state_game->RealizeLeft(this);
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == INPUT_RIGHT)
    {
        m_state_game->RealizeRight(this);
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == INPUT_UP)
    {
        m_state_game->PushUp(this);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == INPUT_DOWN)
    {
        m_state_game->PushDown(this);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == INPUT_LEFT)
    {
        m_state_game->PushLeft(this);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == INPUT_RIGHT)
    {
        m_state_game->PushRight(this);
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == INPUT_USE)
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

void World::ChangeState(std::shared_ptr<StateGame> newState)
{
    m_state_game = std::move(newState);
}


