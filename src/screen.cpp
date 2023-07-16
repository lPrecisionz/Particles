#include "../include/screen.h"

namespace Particle{

screen::screen(): m_window(NULL),
m_renderer(NULL),
m_texture(NULL),
m_buffer(NULL){}

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


    m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    SDL_memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);

    return true;
}
    

void screen::close(){
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}


} // namespace Particle