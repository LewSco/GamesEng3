//Ship.cpp
#include "Ship.hpp"
#include "GameSystem.hpp"

using gs = GameSystem;

Ship::Ship() {};

Ship::Ship(const Ship& s) : _src(s._src) 
{}

Ship::Ship(IntRect src) : Sprite() 
{
	_src = src;
	setTexture(gs::spritesheet);
	setTextureRect(_src);
};

void Ship::Update(const float& dt) {}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;