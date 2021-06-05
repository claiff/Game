//
// Created by claiff on 5/15/21.
//

#ifndef TESTGAME_LOAD_GAME_STATE_H
#define TESTGAME_LOAD_GAME_STATE_H

#include "state_game.h"
//TODO comment
//TODO Проверить include
class LoadGameState : public StateGame
{
public:
    explicit LoadGameState(sf::RenderWindow *window);
    static std::shared_ptr<LoadGameState> GetInstance(sf::RenderWindow *window);
    void PushUp(World *world) override;
    void RealizeUp(World *world) override;
    void PushDown(World *world) override;
    void RealizeDown(World *world) override;
    void PushLeft(World *world) override;
    void RealizeLeft(World *world) override;
    void PushRight(World *world) override;
    void RealizeRight(World *world) override;
    void PushUse(World *world) override;
    void DrawContext() override;
    ~LoadGameState() override = default;

private:
    static std::shared_ptr<LoadGameState> mInstance;
};


#endif //TESTGAME_LOAD_GAME_STATE_H
