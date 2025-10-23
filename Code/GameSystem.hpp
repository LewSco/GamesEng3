//GameSystem.hpp
#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Ship.hpp"

using namespace sf;

struct GameSystem 
{
    //The global variables goes here
    static Texture spritesheet;

    //game system functions
    static void Init();
    static void Clean();
    static void Update(const float& deltaTime);
    static void Render(sf::RenderWindow& window);
};