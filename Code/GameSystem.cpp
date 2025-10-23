#include "GameSystem.hpp"

Texture GameSystem::spritesheet;

/// <summary>
/// initialise all the objects needed for the game.
/// </summary>
void GameSystem::Init()
{
	if (!spritesheet.loadFromFile("Res/Img/invaders_sheet.png"))
	{
		std::cerr << "Failed to load spritesheet!" << std::endl;
	}
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
}

void GameSystem::Clean()
{
	// free up the memory if necessary.
}