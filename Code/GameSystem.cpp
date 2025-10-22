#include "GameSystem.h"

Texture spritesheet;
Sprite invader;

/// <summary>
/// initialise all the objects needed for the game.
/// </summary>
void GameSystem::Init()
{
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png"))
	{
		std::cerr << "Failed to load spritesheet!" << std::endl;
	}

	invader.setTexture(spritesheet);
	invader.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(32, 32)));
}

/// <summary>
/// // Update Everything
/// </summary>
/// <param name="deltaTime"> deltaTime or the time between frames </param>
void GameSystem::Update(const float& deltaTime)
{

}

/// <summary>
/// Draw Everything
/// </summary>
/// <param name="window"></param>
void GameSystem::Render(RenderWindow& window)
{
	window.draw(invader);
}

void GameSystem::Clean()
{
	// free up the memory if necessary.
}