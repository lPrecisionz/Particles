/* swarm.h */

#include "particle.h"

#pragma once

namespace explosion{

class swarm{
public:
    const int NPARTICLES{1000};

private:
    particle* m_particles;

public:
    swarm();
    ~swarm();
    void update();
    particle* const getParticles() {return m_particles; };
};

}