//
// Created by claiff on 5/23/21.
//

#ifndef TESTGAME_MAIN_MENU_SOUND_H
#define TESTGAME_MAIN_MENU_SOUND_H

#include "sound.h"

class MainMenuSound : public Sound
{
public:
    MainMenuSound(const char *path);
    virtual ~MainMenuSound();
    void SetPath(const char *path) override;
    void PlaySound() override;

    void SetLoop(bool val) override;

    void StopSound() override;

    void SetVolume(uint8_t vol) override;
};


#endif //TESTGAME_MAIN_MENU_SOUND_H
