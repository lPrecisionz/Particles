#include <iostream>
#include <SDL.h>
#include <stdexcept>

int main(int argc, char* argv[]) {

    const int SCREEN_WIDTH{800};
    const int SCREEN_HEIGHT{600};

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        SDL_Log("SDL Init Failed");
        return 1; 
    }

    SDL_Window *window = SDL_CreateWindow("Particles",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    
    if(window == NULL){
        SDL_Quit();
        SDL_Log("Error creating window: %s", SDL_GetError());
        return 2;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window,
        -1,
        SDL_RENDERER_PRESENTVSYNC);

    SDL_Texture *texture = SDL_CreateTexture(renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STATIC,
        SCREEN_WIDTH,
        SCREEN_HEIGHT
        );
    
    if(renderer == NULL){
        SDL_Log("Error creating renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    if (texture == NULL){
        SDL_Log("Error creating texture: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4; 
    }


    Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    SDL_memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_Event event;
    bool quit{false};

    while(!quit){
        
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }
    }

    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
}