#pragma once

namespace explosion{

struct particle{
    double m_x;
    double m_y;
    double m_speed;
    double m_direction;

public:
    particle();
    void update();
};

} //namespace explosion