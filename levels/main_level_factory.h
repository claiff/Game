//
// Created by claiff on 5/29/21.
//

#ifndef TESTGAME_MAIN_LEVEL_FACTORY_H
#define TESTGAME_MAIN_LEVEL_FACTORY_H

#include "level_factory.h"
#include "reader/level_text_reader.h"


//TODO comment
//TODO Проверить include
class MainLevelFactory : public LevelFactory
{
public:
    MainLevelFactory( LevelBuilderPtr const& builder, sf::Vector2u const& size);
    std::list<std::pair<sf::Sprite, sf::Texture>> CreateZone() override;
    ~MainLevelFactory() override = default;

private:
    LevelTextReaderPtr mTextReader;

    void BuildAnything(const TypesSpritesPtr &sprite_type);
};



#endif //TESTGAME_MAIN_LEVEL_FACTORY_H
