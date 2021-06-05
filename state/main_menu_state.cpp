//
// Created by claiff on 5/15/21.
//

#include "main_menu_state.h"
#include "../font/font_zelda.h"
#include "load_game_state.h"
#include "main_level_state.h"
#include "../main/world.h"
#include "../font/font_back_decorator.h"
#include "../sound/main_menu_sound.h"
#include "../other/utils.h"
#include "../levels/main_level_factory.h"
#include "../levels/main_level_builder.h"

std::shared_ptr<MainMenuState> MainMenuState::mInstance = nullptr;


MainMenuState::MainMenuState(sf::RenderWindow *window) : StateGame(window)
{
    SetupMusic();
    SetupFont();
}

void MainMenuState::SetupMusic()
{
    auto path = Utils::GetMainMusicPath();
    mSound = std::make_shared<MainMenuSound>(path);
    mSound->SetLoop(true);
    mSound->SetVolume(MUSIC_VOLUME);
    mSound->PlaySound();
}

void MainMenuState::SetupFont()
{
    mFont = std::make_shared<FontZelda>();
    mDecoratorFont = std::make_shared<FontBackDecorator>(mFont);
    SetText("New Game");
    SetText("Load Game");
    SetText("Exit");
    ResetPosition();
}

void MainMenuState::SetText(std::string const &text)
{
    std::pair<std::string, sf::Color> textC;
    textC.first = text;
    textC.second = UN_ACTIVE_COLOR;
    m_text_and_color.emplace_back(textC);
}

void MainMenuState::ResetPosition()
{
    mPosition = 0;
    SetPosition();
}

void MainMenuState::SetPosition()
{
    if(mPosition < 0 || mPosition > m_text_and_color.size())
        return;
    for(int i = 0; i < m_text_and_color.size(); i++)
    {
        if(mPosition == i)
        {
            m_text_and_color[mPosition].second = ACTIVE_COLOR;
        }
        else
        {
            m_text_and_color[i].second = UN_ACTIVE_COLOR;
        }
    }
}

void MainMenuState::PushUp(World *world)
{
}
void MainMenuState::PushDown(World *world)
{}
void MainMenuState::PushLeft(World *world)
{}
void MainMenuState::PushRight(World *world)
{}
void MainMenuState::RealizeLeft(World *world)
{}
void MainMenuState::RealizeRight(World *world)
{}

void MainMenuState::RealizeDown(World *world)
{
    IncrementPosition();
    SetPosition();
}

void MainMenuState::RealizeUp(World *world)
{
    DecrementPosition();
    SetPosition();
}

void MainMenuState::DecrementPosition()
{
    mPosition--;
    if(mPosition < 0)
    {
        mPosition = static_cast<decltype(mPosition)>(m_text_and_color.size() - 1);
    }
}

void MainMenuState::IncrementPosition()
{
    mPosition++;
    if(mPosition >= m_text_and_color.size())
    {
        mPosition = 0;
    }
}

void MainMenuState::PushUse(World *world)
{
    mSound->StopSound();
    switch (mPosition)
    {
        case 0:
            world->ChangeState(MainLevelState::GetInstance(m_window,
                                                         std::make_shared<MainLevelFactory>(std::make_shared<MainLevelBuilder>(),
                                                                                                          m_window->getSize())));
        break;
        case 1:
            world->ChangeState(LoadGameState::GetInstance(m_window));
        break;
        case 2:
            m_window->close();
        break;
    }
}

void MainMenuState::DrawContext()
{
    DrawMainBack();
    mDecoratorFont->DrawMultiText(m_window, m_text_and_color, MENU_COORDINATE.x, MENU_COORDINATE.y);
}

void MainMenuState::DrawMainBack()
{
    sf::Texture mainBackT;
    sf::Sprite mainBackS;
    auto path = Utils::GetMainTexturePath();
    mainBackT.loadFromFile(path);
    mainBackS.setTexture(mainBackT);
    mainBackS.setScale(
            m_window->getSize().x / mainBackS.getLocalBounds().width,
            m_window->getSize().y / mainBackS.getLocalBounds().height);

    m_window->draw(mainBackS);
}

std::shared_ptr<MainMenuState> MainMenuState::GetInstance(sf::RenderWindow *window)
{
    if(!mInstance)
    {
        mInstance = std::make_shared<MainMenuState>(window);
    }
    return mInstance;
}


