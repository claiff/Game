#ifndef WORLD_H
#define WORLD_H

#include "memory"
#include "mainmenustate.h"

static const int FPS_RATE = 60;

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
