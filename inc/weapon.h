#ifndef WEAPON_H
#define WEAPON_H


class Weapon
{
public:
    Weapon(int velocity_bullet,
           int explosion_area,
           int soundFile,
           int pictureBullet,
           int typeDistance);
    virtual ~Weapon();
protected:
    int m_velocityBullet;
    int m_explosionArea;
    int m_soundFile;
    int m_pictureBullet;
    int m_typeDistance;

    virtual void CreateBulletShell() = 0;
    virtual void CreateBullet() = 0;
};

#endif // WEAPON_H
