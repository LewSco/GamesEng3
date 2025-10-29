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
        Ship(IntRect src);

        //Pure virtual deconstructor -- makes this an abstract class and avoids undefined behaviour!
        virtual ~Ship() = 0;

        //Update, virtual so can be overridden, but not pure virtual
        virtual void Update(const float& deltaTime);

        void MoveDown();

    protected:
        IntRect _src; // source rectangle for the sprite
};

class Invader : public Ship 
{

    static bool _direction;
    static float _speed;
    static float _acc;

    public:

        Invader();

        Invader(const Invader& inv);

        Invader(IntRect src, Vector2f pos);

        void Update(const float& deltaTime) override;
};

class Player : public Ship 
{
    public:
        Player();
        void Update(const float& dt) override;
};