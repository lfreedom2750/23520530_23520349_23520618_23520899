#include <OptionState.hpp>
#include <DEFINITIONS.hpp>

#include <sstream>
#include <iostream>

namespace Engine
{
	OptionState::OptionState(GameDataRef data) : m_data(data) {}

	void OptionState::Init()
	{
		std::cout << "Option State" << std::endl;

		m_data->assets.LoadTexture("Game Background",
			GAME_BACKGROUND_FILEPATH);
		m_data->assets.LoadTexture("Game Title",
			GAME_TITLE_FILEPATH);
		m_data->assets.LoadFont("Gameplay Button Font", 
			GAMEPLAY_BUTTON_FONT_FILEPATH);
		m_data->assets.LoadFont("Highscore Button Font", 
			HIGHSCORE_BUTTON_FONT_FILEPATH);
		m_data->assets.LoadFont("Exit Button Font", 
			EXIT_BUTTON_FONT_FILEPATH);

		m_background.setTexture(m_data->assets.GetTexture("Game Background"));
		m_title.setTexture(m_data->assets.GetTexture("Game Title"));
		m_gameplayButton.setFont(m_data->assets.GetFont("Gameplay Button Font"));
		m_highscoreButton.setFont(m_data->assets.GetFont("Highscore Button Font"));
		m_exitButton.setFont(m_data->assets.GetFont("Exit Button Font"));

		m_gameplayButton.setString("GAMEPLAY");
		m_highscoreButton.setString("HIGHSCORE");
		m_exitButton.setString("EXIT");

		m_exitButton.setPosition(20.0f, SCREEN_HEIGHT - 40.0f);
		m_gameplayButton.setPosition((SCREEN_WIDTH / 2) - 450.0f, (SCREEN_HEIGHT / 2)-
			(m_gameplayButton.getGlobalBounds().height / 2) + 125.0f);
		m_highscoreButton.setPosition((SCREEN_WIDTH / 2) - 50.0f, (SCREEN_HEIGHT / 2) -
			(m_highscoreButton.getGlobalBounds().height / 2) + 125.0f);

	}

	void OptionState::ProcessInput()
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

	void OptionState::Update(float dt)
	{

	}

	void OptionState::Draw(float dt)
	{
		m_data->window.clear();

		m_data->window.draw(m_background);
		m_data->window.draw(m_title);
		m_data->window.draw(m_gameplayButton);
		m_data->window.draw(m_highscoreButton);
		m_data->window.draw(m_exitButton);

		m_data->window.display();
	}
}