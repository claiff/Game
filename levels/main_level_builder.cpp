//
// Created by claiff on 5/29/21.
//

#include "main_level_builder.h"
#include "../other/utils.h"

void MainLevelBuilder::BuildMonster(DIFFICULT_MONSTER difficult, int number)
{
}

void MainLevelBuilder::BuildLandscape(int number)
{
    sf::Texture mainBackT;
    sf::Sprite mainBackS;
    std::pair<sf::Sprite, sf::Texture> data;

    auto path = Utils::GetLevelTexturePath();
    bool t = mainBackT.loadFromFile(path);
    mainBackS.setTexture(mainBackT);
    data.first = mainBackS;
    data.second = mainBackT;

    mSprites.push_back(data);
}

void MainLevelBuilder::BuildRoom(int number)
{

}

std::list<std::pair<sf::Sprite, sf::Texture>> & MainLevelBuilder::BuildZone()
{
    return mSprites;
}

