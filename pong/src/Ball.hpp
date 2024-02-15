#pragma once
#include <SDL.h>
#include <time.h>
#include <iostream>
#include "vector_2f.hpp"

#define HIT_WINDOW 0
#define HIT_BAR 1

class Ball {
private:
    SDL_Rect rec_src;
    vector_2f vec;

    void set_direction();
public:
    Ball();
    
    void update();
    void bounce(int hit_flag);
    void render(SDL_Renderer *ren);

    const SDL_Rect& get_rect();
};