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

	// Only proccess if it playing
	if (m_playing)
	{

		m_NextFrameChange -= _frameTime;
		if (m_NextFrameChange.asSeconds() <= 0)
		{

			//Change the frame
			++m_currentFrame;

			//Has End been reached?
			if (m_currentFrame >= m_frames.size())
			{
				//Reached end.
				//Should we loop
				if (m_loop)
				{
					//DO loop
					//wrap around to beginning
					m_currentFrame = 0;
				}
				else
				{
					//Should not loop
					//set frame as the last in list
					m_currentFrame = m_frames.size() - 1;

					//stop playing
					m_playing = false;
				}


				//TODO: What if no loop?

				
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
}

void Animation::Play()
{

	//update sprite to current frame
	if (m_sprite)
	{
		m_sprite->setTexture(*m_frames[m_currentFrame]);

	}


	//only start playing if playback speed is not 0
	if (m_playbackSpeed != 0)
	{
		m_playing = true;
		float timeToChange = 1.0f / m_playbackSpeed;
		m_NextFrameChange = sf::seconds(timeToChange);
	}
}

void Animation::Pause()
{
	//stops playback keeping current frame
	m_playing = false;
}

void Animation::Stop()
{
	//stops playback and resets frame
	m_playing = false;
	m_currentFrame = 0;
}

bool Animation::IsPlaying()
{
	//tells code if currently playing
	return m_playing;
}

void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(& _newFrame);

}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;

}

void Animation::SetPlaybackSpeed(float _framesPerSecond)
{

	m_playbackSpeed = _framesPerSecond;

	//if playback speed is 0 pause to avoid 0 divide error
	if (m_playbackSpeed == 0)
	{
		Pause();
	}

}

void Animation::SetLoop(bool _loop)
{
	m_loop = _loop;
}
