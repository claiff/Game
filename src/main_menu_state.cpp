//
// Created by claiff on 5/15/21.
//

#include "../inc/main_menu_state.h"
#include "../inc/font_zelda.h"
#include "../inc/load_game_state.h"
#include "../inc/main_level_state.h"
#include "../inc/world.h"
#include "../inc/font_back_decorator.h"
std::shared_ptr<MainMenuState> MainMenuState::mInstance = nullptr;

MainMenuState::MainMenuState(sf::RenderWindow *window) : StateGame(window)
{
    mDecoratorFont = std::make_shared<FontBackDecorator>(new FontZelda());
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

MainMenuState::~MainMenuState()
= default;

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
    switch (mPosition)
    {
        case 0:
            world->ChangeState(MainLevelState::GetInstance(m_window));
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

    mainBackT.loadFromFile(PATH_MAIN_BACK);
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


