#include "Game.hpp"

int main(int argc, char* argv[]) {
    Game pong(WINDOW_WIDTH, WINDOW_HIGHT);
    pong.loop();
    return 0;
}