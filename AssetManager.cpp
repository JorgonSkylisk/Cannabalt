// Library includes
#include <assert.h>

//Project Includes
#include "AssetManager.h"

// Initialise the static referrence
AssetManager* AssetManager::s_instance = nullptr;

//Constructor
AssetManager::AssetManager()
	:m_textures		(),
	 m_soundbuffers (),
	 m_fonts		()
{
// Thrownan error and stop execution if a copy throw

	assert(s_instance == nullptr);

	//Assign ourselves to the instance pointer
	s_instance = this;

}

sf::Texture& AssetManager::GetTexture(std::string _fileName)
{
	//creat an iterator to hold key value
	auto keyValuePair = s_instance->m_textures.find(_fileName);
	// "auto" can be used when the compiler can figure out the type of variable for you
	// NOT ALLOWED TO USE THIS EXCEPT FOR ITERATIORS

	// Was texture already loaded?
	if (keyValuePair != s_instance->m_textures.end())
	{
		// Yes
		return keyValuePair->second;
	}
	else
	{
		// No
		// Create a new key value Pair using the filename
		// the subscript [] creates am entry in the map

		sf::Texture& texture = s_instance->m_textures[_fileName];
		// Blank texture loaded
		// load using SFML
		texture.loadFromFile(_fileName);

		// return the texture
		return texture;
	}
}


sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string _fileName)
{
	//creat an iterator to hold key value
	auto keyValuePair = s_instance->m_soundbuffers.find(_fileName);
	// "auto" can be used when the compiler can figure out the type of variable for you
	// NOT ALLOWED TO USE THIS EXCEPT FOR ITERATIORS

	// Was sound already loaded?
	if (keyValuePair != s_instance->m_soundbuffers.end())
	{
		// Yes
		return keyValuePair->second;
	}
	else
	{
		// No
		// Create a new key value Pair using the filename
		// the subscript [] creates am entry in the map

		sf::SoundBuffer& soundBuffer = s_instance->m_soundbuffers[_fileName];
		// Blank sound loaded
		// load using SFML
		soundBuffer.loadFromFile(_fileName);

		// return the sound
		return soundBuffer;
	}
}



sf::Font& AssetManager::GetFont(std::string _fileName)
{
	//creat an iterator to hold key value
	auto keyValuePair = s_instance->m_fonts.find(_fileName);
	// "auto" can be used when the compiler can figure out the type of variable for you
	// NOT ALLOWED TO USE THIS EXCEPT FOR ITERATIORS

	// Was sound already loaded?
	if (keyValuePair != s_instance->m_fonts.end())
	{
		// Yes
		return keyValuePair->second;
	}
	else
	{
		// No
		// Create a new key value Pair using the filename
		// the subscript [] creates am entry in the map

		sf::Font& font = s_instance->m_fonts[_fileName];
		// Blank sound loaded
		// load using SFML
		font.loadFromFile(_fileName);

		// return the sound
		return font;
	}
}