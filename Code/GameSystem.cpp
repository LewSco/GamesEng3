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

	shared_ptr<Invader> inv = make_shared<Invader>(IntRect(Vector2i(0, 0), Vector2i(32, 32)), Vector2f(100, 100));
	ships.push_back(inv); //This is when the copy constructor is called.
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