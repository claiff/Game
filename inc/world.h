#ifndef WORLD_H
#define WORLD_H

#include "memory"
#include "state_game.h"
//TODO comment
//TODO Проверить include

static const int FPS_RATE = 60;
static const sf::Keyboard::Key INPUT_UP = sf::Keyboard::W;
static const sf::Keyboard::Key INPUT_DOWN = sf::Keyboard::S;
static const sf::Keyboard::Key INPUT_LEFT = sf::Keyboard::A;
static const sf::Keyboard::Key INPUT_RIGHT = sf::Keyboard::D;
static const sf::Keyboard::Key INPUT_USE = sf::Keyboard::Space;

class World
{
public:
    World();
    void Redraw();
    bool IsOpen();
    void ChangeState(std::shared_ptr<StateGame> newState);
private:
    std::shared_ptr<StateGame> m_state_game;
    long m_prev_time;
    std::shared_ptr<sf::RenderWindow> window;
};

#endif // WORLD_H
