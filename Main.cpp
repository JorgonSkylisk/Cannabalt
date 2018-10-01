// **** LIBRARIES ****
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>

//Project Includes
#include "AssetManager.h"
#include "Animation.h"
#include "AnimationSystem.h"


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

	// Testing AssetManager
	sf::Sprite TestSprite;
	TestSprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));
	
	sf::Sound testSound;
	testSound.setBuffer(AssetManager::GetSoundBuffer("audio/death.wav"));
	testSound.play();

	sf::Text testFont;
	testFont.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	testFont.setString("BORK BORK");

	// Add Testing section for animation
	AnimationSystem testAnimationSystem;
	testAnimationSystem.SetSprite(TestSprite);


	Animation& TestAnimation = testAnimationSystem.CreateAnimation("run");
	TestAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun1.png"));
	TestAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun2.png"));
	TestAnimation.SetLoop(true);
	TestAnimation.SetPlaybackSpeed(10.0f);

	Animation& jumpAnimation = testAnimationSystem.CreateAnimation("jump");
	jumpAnimation.AddFrame(AssetManager::GetTexture("graphics/playerJump.png"));

	testAnimationSystem.Play("run");


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
			if (event.type == sf::Event::Closed)
				gamewindow.close();
		} // End IF

		// *** End INPUT ***

	//************************
	//******** UPDATE ********
	//************************
		sf::Time frameTime = gameClock.restart();
		testAnimationSystem.Update(frameTime);
	

	// *** END UPDATE ***
		
	// *****************
	// ****** DRAW *****
	// *****************

		gamewindow.clear();
		gamewindow.draw(TestSprite);
		gamewindow.draw(testFont);
		gamewindow.display();

	// *** END DRAW ***

	}// End WHILE
	
	 
	 
	// *****************
	// * END GAME LOOP *
	// *****************

	return 0;
}