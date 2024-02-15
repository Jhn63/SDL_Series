#pragma once
#include <iostream>
#include <SDL.h>

class ErroMgr {
public:
    static void assert(const bool& cdt, const char* msg);
};