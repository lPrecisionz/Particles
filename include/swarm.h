/* swarm.h */

#include "particle.h"

#pragma once

namespace explosion{

class swarm{
public:
    const int NPARTICLES{5000};
    int m_lastTime{0};

private:
    particle* m_particles;

public:
    swarm();
    ~swarm();
    void update(int elapsed);
    particle* const getParticles() {return m_particles; };
};

}