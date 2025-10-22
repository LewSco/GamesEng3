//Ship.hpp
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Ship : public Sprite 
{

    public:
        Ship();

        //Copy constructor
        Ship(const Ship& s);

        //Constructor that takes a sprite
        Ship(IntRect source);

        //Pure virtual deconstructor -- makes this an abstract class and avoids undefined behaviour!
        virtual ~Ship() = 0;

        //Update, virtual so can be overridden, but not pure virtual
        virtual void Update(const float& deltaTime);

    protected:
        IntRect _sprite;
};
