//
// Created by claiff on 5/29/21.
//

#ifndef TESTGAME_LEVEL_BUILDER_H
#define TESTGAME_LEVEL_BUILDER_H
//TODO comment
//TODO Проверить include
#include "memory"
#include "list"
#include <SFML/Graphics.hpp>
#include "types/monster_type.h"

class LevelBuilder
{
public:
    LevelBuilder();
    virtual void BuildMonster(DIFFICULT_MONSTER difficult, int number) = 0;
    virtual void BuildLandscape(int number) = 0;
    virtual void BuildRoom(int number) = 0;
    virtual std::list<std::pair<sf::Sprite, sf::Texture>> & BuildZone() = 0;
    virtual ~LevelBuilder();

protected:
    std::list<std::pair<sf::Sprite, sf::Texture> > mSprites;
};
using LevelBuilderPtr = std::shared_ptr<LevelBuilder>;

#endif //TESTGAME_LEVEL_BUILDER_H
