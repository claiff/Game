#include "../inc/weapon.h"

Weapon::Weapon(int velocity_bullet,
               int intexplosion_area,
               int soundFile,
               int pictureBullet,
               int typeDistance):
    m_velocityBullet(velocity_bullet),
    m_explosionArea(intexplosion_area),
    m_soundFile(soundFile),
    m_pictureBullet(pictureBullet),
    m_typeDistance(typeDistance)
{

}

Weapon::~Weapon()
{

}
