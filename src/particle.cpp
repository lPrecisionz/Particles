#include "../include/particle.h"
#include "../include/screen.h"
#include <stdlib.h>
#include <math.h>

namespace explosion{

particle::particle(){   
    init();
}

void particle::init(){
    m_x = 0;
    m_y = 0;
    m_direction = ((2 * M_PI) * rand()) /RAND_MAX;
    m_speed = (0.04 * rand())/RAND_MAX;
    m_speed *= m_speed;
}

void particle::update(int interval){
    m_direction += interval*0.0005;
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);

    m_x += xspeed * interval;
    m_y += yspeed * interval;

    bool outOfRange = m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1;
    if(outOfRange){
        init();
    }

    if(rand() < RAND_MAX/100){
        init();
    }
}


} //namespace explosion