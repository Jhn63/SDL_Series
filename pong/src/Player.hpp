#pragma once
#include <SDL.h>
#include "vector_2f.hpp"

class Player {
protected:
    SDL_Rect bar_src;
public:
    Player();
    
    void move_up();
    void move_down();
    bool colision(SDL_Rect& ball);
    void render(SDL_Renderer* ren);

    const SDL_Rect& get_rect();
};

