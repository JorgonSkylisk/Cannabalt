// **** LIBRARIES ****
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>

//Project Includes
#include "AssetManager.h"
#include "Player.h"
#include "Platform.h"

int main()
{
	// ****************************
	// ******** GAME SETUP ********
	// ****************************
	// Declare variable for display window
	sf::RenderWindow gamewindow;
	gamewindow.create(sf::VideoMode::getDesktopMode(), "Button Masher",
	sf::Style::Titlebar | sf::Style::Close);
	
	// TIMER
	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;

	// Create AssetManager
	AssetManager assets;

	// Seed RNG
	srand(time(NULL));

	// Create Player
	Player player;
	player.Spawn();

	// Create Camera
	sf::View Camera = gamewindow.getDefaultView();

	// Create platform
	Platform platform;
	platform.Spawn();


	// *****************
	// *** END SETUP ***
	// *****************


	// *************************
	// ******* game loop *******
	// *************************
	while (gamewindow.isOpen())

	{
		// *****************
		// ***** INPUT *****
		// *****************


		sf::Event event;
		while (gamewindow.pollEvent(event))
		{
			//pass input to game objects
			player.Input(event);

			if (event.type == sf::Event::Closed)
				gamewindow.close();
		} // End IF

		// *** End INPUT ***

	//************************
	//******** UPDATE ********
	//************************
		sf::Time frameTime = gameClock.restart();
		
		//process game objects
		player.Update(frameTime);
	
		// Update cam pos
		Camera.setCenter(player.GetPosition().x + Camera.getSize().x * 0.4f, Camera.getCenter().y);




	// *** END UPDATE ***
		
	// *****************
	// ****** DRAW *****
	// *****************


		gamewindow.clear();

		//Draw everything

		//draw game world using camera
		gamewindow.setView(Camera);
		player.Draw(gamewindow);
		platform.Draw(gamewindow);
		
		//draw UI to the window
		gamewindow.setView(gamewindow.getDefaultView());


		//display all content
		gamewindow.display();

	// *** END DRAW ***

	}// End WHILE
	
	 
	 
	// *****************
	// * END GAME LOOP *
	// *****************

	return 0;
}