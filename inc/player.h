#ifndef PLAYER_H
#define PLAYER_H

#include "w_pistol.h"
#include "memory"

class Player
{
public:
    Player();
private:
    std::unique_ptr<Weapon> m_weapon;
};

#endif // PLAYER_H
