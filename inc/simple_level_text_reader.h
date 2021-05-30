//
// Created by claiff on 5/29/21.
//

#ifndef TESTGAME_SIMPLE_LEVEL_TEXT_READER_H
#define TESTGAME_SIMPLE_LEVEL_TEXT_READER_H

static const int MAX_CIPHER_COUNT = 6;

static const int TYPE_POS = 0;

static const char LANDSCAPE_CIPHER = 'L';

static const int NUMBER_POS = 1;

static const char ROOM_CIPHER = 'R';

static const char MONSTER_CIPHER = 'M';

#include "level_text_reader.h"

class SimpleLevelTextReader : public LevelTextReader
{
public:
    SimpleLevelTextReader(std::string const& path);

    sf::Vector2u GetSize() const override;

    TypesSpritesPtr GetSprite(int number) override;

    std::vector<int> GetSprite() const override;

private:

};


#endif //TESTGAME_SIMPLE_LEVEL_TEXT_READER_H
