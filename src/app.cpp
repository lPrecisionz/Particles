#include "../include/app.h"

namespace Particle{

screen app::m_screen = screen();

void app::run(){

    if(!m_screen.init()){
        exit(1);
    }

    SDL_Event event;
    bool quit{false};

    while(!quit){

        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }
        
    }

    m_screen.close();
}

} //namespace Particle