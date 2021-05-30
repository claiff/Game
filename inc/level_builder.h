//
// Created by claiff on 5/29/21.
//

#ifndef TESTGAME_LEVEL_BUILDER_H
#define TESTGAME_LEVEL_BUILDER_H
//TODO comment
//TODO Проверить include
#include "memory"
#include "vector"
#include <SFML/Graphics.hpp>
#include "monster_type.h"

class LevelBuilder
{
public:
    LevelBuilder();
    virtual void BuildMonster(DIFFICULT_MONSTER difficult, int number) = 0;
    virtual void BuildLandscape(int number) = 0;
    virtual void BuildRoom(int number) = 0;
    virtual std::vector<sf::Sprite> BuildZone() = 0;
    virtual ~LevelBuilder();

protected:
    std::vector<sf::Sprite> mSprites;
};
using LevelBuilderPtr = std::shared_ptr<LevelBuilder>;

#endif //TESTGAME_LEVEL_BUILDER_H
