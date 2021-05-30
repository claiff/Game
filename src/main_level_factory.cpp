//
// Created by claiff on 5/29/21.
//

#include "../inc/main_level_factory.h"
#include "../inc/simple_level_text_reader.h"
#include "../inc/landscape_type.h"
#include "../inc/room_type.h"
#include "../inc/monster_type.h"

std::vector<sf::Sprite> MainLevelFactory::CreateZone()
{
    auto sprite_type = mTextReader->GetSprite(0);
    BuildAnything(sprite_type);

    sprite_type = mTextReader->GetSprite(5);
    BuildAnything(sprite_type);

    sprite_type = mTextReader->GetSprite(8);
    BuildAnything(sprite_type);

    return mBuilder->BuildZone();
}

void MainLevelFactory::BuildAnything(const TypesSpritesPtr &sprite_type)
{
    if(dynamic_cast<LandscapeType*>(sprite_type.get()))
    {
        mBuilder->BuildLandscape(sprite_type->GetNumber());
    }
    else if(dynamic_cast<RoomType*>(sprite_type.get()))
    {
        mBuilder->BuildRoom(sprite_type->GetNumber());
    }
    else if(auto mon = dynamic_cast<MonsterType*>(sprite_type.get()))
    {
        auto difficult = mon->GetDifficult();
        mBuilder->BuildMonster(difficult, sprite_type->GetNumber());
    }
}

MainLevelFactory::MainLevelFactory(LevelBuilderPtr const& builder, sf::Vector2u const& size) : LevelFactory(builder, size)
{
    mTextReader = std::make_shared<SimpleLevelTextReader>(PATH_READER);
}


