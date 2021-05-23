//
// Created by claiff on 5/15/21.
//

#include "../inc/main_level_state.h"
std::shared_ptr<MainLevelState> MainLevelState::mInstance = nullptr;
MainLevelState::MainLevelState(sf::RenderWindow *window) : StateGame(window)
{
}

MainLevelState::~MainLevelState()
{

}

void MainLevelState::PushUp(World *world)
{

}

void MainLevelState::RealizeUp(World *world)
{

}

void MainLevelState::PushDown(World *world)
{

}

void MainLevelState::RealizeDown(World *world)
{

}

void MainLevelState::PushLeft(World *world)
{

}

void MainLevelState::RealizeLeft(World *world)
{

}

void MainLevelState::PushRight(World *world)
{

}

void MainLevelState::RealizeRight(World *world)
{

}

void MainLevelState::PushUse(World *world)
{

}

void MainLevelState::DrawContext()
{

}

std::shared_ptr<MainLevelState> MainLevelState::GetInstance(sf::RenderWindow *window)
{
    if(!mInstance)
    {
        mInstance = std::make_shared<MainLevelState>(window);
    }
    return mInstance;
}
