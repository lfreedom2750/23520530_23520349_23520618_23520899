#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{
	class InputMan
	{
	public:
		InputMan() {}
		~InputMan() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, 
			sf::RenderWindow& window);

		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	};
}