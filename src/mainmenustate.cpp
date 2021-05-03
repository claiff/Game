#include "../inc/mainmenustate.h"


MainMenuState::MainMenuState(sf::RenderWindow* window):
    StateGame(window)
{    
    sf::Texture menu_new_gameT;
    sf::Texture menu_load_gameT;
    sf::Texture menu_exit_gameT;
    sf::Texture menu_backT;
    bool l;

//    l = menu_new_gameT.loadFromFile("../Texture/Menu/111.png");
//    sf::Sprite menu_new_gameS(menu_new_gameT);

//    l = menu_load_gameT.loadFromFile("../Texture/Menu/333.png");
//    sf::Sprite menu_load_gameS(menu_load_gameT);

//    l = menu_exit_gameT.loadFromFile("../Texture/Menu/222.png");
//    sf::Sprite menu_exit_gameS(menu_exit_gameT);

    l = menu_backT.loadFromFile("../Texture/Menu/main.png");
    sf::Sprite menu_backS(menu_backT);

//    menu_new_gameS.setPosition(100,30);
//    menu_load_gameS.setPosition(100,90);
//    menu_exit_gameS.setPosition(100,150);


    menu_backS.setScale(m_window->getSize().x / menu_backS.getLocalBounds().width,
                   m_window->getSize().y / menu_backS.getLocalBounds().height);

//    m_menu_array.push_back(menu_new_gameS);
//    m_menu_array.push_back(menu_load_gameS);
//    m_menu_array.push_back(menu_exit_gameS);

    m_window->draw(menu_backS);
    m_window->display();
    m_pos_menu = 0;
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::DrawContext()
{
//    if(m_window->isOpen())
//    {
//        sf::Event event;
//        //m_window->display();
//        while (m_window->pollEvent(event))
//        {
//            // Пользователь нажал на «крестик» и хочет закрыть окно?
//            if (event.type == sf::Event::Closed)
//                // тогда закрываем его
//                m_window->close();
//        }
//    }
}

void MainMenuState::PushUp()
{

}

void MainMenuState::PushDown()
{
//    m_pos_menu++;
//    if(m_pos_menu > m_menu_array.size())
//        m_pos_menu = 0;

}

void MainMenuState::PushLeft()
{

}

void MainMenuState::PushRight()
{

}
