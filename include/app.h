/* app.h */
#include "screen.h"

#pragma once

namespace Particle{

class app{
public:
    static screen m_screen;

public:
    static void run();
};

} //namespace Particle