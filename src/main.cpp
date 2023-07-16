#include <iostream>
#include <SDL.h>

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
    

    SDL_Event event;
    bool quit{false};

    while(!quit){
        
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}