#pragma once

namespace explosion{

struct particle{
    double m_x;
    double m_y;
    double m_xspeed;
    double m_yspeed;

public:
    particle();
    void update();
};

} //namespace explosion