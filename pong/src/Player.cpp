#include "Player.hpp"

Player::Player() {
    bar_src.h = 80;
    bar_src.w = 20;
    bar_src.x = 0;
    bar_src.y = 0;
}

void Player::render(SDL_Renderer* ren) {
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    SDL_RenderFillRect(ren, &bar_src);
}

void Player::move_up() {
    bar_src.y -= 5;
}

void Player::move_down() {
    bar_src.y += 5;
}

const SDL_Rect& Player::get_rect() {
    return bar_src;
}

bool Player::colision(SDL_Rect& ball) {
    return  (   (ball.x >= bar_src.x && ball.y >= bar_src.y) && 
                (ball.x <= bar_src.x + bar_src.w && ball.y <= bar_src.y + bar_src.h)
            );
}