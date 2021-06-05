//
// Created by claiff on 5/10/21.
//

#include "decorator_font.h"

DecoratorFont::DecoratorFont(FontPtr font):
        mFont(std::move(font))
{

}
