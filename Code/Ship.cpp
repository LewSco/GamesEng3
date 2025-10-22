//Ship.cpp
#include "Ship.hpp"

Ship::Ship() {};

Ship::Ship(const Ship& s) : _sprite(s._sprite) 
{
}

Ship::Ship(sf::IntRect ir) : Sprite() 
{
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::update(const float& dt) {}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;