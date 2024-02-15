#pragma once

#include <time.h>
#include <iostream>
#include <SDL.h>
#include "Player.hpp"

class Enemy : public Player {
public:
    Enemy();
    
    void find_ball(SDL_Rect& ball_src);
};