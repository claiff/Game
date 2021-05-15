//
// Created by claiff on 5/15/21.
//

#include "../inc/main_menu_state.h"
#include "../inc/font_zelda.h"

std::shared_ptr<MainMenuState> MainMenuState::mInstance = nullptr;

MainMenuState::~MainMenuState()
= default;

void MainMenuState::PushUp(World *world)
{

}

void MainMenuState::PushDown(World *world)
{

}

void MainMenuState::PushLeft(World *world)
{

}

void MainMenuState::PushRight(World *world)
{

}

void MainMenuState::PushUse(World *world)
{

}

void MainMenuState::DrawContext()
{
    DrawMainBack();
    m_font->DrawMultiText(m_window, text_and_color, 200,200);
}

std::shared_ptr<MainMenuState> MainMenuState::GetInstance(sf::RenderWindow *window)
{
    if(!mInstance)
    {
        mInstance = std::make_shared<MainMenuState>(window);
    }
    return mInstance;
}

MainMenuState::MainMenuState(sf::RenderWindow *window) : StateGame(window),
                                                         m_font(new FontZelda())
{
    AddTextAndColor("MmNnOoPp", ACTIVE_COLOR);
//    AddTextAndColor("Load Game", UN_ACTIVE_COLOR);
//    AddTextAndColor("Exit", UN_ACTIVE_COLOR);
}

void MainMenuState::AddTextAndColor(const std::string &text, const sf::Color &color)
{
    std::pair<std::string, sf::Color> textC;
    textC.first = text;
    textC.second = color;
    text_and_color.emplace_back(textC);
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
