#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class AssetManager
{

public:

	// Public interface / behaviours

	// Constructor
	AssetManager();

	// Get texture based on a file name
	static sf::Texture& GetTexture(std::string _fileName);
	// Get soundBuffer based on a file name
	//sf::Texture& GetSoundBuffer(std::string _fileName);
	// Get Font based on a file name
	//sf::Texture& GetFont(std::string _fileName);

private:

	// Private data for this class

	// A pointer to the class itself for the singleton design pattern The one and only instance of this
	static AssetManager* s_instance;


	// List of textures
	std::map <sf::String, sf::Texture> m_textures;
	
	// List of sound buffers
	std::map <sf::String, sf::Texture> m_soundbuffers;

	// List of fonts
	std::map <sf::String, sf::Texture> m_fonts;


};

