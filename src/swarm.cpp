#include "../include/swarm.h"

namespace explosion{

swarm::swarm(){
    m_particles = new particle[NPARTICLES];
}

swarm::~swarm(){
    delete [] m_particles;
}

} //namespace explosion