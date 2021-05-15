//
// Created by claiff on 5/10/21.
//

#ifndef TESTGAME_DECORATORFONT_H
#define TESTGAME_DECORATORFONT_H

#include "font.h"

class DecoratorFont : public Font
{
public:
    DecoratorFont(Font *font);
protected:
    Font *m_font;
};


#endif //TESTGAME_DECORATORFONT_H
