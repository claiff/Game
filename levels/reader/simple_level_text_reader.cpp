//
// Created by claiff on 5/29/21.
//

#include "simple_level_text_reader.h"
#include "../types/landscape_type.h"
#include "../types/room_type.h"
#include "../types/monster_type.h"

static const int MAX_CIPHER_COUNT = 6;
static const int TYPE_POS = 0;
static const char LANDSCAPE_CIPHER = 'L';
static const int NUMBER_POS = 1;
static const char ROOM_CIPHER = 'R';
static const char MONSTER_CIPHER = 'M';

SimpleLevelTextReader::SimpleLevelTextReader(const char* path) : LevelTextReader(path)
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
