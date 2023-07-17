#include "../include/screen.h"

namespace explosion{

screen::screen(): m_window(NULL),
m_renderer(NULL),
m_texture(NULL),
m_buffer1(NULL),
m_buffer2(NULL){}

bool screen::init(){

    m_window = SDL_CreateWindow("Particle",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if(m_window == NULL){
        SDL_Quit();
        SDL_Log("Error creating window: %s", SDL_GetError());
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window,
        -1,
        SDL_RENDERER_PRESENTVSYNC);

    m_texture = SDL_CreateTexture(m_renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STATIC,
        SCREEN_WIDTH,
        SCREEN_HEIGHT
        );
    
    if(m_renderer == NULL){
        SDL_Log("Error creating renderer: %s", SDL_GetError());
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    if (m_texture == NULL){
        SDL_Log("Error creating texture: %s", SDL_GetError());
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }


    m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    SDL_memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    SDL_memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    return true;
}

void screen::update(){
    SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    bool outOfRange = x < 0 || x >= screen::SCREEN_WIDTH
        || y < 0 || y >= screen::SCREEN_HEIGHT;

    if(outOfRange){
        return;
    }
    Uint32 color{0};

    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF; //alpha (opaque)

    m_buffer1[SCREEN_WIDTH * y + x] = color;
}

void screen::boxBlur(){
    // Buffer2 retrieves buffer1 data, before it's cleaned
    Uint32 *temp = m_buffer1;
    m_buffer1 = m_buffer2;
    m_buffer2 = temp;

    for(int y = 0; y < SCREEN_HEIGHT; y++){
        for(int x = 0; x < SCREEN_WIDTH; x++){

            int redTotal{0};
            int greenTotal{0};
            int blueTotal{0};

            for(int row = -1; row <= 1; row++){
                for(int col = -1; col <= +1; col++){
                    int currentX = x + col;
                    int currentY = y + row;
                    bool particleInRange { currentX >= 0 && currentX < SCREEN_WIDTH && currentY >=0 && currentY < SCREEN_HEIGHT};

                    if(particleInRange){
                        Uint32 color = m_buffer2[currentY * SCREEN_WIDTH + currentX];

                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;    

                        redTotal += red;
                        greenTotal +=green;
                        blueTotal +=blue;
                    }
                }
            }
            
            Uint8 resultRed = redTotal/9;
            Uint8 resultGreen = greenTotal/9;
            Uint8 resultBlue = blueTotal/9;

            setPixel(x, y, resultRed, resultGreen, resultBlue);
        }
    }
}

bool screen::processEvents(SDL_Event &event){
    while(SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            return false;
        }
    }
    return true;
}   

void screen::close(){
    delete [] m_buffer1;
    delete [] m_buffer2;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}


} // namespace explosion