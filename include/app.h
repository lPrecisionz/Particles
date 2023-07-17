/* app.h */
#include "screen.h"

#pragma once

namespace explosion{

class app{
public:
    static screen m_screen;

public:
    static void run(); //game loop
};

} //namespace explosion