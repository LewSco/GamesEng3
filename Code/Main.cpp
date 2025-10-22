#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameSystem.hpp"
#include "GameParameters.hpp"

using namespace sf;

int main() 
{
	//create the window
	RenderWindow window(VideoMode({ Parameters::_gameWidth, Parameters::_gameHeight }), "Space Invaders");
	// turn on vsync to limit the frame rate to the refresh rate of the monitor
	window.setVerticalSyncEnabled(true);
	//initialise and load
	GameSystem::Init();

	// Game loop runs while window is open
	while (window.isOpen()) 
	{
		//Calculate dt
		static Clock clock;
		const float deltaTime = clock.restart().asSeconds();

		// clear previous display
		window.clear();

		GameSystem::Update(deltaTime);
		GameSystem::Render(window);

		//wait for the time_step to finish before displaying the next frame.
		sleep(seconds(Parameters::_timeStep));
		//Wait for Vsync
		window.display();
	}

	// Unload and shutdown
	GameSystem::Clean();
}