#ifndef WORLD_H
#define WORLD_H

#include "../state/state_game.h"

//TODO comment

class World
{
public:
    World();
    void Redraw();
    bool IsOpen() const;
    void ChangeState(std::shared_ptr<StateGame> newState);
private:
    std::shared_ptr<StateGame> m_state_game;
    long m_prev_time;
    std::shared_ptr<sf::RenderWindow> window;
};

#endif // WORLD_H
