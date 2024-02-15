#include "Ball.hpp"

Ball::Ball() {
    rec_src.h = 5;
    rec_src.w = 5;
    rec_src.x = 250;
    rec_src.y = 250;
    set_direction();
}

void Ball::set_direction() {
    srand(time(NULL));
    switch (rand() % 2) {
        case 0: {
            vec.x = 1;
            vec.y = 1;
            break;
        }
        case 1: {
            vec.x = -1;
            vec.y = -1;
            break;
        }
    }
}

void Ball::render(SDL_Renderer *ren) {
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    SDL_RenderFillRect(ren, &rec_src);
}

void Ball::update() {
    rec_src.x += static_cast<int>(vec.x * 3);
    rec_src.y += static_cast<int>(vec.y * 3);
}

void Ball::bounce(int hit_flag) {
    switch (hit_flag)
    {
        case HIT_WINDOW: {
            vec.y *= -1;
            break;
        }
        case HIT_BAR: {
            vec.x *= -1;
            break;
        }   
    }
}

const SDL_Rect& Ball::get_rect() {
    return rec_src;
}