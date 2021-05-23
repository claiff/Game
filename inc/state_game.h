//
// Created by claiff on 5/15/21.
//

#ifndef TESTGAME_STATE_GAME_H
#define TESTGAME_STATE_GAME_H

#include "SFML/Graphics.hpp"
#include "memory"

class World;
class StateGame
{
public:
    StateGame(sf::RenderWindow *window);

    virtual void PushUp(World *world) = 0;
    virtual void RealizeUp(World *world) = 0;

    virtual void PushDown(World *world) = 0;
    virtual void RealizeDown(World *world) = 0;

    virtual void PushLeft(World *world) = 0;
    virtual void RealizeLeft(World *world) = 0;

    virtual void PushRight(World *world) = 0;
    virtual void RealizeRight(World *world) = 0;

    virtual void PushUse(World *world) = 0;

    virtual void DrawContext() = 0;
    virtual ~StateGame();

protected:
    sf::RenderWindow *m_window;
};


#endif //TESTGAME_STATE_GAME_H
