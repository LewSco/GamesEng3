//GameSystem.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

struct GameSystem 
{
    //The global variables goes here

    //game system functions
    static void Init();
    static void Clean();
    static void Update(const float& deltaTime);
    static void Render(sf::RenderWindow& window);
};