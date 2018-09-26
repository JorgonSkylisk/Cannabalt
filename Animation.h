#pragma once


// Library include
#include <vector>
#include <SFML/Graphics.hpp>


class Animation
{


public:

	Animation();

	void Update(sf::Time _frameTime);

	void Play();
	void Pause();
	void Stop();
	
	bool IsPlaying();

	void AddFrame(sf::Texture& _NewFrame);
	void SetSprite(sf::Sprite& _sprite);
	void SetPlaybackSpeed(float _framesPerSecond);
	void SetLoop(bool _loop);


private:

	//Settings
	bool m_loop;
	std::vector<sf::Texture*> m_frames;
	sf::Sprite* m_sprite;
	float m_playbackSpeed;

	//State
	sf::Time m_NextFrameChange;
	int m_currentFrame;	
	bool m_playing;


};
