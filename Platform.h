#pragma once
// **** LIBRARIES ****
#include <SFML/Graphics.hpp>

class Platform
{

public:

	Platform();

	//void Update(sf::Time _frameTime);
	void Draw(sf::RenderTarget& _target);

	void Spawn();

private:
	sf::Sprite m_sprite;


};

