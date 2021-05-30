//
// Created by claiff on 5/29/21.
//

#ifndef TESTGAME_MONSTER_TYPE_H
#define TESTGAME_MONSTER_TYPE_H

#include "types_sprites.h"

enum class DIFFICULT_MONSTER : uint8_t
{
    EASY = 0,
    MIDDLE,
    HARD
};
class MonsterType : public TypesSprites
{
public:
    MonsterType(int mNumber, DIFFICULT_MONSTER difficult);
    DIFFICULT_MONSTER GetDifficult()const { return mDifficult;}
private:
    DIFFICULT_MONSTER mDifficult;
};


#endif //TESTGAME_MONSTER_TYPE_H
