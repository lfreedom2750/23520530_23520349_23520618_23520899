#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include <State.hpp>
#include <Game.hpp>
#include <Snake.hpp>

#include <array>

namespace Engine
{
	class GameState : public State
	{
	private:
		GameDataRef m_data;
		sf::Sprite m_background;
		sf::Sprite m_grass;
		sf::Sprite m_food;
		std::array<sf::Sprite, 4> m_walls;

		Snake m_snake;
		sf::Vector2f m_direction;
		float m_elapsedTime;

	public:
		GameState(GameDataRef data);

		void Init();
		void ProcessInput();
		void Update(float dt);
		void Draw(float dt);

		void Pause();
		void Resume();
	};
}