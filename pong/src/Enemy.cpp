#include "Enemy.hpp"

Enemy::Enemy() {
    bar_src.h = 80;
    bar_src.w = 20;
    bar_src.x = 480;
    bar_src.y = 420;
}

void Enemy::find_ball(SDL_Rect& ball_src) {
    int y_mid = bar_src.y + bar_src.h/2;
    srand(time(NULL));
    if (rand()%2 == 0) {
        
        (y_mid > ball_src.y) ? move_up() : move_down();
    }
}