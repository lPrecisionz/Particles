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
    Uint32 *m_buffer;

public:
    screen();
    bool init();
    bool processEvents(SDL_Event &event);
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void update();
    void clear();
    void close();
};

} // namespace explosion