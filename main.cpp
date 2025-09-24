#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;


const int _gameWidth = 800;
const int _gameHeight = 600;
const float _timeStep = 0.017f; //60 fps

/// <summary>
/// initialise all the objects needed for the game.
/// </summary>
void Init() 
{ 
}

/// <summary>
/// // Update Everything
/// </summary>
/// <param name="dt"> deltaTime or the time between frames </param>
void Update(float deltaTime) 
{

}

/// <summary>
/// Draw Everything
/// </summary>
/// <param name="window"></param>
void Render(RenderWindow& window) 
{

}

void Clean() 
{
	// free up the memory if necessary.
}

int main() 
{
	//create the window
	RenderWindow window(VideoMode({ _gameWidth, _gameHeight }), "PONG");
	// turn on vsync to limit the frame rate to the refresh rate of the monitor
	window.setVerticalSyncEnabled(true);
	//initialise and load
	Init();

	// Game loop runs while window is open
	while (window.isOpen()) 
	{
		//Calculate dt
		static sf::Clock clock;
		const float deltaTime = clock.restart().asSeconds();

		// clear previous display
		window.clear();

		Update(deltaTime);
		Render(window);

		//wait for the time_step to finish before displaying the next frame.
		sleep(seconds(_timeStep));
		//Wait for Vsync
		window.display();
	}

	//Unload and shutdown
	Clean();
}