#ifndef W_PISTOL_H
#define W_PISTOL_H

#include "weapon.h"

class W_Pistol : public Weapon
{
public:
    W_Pistol();
    virtual ~W_Pistol() override;
    void CreateBulletShell() override;
    void CreateBullet() override;
};

#endif // W_PISTOL_H
