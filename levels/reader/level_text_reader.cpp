//
// Created by claiff on 5/29/21.
//

#include "level_text_reader.h"

LevelTextReader::LevelTextReader(const char* path)
{
    mIsRead = mStream.open(path);
    auto counter = mStream.getSize();
    std::string data;
    char letter;
    //Прочтем весь файл
    do
    {
        mStream.read(&letter, sizeof(letter));
        if(letter != ' ' && std::isprint(letter))
        {
            data += letter;
        }
        else if(data != "")
        {
            ciphers.push_back(data);
            data = "";
        }
        counter--;
    }
    while(counter != 0);
}

std::string LevelTextReader::GetCipher(int number) const
{
    return ciphers.at(number);
}
