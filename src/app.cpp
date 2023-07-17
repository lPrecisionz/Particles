#include "../include/app.h"
#include <math.h>

namespace explosion{

screen app::m_screen = screen();

void app::run(){

    if(!m_screen.init()){
        exit(1);
    }

    SDL_Event event;
    bool quit{ false };
    int max{0};

    while(!quit){
        
        int elapsed = SDL_GetTicks();
        unsigned char red = (1 + sin(elapsed * 0.001)) * 128; //safety to avoid > 255
        unsigned char green = (1 + sin(elapsed * 0.002)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.003)) * 128;

        for(int y = 0; y < m_screen.SCREEN_HEIGHT; y++){
            for(int x = 0; x < m_screen.SCREEN_WIDTH; x++){
                m_screen.setPixel(x, y, red, green, blue);
            }
        }
        m_screen.setPixel(400, 300, 0, green, 0);
        m_screen.update();
        if(!m_screen.processEvents(event)){
            quit = true;
        }
    }

    m_screen.close();
}

} //namespace explosion