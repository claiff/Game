#include "../inc/mainmenustate.h"

MainMenuState::MainMenuState(sf::RenderWindow* window):
    StateGame(window)
{
    //Надпись Главное меню
    m_menu_new_gameT.loadFromFile("../Texture/Menu/111.png");
    m_menu_new_gameS.setTexture(m_menu_new_gameT);

    //Надпись Загрузить
    m_menu_load_gameT.loadFromFile("../Texture/Menu/333.png");
    m_menu_load_gameS.setTexture(m_menu_load_gameT);

    //Надпись Выход
    m_menu_exit_gameT.loadFromFile("../Texture/Menu/222.png");
    m_menu_exit_gameS.setTexture(m_menu_exit_gameT);

    //Текстура заднего фона
    menu_backT.loadFromFile("../Texture/Menu/main.png");
    m_menu_backS.setTexture(menu_backT);

    //Надписи располагаем
    m_menu_new_gameS.setPosition(100,30);
    m_menu_load_gameS.setPosition(100,90);
    m_menu_exit_gameS.setPosition(100,150);

    //Растянем главное меню во весь экран
    m_menu_backS.setScale(m_window->getSize().x / m_menu_backS.getLocalBounds().width,
                   m_window->getSize().y / m_menu_backS.getLocalBounds().height);

    //Запихнем надписи в вектор чтоб их переключать
    m_menu_array.push_back(m_menu_new_gameS);
    m_menu_array.push_back(m_menu_load_gameS);
    m_menu_array.push_back(m_menu_exit_gameS);

    ResetMenu();
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::DrawContext()
{
    //Рисуем задний фон
    m_window->draw(m_menu_backS);

    //Рисуем все надписи
    for (const auto legend: m_menu_array)
    {
        m_window->draw(legend);
    }
}

bool MainMenuState::IsTimePressButton(long& prev_time)
{
    auto curr_time = Utils::GetTime();
    //Проверка чтоб выбор меню не был слишком быстрым

    if(curr_time > prev_time + FREEZE_TIME)
    {
        prev_time = curr_time;
        return true;
    }
    else
    {
        return false;
    }
}

void MainMenuState::PushUp()
{
    //Цыганский фокус чтоб при первом нажатии сразу сработал и prev_time != curr_time
    static auto prev_time = Utils::GetTime() - FREEZE_TIME;

    if(IsTimePressButton(prev_time))
    {
        DecMenu();
    }
}

void MainMenuState::PushDown()
{
    //Цыганский фокус чтоб при первом нажатии сразу сработал и prev_time != curr_time
    static auto prev_time = Utils::GetTime() - FREEZE_TIME;

    auto curr_time = Utils::GetTime();
    //Проверка чтоб выбор меню не был слишком быстрым
    if(IsTimePressButton(prev_time))
    {
        IncMenu();
    }
}

void MainMenuState::PushLeft(){}

void MainMenuState::PushRight(){}

void MainMenuState::ResetMenu()
{
    m_pos_menu = 0;
    m_menu_array[m_pos_menu].setColor(ACTIVE_MENU_COLOR);
}

void MainMenuState::IncMenu()
{
    m_menu_array[m_pos_menu].setColor(UNACTIVE_MENU_COLOR);
    m_pos_menu++;
    if(m_pos_menu >= m_menu_array.size())
    {
        m_pos_menu = 0;
    }
    m_menu_array[m_pos_menu].setColor(ACTIVE_MENU_COLOR);
}

void MainMenuState::DecMenu()
{
    m_menu_array[m_pos_menu].setColor(UNACTIVE_MENU_COLOR);
    m_pos_menu--;
    if(m_pos_menu < 0)
    {
        m_pos_menu = m_menu_array.size() - 1;
    }
    m_menu_array[m_pos_menu].setColor(ACTIVE_MENU_COLOR);
}

void MainMenuState::SetMenu()
{

}

