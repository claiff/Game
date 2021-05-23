//
// Created by claiff on 5/15/21.
//

#include "../inc/load_game_state.h"

std::shared_ptr<LoadGameState> LoadGameState::mInstance = nullptr;

LoadGameState::LoadGameState(sf::RenderWindow *window) : StateGame(window)
{
}

LoadGameState::~LoadGameState()
{

}

void LoadGameState::PushUp(World *world)
{

}

void LoadGameState::RealizeUp(World *world)
{

}

void LoadGameState::PushDown(World *world)
{

}

void LoadGameState::RealizeDown(World *world)
{

}

void LoadGameState::PushLeft(World *world)
{

}

void LoadGameState::RealizeLeft(World *world)
{

}

void LoadGameState::PushRight(World *world)
{

}

void LoadGameState::RealizeRight(World *world)
{

}

void LoadGameState::PushUse(World *world)
{

}

void LoadGameState::DrawContext()
{

}

std::shared_ptr<LoadGameState> LoadGameState::GetInstance(sf::RenderWindow *window)
{
    if(!mInstance)
    {
        mInstance = std::make_shared<LoadGameState>(window);
    }
    return mInstance;
}
