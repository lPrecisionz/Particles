#include "../include/swarm.h"

namespace explosion{

swarm::swarm(){
    m_particles = new particle[NPARTICLES];
}

swarm::~swarm(){
    delete [] m_particles;
}

void swarm::update(){
    for(int i = 0; i < swarm::NPARTICLES; i++){
        m_particles[i].update();
    }
}

} //namespace explosion