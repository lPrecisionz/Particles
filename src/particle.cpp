#include "../include/particle.h"
#include "../include/screen.h"
#include <stdlib.h>

namespace explosion{

particle::particle(){
    m_x = (2.0 * rand()/RAND_MAX) - 1; //range: -1 to +1
    m_y = (2.0 * rand()/RAND_MAX) - 1;

    m_xspeed = 0.001 * ((2.0 * rand()/RAND_MAX) - 1);
    m_yspeed = 0.001 * ((2.0 * rand()/RAND_MAX) - 1);
}

void particle::update(){
    m_x += m_xspeed;
    m_y += m_yspeed;

    bool x_outOfRange = m_x < -1 || m_x >= 1;
    bool y_outOfRange = m_y < -1 || m_y >= 1;

    if(x_outOfRange){
        m_xspeed = -m_xspeed;
    }

    if(y_outOfRange){
        m_yspeed = -m_yspeed;
    }
}

} //namespace explosion