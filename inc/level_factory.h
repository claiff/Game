//
// Created by claiff on 5/29/21.
//

#ifndef TESTGAME_LEVEL_FACTORY_H
#define TESTGAME_LEVEL_FACTORY_H
//TODO comment
//TODO Проверить include
#include "level_builder.h"

class LevelFactory
{
public:
    LevelFactory(LevelBuilderPtr builder, sf::Vector2u const& size);
    virtual std::vector<sf::Sprite> CreateZone() = 0;
    virtual ~LevelFactory() = default;

protected:
    LevelBuilderPtr mBuilder;
    sf::Vector2u mSize;
};
using LevelFactoryPtr = std::shared_ptr<LevelFactory>;

#endif //TESTGAME_LEVEL_FACTORY_H
