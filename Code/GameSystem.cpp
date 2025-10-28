#include "GameSystem.hpp"
#include "GameParameters.hpp"

Texture GameSystem::spritesheet;
vector<shared_ptr<Ship>> GameSystem::ships;

using param = Parameters;

/// <summary>
/// initialise all the objects needed for the game.
/// </summary>
void GameSystem::Init()
{
	if (!spritesheet.loadFromFile("Res/Img/invaders_sheet.png"))
	{
		std::cerr << "Failed to load spritesheet!" << std::endl;
	}

	std::shared_ptr<Ship> player = std::make_shared<Player>();
	ships.push_back(player);

	/*ships.push_back(make_shared<Player>());*/

	for (int y = 0; y < param::GROUP_SIZE_Y; ++y)
	{
		auto rect = IntRect(32 * (4 - (((y + 2) / 2 - 1) * 2)), 0, 32, 32);

		for (int x = 0; x < param::GROUP_SIZE_X; ++x)
		{
			Vector2f position(x * (32 + param::ENEMY_SPACING) + 32 / 2.f,
				y * (32 + param::ENEMY_SPACING) + 32 / 2.f);
			auto inv = make_shared<Invader>(rect, position);
			ships.push_back(inv);
		}
	}
	
}

/// <summary>
/// Update Everything
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

/// <summary>
/// free up the memory if necessary.
/// </summary>
void GameSystem::Clean()
{
	for (std::shared_ptr<Ship>& ship : ships)
		ship.reset();//free up the memory of this shared pointer
	ships.clear();//clear the vector to be sure we free up any memory left.
}