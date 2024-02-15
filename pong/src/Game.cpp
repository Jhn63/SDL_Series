#include "Game.hpp"

Game::Game(const int W, const int H) : window(NULL), renderer(NULL) {
    ErroMgr::assert(SDL_Init(SDL_INIT_EVERYTHING) == 0, "Failed initializing SDL" );

    window = SDL_CreateWindow("pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, 0);
    ErroMgr::assert(window != NULL, "Failed creating window" );

    renderer = SDL_CreateRenderer(window,-1, 0);
    ErroMgr::assert(renderer != NULL, "Failed creating renderer" );
    
    running = true;
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::loop() {
    while (running) {
        Uint32 frame_start = SDL_GetTicks();

        handle_event();
        update();
        render();

        int frame_time = SDL_GetTicks() - frame_start;
        if (FRAME_DELAY > frame_time) {
            SDL_Delay(FRAME_DELAY - frame_time);
        }
    }
}

void Game::handle_event() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT: {
            running = false;
            break;
        }
        case SDL_KEYDOWN: {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
            if (event.key.keysym.sym == SDLK_UP) {
                player.move_up();
            }
            if (event.key.keysym.sym == SDLK_DOWN) {
                player.move_down();
            }
            if (event.key.keysym.sym == SDLK_DOWN) {
                player.move_down();
            }
            break;
        }
    }
}

void Game::update() {
    ball.update();
    SDL_Rect b_src = ball.get_rect();
    SDL_Rect e_src = enemy.get_rect();
    SDL_Rect p_src = player.get_rect();

    enemy.find_ball(b_src);
    if (b_src.y >= WINDOW_HIGHT || b_src.y <= 0) {
        ball.bounce(HIT_WINDOW);
    }
    if (player.colision(b_src) || enemy.colision(b_src)) {
        ball.bounce(HIT_BAR);
    }
    if (b_src.x > WINDOW_WIDTH || b_src.x < 0) {
        running = false;
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    SDL_RenderClear(renderer);
    player.render(renderer);
    enemy.render(renderer);
    ball.render(renderer);
    SDL_RenderPresent(renderer);
}