/* screen.h */
#include <SDL.h>
#pragma once

namespace explosion{

class screen{
public:
    const static int SCREEN_WIDTH{800};
    const static int SCREEN_HEIGHT{600};

private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2; //used for boxBlur

public:
    screen();
    bool init();
    bool processEvents(SDL_Event &event);
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void boxBlur();
    void update();
    void close();
};

} // namespace explosion