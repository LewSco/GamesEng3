#include "Bullet.hpp"
#include "GameParameters.hpp"
#include "GameSystem.hpp"

using gs = GameSystem;
using param = Parameters;

unsigned char Bullet::_bulletPointer;
Bullet Bullet::_bullets[256];

Bullet::Bullet() {}

void Bullet::Update(const float& dt) 
{
    for (int i = 0; i < 256; i++)
        _bullets[i]._Update(dt);
}

void Bullet::Render(sf::RenderWindow& window) 
{
    for (int i = 0; i < 256; i++)
        window.draw(_bullets[i]);
}

void Bullet::Fire(const sf::Vector2f& pos, const bool mode) 
{
    Bullet& bullet = _bullets[++_bulletPointer];

    if (mode)
        bullet.setTextureRect(IntRect(Vector2i(param::SPRITE_SIZE, param::SPRITE_SIZE),
            Vector2i(param::SPRITE_SIZE, param::SPRITE_SIZE)));
    else
        bullet.setTextureRect(IntRect(Vector2i(param::SPRITE_SIZE * 2, param::SPRITE_SIZE),
            Vector2i(param::SPRITE_SIZE, param::SPRITE_SIZE)));

    bullet.setPosition(pos);
    bullet._mode = mode;
}

void Bullet::Init() 
{
    for (int i = 0; i < 256; i++) 
    {
        _bullets[i].setTexture(gs::spritesheet);
        _bullets[i].setOrigin(param::SPRITE_SIZE / 2.f, param::SPRITE_SIZE / 2.f);
        _bullets[i].setPosition(-100, -100);
    }
}

void Bullet::_Update(const float& dt) 
{
    if (getPosition().y < -param::SPRITE_SIZE || 
        getPosition().y > param::GAME_HEIGHT + param::SPRITE_SIZE) 
    {
        //off screen - do nothing
        return;
    }
    else 
    {
        move(Vector2f(0, dt * param::BULLET_SPEED * (_mode ? 1.0f : -1.0f)));

        const FloatRect boundingBox = getGlobalBounds();

        shared_ptr<Ship>& player = gs::ships[0]; //we know that the first ship is the player

        for (shared_ptr<Ship>& s : gs::ships) 
        {
            if (!_mode && s == player) 
            {
                //player bullets don't collide with player
                continue;
            }

            if (_mode && s != player) 
            {
                //invader bullets don't collide with other invaders
                continue;
            }

            if (!s->IsExploded() &&
                s->getGlobalBounds().intersects(boundingBox)) 
            {
                //Explode the ship
                s->Explode();

                //warp bullet off-screen
                setPosition(sf::Vector2f(-100, -100));

                return;
            }
        }
    }
}