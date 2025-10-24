//GameParameters.hpp
#pragma once //insure that this header file is included only once and there will no multiple definition of the same thing

struct Parameters 
{
    static constexpr float TIME_STEP = 0.017f; // 60 fps
    static constexpr int GAME_WIDTH = 800;
    static constexpr int GAME_HEIGHT = 600;
    static constexpr int SPRITE_SIZE = 32;
};