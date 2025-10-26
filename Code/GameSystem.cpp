#include "GameSystem.hpp"

Texture GameSystem::spritesheet;
vector<shared_ptr<Ship>> GameSystem::ships;

/// <summary>
/// initialise all the objects needed for the game.
/// </summary>
void GameSystem::Init()
{
	if (!spritesheet.loadFromFile("Res/Img/invaders_sheet.png"))
	{
		std::cerr << "Failed to load spritesheet!" << std::endl;
	}
	
	for (int r = 0; r < param::rows; ++r) 
	{
		auto rect = IntRect(...);
		for (int c = 0; c < param::columns; ++c) 
		{
			Vector2f position = ...;
			auto inv = new Invader(rect, position);
			ships.push_back(inv);
		}
}

/// <summary>
/// // Update Everything
/// </summary>
/// <param name="deltaTime"> deltaTime or the time between frames </param>
void GameSystem::Update(const float& deltaTime)
{
	for (std::shared_ptr<Ship>& ship : ships)
		ship->Update(deltaTime);
}

/// <summary>
/// Draw Everything
/// </summary>
/// <param name="window"></param>
void GameSystem::Render(RenderWindow& window)
{
	for (const std::shared_ptr<Ship>& ship : ships)
		window.draw(*(ship.get()));
}

void GameSystem::Clean()
{
	// free up the memory if necessary.
}