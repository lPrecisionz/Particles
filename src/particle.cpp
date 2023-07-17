#include "../include/particle.h"
#include <stdlib.h>

namespace explosion{

particle::particle(){
    m_x = (2.0 * rand()/RAND_MAX) - 1; //range: -1 to +1
    m_y = (2.0 * rand()/RAND_MAX) - 1;
}

} //namespace explosion