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

	sf::FloatRect GetCollider();
private:
	sf::Sprite m_sprite;


};

