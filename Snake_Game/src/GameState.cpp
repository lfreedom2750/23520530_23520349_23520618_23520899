#include <GameState.hpp>
#include <DEFINITIONS.hpp>

#include <sstream>
#include <iostream>

namespace Engine
{
	GameState::GameState(GameDataRef data) : m_data(data) {}

	void GameState::Init()
	{
		std::cout << "Game State" << std::endl;

		m_data->assets.LoadTexture("Game Background",
			GAME_BACKGROUND_FILEPATH);

		m_background.setTexture(m_data->assets.GetTexture("Game Background"));
	}

	void GameState::ProcessInput()
	{
		sf::Event event;
		while (m_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				m_data->window.close();
			}


		}
	}

	void GameState::Update(float dt)
	{

	}

	void GameState::Draw(float dt)
	{
		m_data->window.clear();

		m_data->window.draw(m_background);

		m_data->window.display();
	}
}