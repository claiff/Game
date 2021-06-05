//
// Created by claiff on 5/29/21.
//

#ifndef TESTGAME_MAIN_LEVEL_BUILDER_H
#define TESTGAME_MAIN_LEVEL_BUILDER_H

#include "level_builder.h"

//TODO comment
//TODO Проверить include
class MainLevelBuilder : public LevelBuilder
{
public:
    MainLevelBuilder() = default;
    ~MainLevelBuilder() override = default;
private:
    void BuildMonster(DIFFICULT_MONSTER difficult, int number) override;
    void BuildLandscape(int number) override;
    void BuildRoom(int number) override;
    std::list<std::pair<sf::Sprite, sf::Texture>> & BuildZone() override;

};


#endif //TESTGAME_MAIN_LEVEL_BUILDER_H
