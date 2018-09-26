//Project Includes
#include "Animation.h"

Animation::Animation()
	:m_frames()
	,m_sprite(nullptr)
	,m_playbackSpeed(15.0f)
	,m_loop(false)
	,m_playing(false)
	,m_NextFrameChange()
	,m_currentFrame(0)
{

}

void Animation::Update(sf::Time _frameTime)
{
	m_NextFrameChange -= _frameTime;
	if (m_NextFrameChange.asSeconds() <= 0)
	{
		
		//Cjange the frame
		++m_currentFrame;
		//Has End been reached?
		if (m_currentFrame >= m_frames.size())
		{
			//Reached end.
			//TODO: What if no loop?

			//wrap around to beginning
			m_currentFrame = 0;
		}

		//update sprite texture to match new frame
		//does sprite exist
		if (m_sprite)
		{
			m_sprite->setTexture(*m_frames[m_currentFrame]);


		}

		//determine time for next frame change
		float timeToChange = 1.0f / m_playbackSpeed;
		m_NextFrameChange = sf::seconds(timeToChange);

	}
}

void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(& _newFrame);

}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;

}


