//
// Created by claiff on 5/10/21.
//

#ifndef TESTGAME_DECORATORFONT_H
#define TESTGAME_DECORATORFONT_H

#include "font.h"

//TODO comment
//TODO Проверить include
class DecoratorFont : public Font
{
public:
    DecoratorFont(FontPtr font);
protected:
    FontPtr mFont;
};
using DecoratorFontPtr = std::shared_ptr<DecoratorFont>;

#endif //TESTGAME_DECORATORFONT_H
