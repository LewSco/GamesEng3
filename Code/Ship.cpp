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

Invader::Invader() : Ship() 
{}

Invader::Invader(const Invader& inv) : Ship(inv) 
{}

Invader::Invader(IntRect src, Vector2f pos) : Ship(src) 
{
	setOrigin(Vector2f(16.f, 16.f));;
	setPosition(pos);
}

void Invader::Update(const float& deltaTime) 
{
	Ship::Update(deltaTime);
}