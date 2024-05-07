#pragma once

#include <SFML/Graphics.hpp>

#include <State.hpp>
#include <Game.hpp>

namespace Engine
{
	class GameplayState : public State
	{
	private:
		GameDataRef m_data;
		sf::Sprite m_background;
		sf::Sprite m_title;
		sf::Text m_classicButton;
		sf::Text m_modernButton;
		sf::Text m_backButton;
		sf::Text m_levelButton;

		bool m_isclassicButtonClicked;
		bool m_ismodernButtonClicked;
		
	public:
		GameplayState(GameDataRef data);

		void Init();
		void ProcessInput();
		void Update(float dt);
		void Draw(float dt);

	};
}