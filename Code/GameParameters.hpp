//GameParameters.hpp
#pragma once //insure that this header file is included only once and there will no multiple definition of the same thing
#include <SFML/Graphics.hpp>

struct Parameters 
{
    static constexpr float TIME_STEP = 0.017f; // 60 fps
    static constexpr int GAME_WIDTH = 800;
    static constexpr int GAME_HEIGHT = 600;
    static constexpr int SPRITE_SIZE = 32;
    static constexpr int GROUP_SIZE_X = 12;
    static constexpr int GROUP_SIZE_Y = 6;
    static constexpr int ENEMY_SPACING = 16;
};