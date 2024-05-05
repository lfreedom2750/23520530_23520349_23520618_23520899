#pragma once

#include <SFML/Graphics.hpp>

#include <State.hpp>
#include <Game.hpp>

namespace Engine
{
	class MainMenuState : public State
	{
	private:
		GameDataRef m_data;
		sf::Sprite m_title;
		sf::Sprite m_playButton;
		sf::Sprite m_background;
	public:
		MainMenuState(GameDataRef data);

		void Init();
		void ProcessInput();
		void Update(float dt);
		void Draw(float dt);

	};
}