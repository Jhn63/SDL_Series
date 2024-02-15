#include "ErroMgr.hpp"

void ErroMgr::assert(const bool& cdt, const char* msg) {
    if (!cdt) {
        std::cout << msg << ". ERRO: " << SDL_GetError();
        exit(-1);
    }
}