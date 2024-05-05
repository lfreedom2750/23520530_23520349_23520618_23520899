#include <AssetMan.hpp>

namespace Engine
{
	void AssetMan::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;
		if (tex.loadFromFile(fileName))
		{
			m_textures[name] = tex;
		}
	}

	sf::Texture& AssetMan::GetTexture(std::string name)
	{
		return m_textures.at(name);
	}

	void AssetMan::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName))
		{
			m_fonts[name] = font;
		}
	}

	sf::Font& AssetMan::GetFont(std::string name)
	{
		return m_fonts.at(name);
	}
}