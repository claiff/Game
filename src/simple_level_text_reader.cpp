//
// Created by claiff on 5/29/21.
//

#include "../inc/simple_level_text_reader.h"
#include "../inc/landscape_type.h"
#include "../inc/room_type.h"
#include "../inc/monster_type.h"

SimpleLevelTextReader::SimpleLevelTextReader(std::string const& path) : LevelTextReader(path)
{}

sf::Vector2u SimpleLevelTextReader::GetSize() const
{
    return sf::Vector2u();
}

TypesSpritesPtr SimpleLevelTextReader::GetSprite(int number)
{
    TypesSpritesPtr type;
    auto data = GetCipher(number);
    if(data[TYPE_POS] == LANDSCAPE_CIPHER)
    {
        auto number = atoi(&data[NUMBER_POS]);
        type = std::make_shared<LandscapeType>(number);
    }
    else if(data[TYPE_POS] == ROOM_CIPHER)
    {
        auto number = atoi(&data[NUMBER_POS]);
        type = std::make_shared<RoomType>(number);
    }
    else if(data[TYPE_POS] == MONSTER_CIPHER)
    {
        auto letter = data[NUMBER_POS];
        auto diff_num =  atoi(&letter);
        auto difficult = static_cast<DIFFICULT_MONSTER>(diff_num);
        type = std::make_shared<MonsterType>(number, difficult);
    }
    return type;
}

std::vector<int> SimpleLevelTextReader::GetSprite() const
{
    return std::vector<int>();
}
