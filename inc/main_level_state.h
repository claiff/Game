//
// Created by claiff on 5/15/21.
//

#ifndef TESTGAME_MAIN_LEVEL_STATE_H
#define TESTGAME_MAIN_LEVEL_STATE_H

#include "state_game.h"

class MainLevelState : public StateGame
{
public:
    MainLevelState(sf::RenderWindow *window);
    static std::shared_ptr<MainLevelState> GetInstance(sf::RenderWindow *window);
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
    virtual ~MainLevelState();

private:
    static std::shared_ptr<MainLevelState> mInstance;
};


#endif //TESTGAME_MAIN_LEVEL_STATE_H
