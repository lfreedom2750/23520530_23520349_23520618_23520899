#pragma once

#include <SFML/Graphics.hpp>

#include <State.hpp>
#include <Game.hpp>

namespace Engine
{
	class GameState : public State
	{
	private:
		GameDataRef m_data;
		sf::Sprite m_background;
	public:
		GameState(GameDataRef data);

		void Init();
		void ProcessInput();
		void Update(float dt);
		void Draw(float dt);

	};
}