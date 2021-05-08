#ifndef WORLD_H
#define WORLD_H

#include "memory"
#include "mainmenustate.h"

static const int FPS_RATE = 60;
static const sf::Keyboard::Key INPUT_UP = sf::Keyboard::W;
static const sf::Keyboard::Key INPUT_DOWN = sf::Keyboard::S;
static const sf::Keyboard::Key INPUT_LEFT = sf::Keyboard::A;
static const sf::Keyboard::Key INPUT_RIGHT = sf::Keyboard::D;

class World
{
public:
    World();
    void Redraw();
    bool IsOpen();
private:
    long m_prev_time;
    std::shared_ptr<sf::RenderWindow> window;
    StateGame *m_state_game;

    long GetTime();
    bool IsRateTime();
};

#endif // WORLD_H
