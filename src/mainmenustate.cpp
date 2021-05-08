#include "../inc/mainmenustate.h"

MainMenuState::MainMenuState(sf::RenderWindow* window):
    StateGame(window),
    m_font(new FontZelda)
{
    //Текстура заднего фона
    menu_backT.loadFromFile("../Texture/Menu/main.png");
    m_menu_backS.setTexture(menu_backT);

    //Растянем главное меню во весь экран
    m_menu_backS.setScale(m_window->getSize().x / m_menu_backS.getLocalBounds().width,
                   m_window->getSize().y / m_menu_backS.getLocalBounds().height);

    //Запихнем надписи в вектор чтоб их переключать
    m_menu_array.push_back(std::pair<std::string, sf::Color>("New game", UNACTIVE_MENU_COLOR));
    m_menu_array.push_back(std::pair<std::string, sf::Color>("Load game", UNACTIVE_MENU_COLOR));
    m_menu_array.push_back(std::pair<std::string, sf::Color>("Exit", UNACTIVE_MENU_COLOR));

    ResetMenu();

}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::DrawContext()
{
    //Рисуем задний фон
    m_window->draw(m_menu_backS);
    auto start_draw_y = START_DRAW_LEG_Y;
    for (const auto legend : m_menu_array)
    {
        m_font->DrawText(m_window, legend.first, legend.second, START_DRAW_LEG_X, start_draw_y);
        start_draw_y += INDENT_LEGEND;
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
    m_menu_array[m_pos_menu].second = ACTIVE_MENU_COLOR;
}

void MainMenuState::IncMenu()
{
    m_menu_array[m_pos_menu].second = UNACTIVE_MENU_COLOR;
    m_pos_menu++;
    if(m_pos_menu >= m_menu_array.size())
    {
        m_pos_menu = 0;
    }
    m_menu_array[m_pos_menu].second = ACTIVE_MENU_COLOR;
}

void MainMenuState::DecMenu()
{
    m_menu_array[m_pos_menu].second = UNACTIVE_MENU_COLOR;
    m_pos_menu--;
    if(m_pos_menu < 0)
    {
        m_pos_menu = m_menu_array.size() - 1;
    }
    m_menu_array[m_pos_menu].second = ACTIVE_MENU_COLOR;
}

void MainMenuState::PushUse()
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

