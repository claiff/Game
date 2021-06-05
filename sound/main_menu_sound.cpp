//
// Created by claiff on 5/23/21.
//

#include "main_menu_sound.h"

MainMenuSound::MainMenuSound(const char *path) : Sound(path)
{
    mBuffer.loadFromFile(path);
    mSound.setBuffer(mBuffer);
}

MainMenuSound::~MainMenuSound()
{}

void MainMenuSound::SetPath(const char *path)
{
    mPath = path;
}

void MainMenuSound::PlaySound()
{
    mSound.play();
}

void MainMenuSound::StopSound()
{
    mSound.stop();
}

void MainMenuSound::SetVolume(uint8_t vol)
{
    if(vol > 100)
    {
        return;
    }
    mSound.setVolume(vol);
}

void MainMenuSound::SetLoop(bool val)
{
    mSound.setLoop(val);
}
