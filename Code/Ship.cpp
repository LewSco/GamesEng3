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

void Ship::MoveDown()
{
	Sprite::move(Vector2f(0.0f, _src.getSize().y / 2.f));
}

void Ship::Update(const float& dt) {}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;

#pragma region Invader

bool Invader::_direction = true;
float Invader::_speed = 10.f;
float Invader::_acc = 10.f;

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

#pragma region Player

Player::Player() : 
	Ship(IntRect(Vector2i(param::SPRITE_SIZE * 5, param::SPRITE_SIZE), 
		Vector2i(param::SPRITE_SIZE, param::SPRITE_SIZE)))
{
	setOrigin(param::SPRITE_SIZE / 2.f, param::SPRITE_SIZE / 2.f);;

	setPosition(param::GAME_WIDTH / 2.f, 
		param::GAME_HEIGHT - static_cast<float>(param::SPRITE_SIZE));
}

void Player::Update(const float& dt) 
{
	
	Ship::Update(dt);
	
	if (Keyboard::isKeyPressed(Keyboard::A)) //Move left
	{
		float leftBnd = param::SPRITE_SIZE / 2.f;
		if (getPosition().x - param::PLAYER_SPEED * dt < leftBnd)
			setPosition(leftBnd, getPosition().y);
		else
			move(-param::PLAYER_SPEED * dt, 0);
	}	
	else if (Keyboard::isKeyPressed(Keyboard::D)) //Move Right
	{
		float rightBnd = param::GAME_WIDTH - param::SPRITE_SIZE / 2.f;

		if (getPosition().x + param::PLAYER_SPEED * dt > rightBnd)
			setPosition(rightBnd, getPosition().y);
		else
			move(param::PLAYER_SPEED * dt, 0);
	}
}

#pragma endregion
