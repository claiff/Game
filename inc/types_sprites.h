//
// Created by claiff on 5/29/21.
//

#ifndef TESTGAME_TYPES_SPRITES_H
#define TESTGAME_TYPES_SPRITES_H

#include "memory"

class TypesSprites
{
public:
    TypesSprites(int mNumber);
    virtual int GetNumber() const{return mNumber;}
protected:
    int mNumber;
};
using TypesSpritesPtr = std::shared_ptr<TypesSprites>;

#endif //TESTGAME_TYPES_SPRITES_H
