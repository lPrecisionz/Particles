#include "../include/app.h"
#include "../include/swarm.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

namespace explosion{

// YRANGE compensates the difference in the range from x to y
// since the screen has different height and width constants
const double XRANGE{screen::SCREEN_WIDTH/2};
const double YRANGE{screen::SCREEN_WIDTH/2 + screen::SCREEN_HEIGHT/2};

screen app::m_screen = screen();

void app::run(){
    srand(time(NULL));

    if(!m_screen.init()){
        exit(1);
    }

    swarm appSwarm;
    SDL_Event event;
    bool quit{ false };
    int max{0};

    while(!quit){
        const particle * const pParticles = appSwarm.getParticles();

        appSwarm.update();
        m_screen.clear();
        int elapsed = SDL_GetTicks();
        //unsigned: safety to avoid > 255
        unsigned char red = (1 + sin(elapsed * 0.001)) * 128;
        unsigned char green = (1 + sin(elapsed * 0.002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.003)) * 128;

        for(int i = 0; i < appSwarm.NPARTICLES; i++){
            particle currentParticle = pParticles[i];

            int x = (currentParticle.m_x + 1) * (XRANGE);
            int y = (currentParticle.m_y * YRANGE);

            m_screen.setPixel(x, y, red, green, blue);
        }

        m_screen.update();

        if(!m_screen.processEvents(event)){
            quit = true;
        }
    }

    m_screen.close();
}

} //namespace explosion