//
// Created by claiff on 5/29/21.
//

#include "level_factory.h"

LevelFactory::LevelFactory(LevelBuilderPtr builder, sf::Vector2u const& size) :
        mBuilder(std::move(builder)),
        mSize(size)
{
}
