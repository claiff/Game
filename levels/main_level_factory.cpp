//
// Created by claiff on 5/29/21.
//

#include "main_level_factory.h"
#include "reader/simple_level_text_reader.h"
#include "types/landscape_type.h"
#include "types/room_type.h"
#include "types/monster_type.h"
#include "../other/utils.h"

MainLevelFactory::MainLevelFactory(LevelBuilderPtr const& builder, sf::Vector2u const& size) : LevelFactory(builder, size)
{
    auto path = Utils::GetLevel1Path();
    mTextReader = std::make_shared<SimpleLevelTextReader>(path);
}

std::list<std::pair<sf::Sprite, sf::Texture>> MainLevelFactory::CreateZone()
{
    auto sprite_type = mTextReader->GetSprite(0);
    BuildAnything(sprite_type);

//    sprite_type = mTextReader->GetSprite(5);
//    BuildAnything(sprite_type);
//
//    sprite_type = mTextReader->GetSprite(8);
//    BuildAnything(sprite_type);

    return mBuilder->BuildZone();
}

void MainLevelFactory::BuildAnything(const TypesSpritesPtr &sprite_type)
{
    if(dynamic_cast<LandscapeType*>(sprite_type.get()))
    {
        mBuilder->BuildLandscape(sprite_type->GetNumber());
        return;
    }
    else if(dynamic_cast<RoomType*>(sprite_type.get()))
    {
        mBuilder->BuildRoom(sprite_type->GetNumber());
        return;
    }
    else if(auto mon = dynamic_cast<MonsterType*>(sprite_type.get()))
    {
        auto difficult = mon->GetDifficult();
        mBuilder->BuildMonster(difficult, sprite_type->GetNumber());
        return;
    }
}


