//
// Created by claiff on 5/29/21.
//

#pragma once

#include "level_text_reader.h"

class SimpleLevelTextReader : public LevelTextReader
{
public:
    explicit SimpleLevelTextReader(const char* path);

    sf::Vector2u GetSize() const override;

    TypesSpritesPtr GetSprite(int number) override;

    std::vector<int> GetSprite() const override;

private:

};
