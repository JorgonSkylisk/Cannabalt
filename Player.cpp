// **** LIBRARIES ****


// Project Includes
#include "Player.h"
#include "AssetManager.h"

// Constants
#define JUMP_SPEED -1500.0f
#define RUN_SPEED_INITIAL 500.0f
#define GRAVITY 2000.0f


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
			m_animation.Play("jump");
			// set upward velocity
			m_Velocity.y = JUMP_SPEED;
		}
	}

}

void Player::Update(sf::Time _frameTime)
{

	// Process animation
	m_animation.Update(_frameTime);
	
	if (m_touchingGround == false)
	{
		// Gravity to velocity
		float velocityChange = GRAVITY * _frameTime.asSeconds();
		m_Velocity.y += velocityChange;
	}
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

sf::Vector2f Player::GetPosition()
{
	return m_sprite.getPosition();
}

void Player::handleCollision(sf::FloatRect _platform)
{
	//assume not touching anything
	bool hadCollision = false;

	//Collider for player
	sf::FloatRect PlayerCollider = m_sprite.getGlobalBounds();
	//does sprite intersect platform
	if (PlayerCollider.intersects(_platform))
	{
		// YE
		// Check if feet are touching top of platform and are falling
		sf::FloatRect FeetCollider = PlayerCollider;
		// Sett feet 10 pixels up from bottom of collider
		FeetCollider.top += PlayerCollider.height - 10;
		//set feet collider height to 10
		FeetCollider.height = 10;

		sf::FloatRect platformtop = _platform;
		platformtop.height = 10;

		// Are feet and platform top colliding
		if (FeetCollider.intersects(platformtop))
		{
			hadCollision = true;
			
			if (m_Velocity.y > 0)
			{
				if (m_touchingGround == false)
				{
					//touching ground
					m_animation.Play("run");
					m_landSound.play();
					m_Velocity.y = 0;
					m_touchingGround = true;
				}
			}

		}

	}
	if (hadCollision == false)
	{
		m_touchingGround = false;
	}
}