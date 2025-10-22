//GameParameters.h
#pragma once //insure that this header file is included only once and there will no multiple definition of the same thing

struct Parameters 
{
    static constexpr float _timeStep = 0.017f; // 60 fps
    static constexpr int _gameWidth = 800;
    static constexpr int _gameHeight = 600;
    static constexpr int sprite_size = 32;
};