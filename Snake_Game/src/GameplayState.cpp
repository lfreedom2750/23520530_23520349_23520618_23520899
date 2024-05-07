#include <GameplayState.hpp>
#include <OptionState.hpp>
#include <DEFINITIONS.hpp>

#include <sstream>
#include <iostream>

namespace Engine
{
	GameplayState::GameplayState(GameDataRef data) : m_data(data), m_isclassicButtonClicked(false),
	m_ismodernButtonClicked(false) {}

	void GameplayState::Init()
	{
		std::cout << "Gameplay State" << std::endl;

		m_data->assets.LoadTexture("Game Background",
			GAME_BACKGROUND_FILEPATH);
		m_data->assets.LoadTexture("Game Title",
			GAME_TITLE_FILEPATH);
		m_data->assets.LoadFont("Classic Button Font",
			CLASSIC_BUTTON_FONT_FILEPATH);
		m_data->assets.LoadFont("Modern Button Font",
			MODERN_BUTTON_FONT_FILEPATH);
		m_data->assets.LoadFont("Back Button Font",
			BACK_BUTTON_FONT_FILEPATH);

		m_background.setTexture(m_data->assets.GetTexture("Game Background"));
		m_title.setTexture(m_data->assets.GetTexture("Game Title"));
		m_classicButton.setFont(m_data->assets.GetFont("Classic Button Font"));
		m_modernButton.setFont(m_data->assets.GetFont("Modern Button Font"));
		m_backButton.setFont(m_data->assets.GetFont("Back Button Font"));

		m_classicButton.setString("CLASSIC");
		m_modernButton.setString("MODERN");
		m_backButton.setString("BACK");

		m_backButton.setPosition(20.0f, SCREEN_HEIGHT - 40.0f);
		m_classicButton.setPosition((SCREEN_WIDTH / 2) - 450.0f, (SCREEN_HEIGHT / 2) -
			(m_classicButton.getGlobalBounds().height / 2) + 125.0f);
		m_modernButton.setPosition((SCREEN_WIDTH / 2) - 50.0f, (SCREEN_HEIGHT / 2) -
			(m_modernButton.getGlobalBounds().height / 2) + 125.0f);
	}

	void GameplayState::ProcessInput()
	{
		sf::Event event;
		while (m_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				m_data->window.close();
			}

			if (m_data->input.IsTextClicked(m_backButton, sf::Mouse::Left,
				m_data->window))
			{
				m_data->states.AddState(StateRef(new OptionState(m_data)), true);
			}

			if (m_data->input.IsTextClicked(m_classicButton, sf::Mouse::Left,
				m_data->window))
			{
				if (m_isclassicButtonClicked == false)
					m_classicButton.setFillColor(sf::Color::White);
					m_isclassicButtonClicked = true;
			}

			if (m_data->input.IsTextClicked(m_modernButton, sf::Mouse::Left,
				m_data->window))
			{
				if (m_ismodernButtonClicked == false)
					m_modernButton.setFillColor(sf::Color::White);
				m_ismodernButtonClicked = true;
			}

			if (sf::Event::MouseMoved == event.type)
			{
				if (m_classicButton.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				{
					m_classicButton.setFillColor(sf::Color::Yellow);
				}
				else
				{
					m_classicButton.setFillColor(sf::Color::White);
				}

				if (m_modernButton.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				{
					m_modernButton.setFillColor(sf::Color::Yellow);
				}
				else
				{
					m_modernButton.setFillColor(sf::Color::White);
				}

				if (m_backButton.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				{
					m_backButton.setFillColor(sf::Color::Yellow);
				}
				else
				{
					m_backButton.setFillColor(sf::Color::White);
				}
			}
		}
	}

	void GameplayState::Update(float dt)
	{
		if (m_isclassicButtonClicked)
		{
			m_classicButton.setFillColor(sf::Color::Yellow);
			m_isclassicButtonClicked = false;
		}

		if (m_ismodernButtonClicked)
		{
			m_modernButton.setFillColor(sf::Color::Yellow);
			m_ismodernButtonClicked = false;
		}
	}

	void GameplayState::Draw(float dt)
	{
		m_data->window.clear();

		m_data->window.draw(m_background);
		m_data->window.draw(m_title);
		m_data->window.draw(m_classicButton);
		m_data->window.draw(m_modernButton);
		m_data->window.draw(m_backButton);

		m_data->window.display();
	}
}