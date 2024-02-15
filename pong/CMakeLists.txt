cmake_minimum_required(VERSION 3.10)
project(pong)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR "../SDL2/include")
set(SDL2_LIB_DIR "../SDL2/lib/x86")

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(pong src/main.cpp src/ErroMgr.cpp src/Game.cpp src/Player.cpp src/Ball.cpp src/Enemy.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
