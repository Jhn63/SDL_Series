#pragma once
#include <iostream>
#include <time.h>

#include "Ball.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "ErroMgr.hpp"

#define FPS 60
#define FRAME_DELAY 1000/FPS

#define WINDOW_HIGHT 500
#define WINDOW_WIDTH 500

class Game {
private:
    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;

    Player player;
    Enemy enemy;
    Ball ball;
public:
    Game(const int W, const int H);
    ~Game();

    void handle_event();    // handle input from mouse and keyboard
    void render();          // render objects on the screen
    void update();          // update changes non-caused by the user
    void loop();            // game loop
};