//
// Created by claiff on 5/29/21.
//

#ifndef TESTGAME_LEVEL_TEXT_READER_H
#define TESTGAME_LEVEL_TEXT_READER_H
//TODO comment
//TODO Проверить include

#include "string"
#include "SFML/Graphics.hpp"
#include "types_sprites.h"

class LevelTextReader
{
public:
    LevelTextReader(std::string const& path);
    virtual sf::Vector2u GetSize() const = 0;
    virtual TypesSpritesPtr GetSprite(int number) = 0;
    virtual  std::vector<int> GetSprite() const = 0;
protected:
    std::string GetCipher(int number) const;
    bool mIsRead;
private:
    sf::FileInputStream mStream;
    std::vector<std::string> ciphers;
};
using LevelTextReaderPtr = std::shared_ptr<LevelTextReader>;

#endif //TESTGAME_LEVEL_TEXT_READER_H
