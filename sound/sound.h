//
// Created by claiff on 5/23/21.
//

#ifndef TESTGAME_SOUND_H
#define TESTGAME_SOUND_H

#include "SFML/Audio.hpp"
//TODO comment
//TODO Проверить include
class Sound
{
public:
    Sound(char const *path);
    virtual void SetPath(char const* path) = 0;
    virtual void PlaySound() = 0;
    virtual void StopSound() = 0;
    virtual void SetVolume(uint8_t vol) = 0;
    virtual void SetLoop(bool val) = 0;
protected:
    sf::Sound mSound;
    sf::SoundBuffer mBuffer;
    char const *mPath;
};


#endif //TESTGAME_SOUND_H
