// **** LIBRARIES ****


// Project Includes
#include "Player.h"
#include "AssetManager.h"

// Constants
#define JUMP_SPEED -1500.0f
#define RUN_SPEED_INITIAL 500.0f
#define GRAVITY 2000.0f
//#define RUN_ACCEL 100.0f

Player::Player():
	m_sprite(),
	m_jumpSound(),
	m_deathSound(),
	m_landSound(),
	m_animation(),
	m_Velocity(0.0f,0.0f)
{
	// Sprite setup
	m_sprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));
	m_jumpSound.setBuffer(AssetManager::GetSoundBuffer("audio/jump.wav"));
	m_deathSound.setBuffer(AssetManager::GetSoundBuffer("audio/death.wav"));
	m_landSound.setBuffer(AssetManager::GetSoundBuffer("audio/landing.wav"));

	//Animation
	m_animation.SetSprite(m_sprite);


	Animation& RunAnimation = m_animation.CreateAnimation("run");
	RunAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun1.png"));
	RunAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun2.png"));
	RunAnimation.SetLoop(true);
	RunAnimation.SetPlaybackSpeed(10.0f);

	Animation& jumpAnimation = m_animation.CreateAnimation("jump");
	jumpAnimation.AddFrame(AssetManager::GetTexture("graphics/playerJump.png"));

	m_animation.Play("jump");
}

void Player::Input(sf::Event _gameEvent)
{

	//check if player has pressed jump
	if (_gameEvent.type == sf::Event::KeyPressed)
	{
		// check if space
		if (_gameEvent.key.code == sf::Keyboard::Space)
		{
			//play jump sound
			m_jumpSound.play();
			// set upward velocity
			m_Velocity.y = JUMP_SPEED;
		}
	}

}

void Player::Update(sf::Time _frameTime)
{

	// Process animation
	m_animation.Update(_frameTime);
	
	// Gravity to velocity
	float velocityChange = GRAVITY * _frameTime.asSeconds();
	m_Velocity.y += velocityChange;

	// move sprite based on velocity
	sf::Vector2f currentPosition = m_sprite.getPosition();
	sf::Vector2f postionChange = m_Velocity * _frameTime.asSeconds();
	m_sprite.setPosition(currentPosition + postionChange);

}

void Player::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);



}

void Player::Spawn()
{
	m_sprite.setPosition(0, 0);
	m_animation.Play("jump");
	m_Velocity.y = 0;
	m_Velocity.x = RUN_SPEED_INITIAL;
}