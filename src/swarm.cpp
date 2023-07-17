#include "../include/swarm.h"

namespace explosion{

swarm::swarm(){
    m_particles = new particle[NPARTICLES];
}

swarm::~swarm(){
    delete [] m_particles;
}

void swarm::update(int elapsed){
    // ensuring similar speed across different systems
    int interval = elapsed - m_lastTime;
    for(int i = 0; i < swarm::NPARTICLES; i++){
        m_particles[i].update(interval);
    }

    m_lastTime = elapsed;
}

} //namespace explosion