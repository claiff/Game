//
// Created by claiff on 5/15/21.
//

#include "main_level_state.h"

#include <utility>

std::shared_ptr<MainLevelState> MainLevelState::mInstance = nullptr;

MainLevelState::MainLevelState(sf::RenderWindow *window, LevelFactoryPtr levelFactory):
        StateGame(window),
        mLevelFactory(std::move(levelFactory))
{}

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
    auto zone = mLevelFactory->CreateZone();
    for(const auto& sprite: zone)
    {
        m_window->draw(sprite.first);
    }
}

std::shared_ptr<MainLevelState> MainLevelState::GetInstance(sf::RenderWindow *window, LevelFactoryPtr const& levelFactory)
{
    if(!mInstance)
    {
        mInstance = std::make_shared<MainLevelState>(window, levelFactory);
    }
    return mInstance;
}


