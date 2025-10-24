//Ship.cpp
#include "Ship.hpp"
#include "GameSystem.hpp"
#include "GameParameters.hpp"

using gs = GameSystem;
using param = Parameters;

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

#pragma region Invader

bool Invader::_direction;
float Invader::_speed;

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

	move(deltaTime * (_direction ? 1.0f : -1.0f) * _speed, 0.0f);

	if ((_direction && getPosition().x > param::GAME_WIDTH - param::SPRITE_SIZE / 2.f) ||
		(!_direction && getPosition().x < param::SPRITE_SIZE / 2.f)) 
	{
		_direction = !_direction;

		_speed += Invader::_acc;

		for (std::shared_ptr<Ship>& ship : gs::ships) 
		{
			ship->MoveDown();
		}
	}
}

#pragma endregion