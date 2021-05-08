#ifndef STATEGAME_H
#define STATEGAME_H

#include <SFML/Graphics.hpp>
#include "memory"

class StateGame
{
public:
    explicit StateGame(sf::RenderWindow* window);
    virtual ~StateGame();
    virtual void DrawContext() = 0;
    virtual void PushUp() = 0;
    virtual void PushDown() = 0;
    virtual void PushLeft() = 0;
    virtual void PushRight() = 0;
    virtual void PushUse() = 0;
protected:
    sf::RenderWindow* m_window;
};

#endif // STATEGAME_H
