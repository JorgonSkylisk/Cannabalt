// **** LIBRARIES ****
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>

//Project Includes
#include "AssetManager.h"
#include "Player.h"

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

	Player player;
	player.Spawn();




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
	

	// *** END UPDATE ***
		
	// *****************
	// ****** DRAW *****
	// *****************

		gamewindow.clear();
		player.Draw(gamewindow);
		gamewindow.display();

	// *** END DRAW ***

	}// End WHILE
	
	 
	 
	// *****************
	// * END GAME LOOP *
	// *****************

	return 0;
}