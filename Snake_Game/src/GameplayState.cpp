#include <GameplayState.hpp>
#include <GameState.hpp>
#include <OptionState.hpp>
#include <DEFINITIONS.hpp>	

#include <sstream>
#include <iostream>

namespace Engine
{
	GameplayState::GameplayState(GameDataRef data) : m_data(data), m_isclassicButtonClicked(false),
		m_ismodernButtonClicked(false), m_isLevel1Clicked (false), m_isLevel2Clicked (false), 
		m_isLevel3Clicked (false), m_isLevel4Clicked (false), m_isLevel5Clicked(false) {}

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
		m_data->assets.LoadFont("Level Button Font",
			LEVEL_BUTTON_FONT_FILEPATH);
		m_data->assets.LoadTexture("Play Button",
			PLAY_BUTTON_2_FILEPATH);
		m_data->assets.LoadTexture("Level 1", LEVEL1_BUTTON_FILEPATH);
		m_data->assets.LoadTexture("Level 2", LEVEL2_BUTTON_FILEPATH);
		m_data->assets.LoadTexture("Level 3", LEVEL3_BUTTON_FILEPATH);
		m_data->assets.LoadTexture("Level 4", LEVEL4_BUTTON_FILEPATH);
		m_data->assets.LoadTexture("Level 5", LEVEL5_BUTTON_FILEPATH);


		m_background.setTexture(m_data->assets.GetTexture("Game Background"));
		m_title.setTexture(m_data->assets.GetTexture("Game Title"));
		m_playButton.setTexture(m_data->assets.GetTexture("Play Button"));
		m_classicButton.setFont(m_data->assets.GetFont("Classic Button Font"));
		m_modernButton.setFont(m_data->assets.GetFont("Modern Button Font"));
		m_backButton.setFont(m_data->assets.GetFont("Back Button Font"));
		m_levelButton.setFont(m_data->assets.GetFont("Level Button Font"));

		m_level1.setTexture(m_data->assets.GetTexture("Level 1"));
		m_level2.setTexture(m_data->assets.GetTexture("Level 2"));
		m_level3.setTexture(m_data->assets.GetTexture("Level 3"));
		m_level4.setTexture(m_data->assets.GetTexture("Level 4"));
		m_level5.setTexture(m_data->assets.GetTexture("Level 5"));

		m_classicButton.setString("CLASSIC");
		m_modernButton.setString("MODERN");
		m_backButton.setString("BACK");
		m_levelButton.setString("LEVEL");

		m_backButton.setPosition(20.0f, SCREEN_HEIGHT - 40.0f);
		m_classicButton.setPosition((SCREEN_WIDTH / 2) - 450.0f, (SCREEN_HEIGHT / 2) -
			(m_classicButton.getGlobalBounds().height / 2) + 80.0f);
		m_modernButton.setPosition((SCREEN_WIDTH / 2) - 50.0f, (SCREEN_HEIGHT / 2) -
			(m_modernButton.getGlobalBounds().height / 2) + 80.0f);
		m_levelButton.setPosition((SCREEN_WIDTH / 2) - 450.0f, (SCREEN_HEIGHT / 2) -
			(m_levelButton.getGlobalBounds().height / 2) + 220.0f);
		m_playButton.setPosition((SCREEN_WIDTH / 2) + 174.0f, (SCREEN_HEIGHT / 2) -
			(m_playButton.getGlobalBounds().height / 2) + 160.0f);

		m_level1.setPosition((SCREEN_WIDTH / 2) - 230.0f, (SCREEN_HEIGHT / 2) -
			(m_level1.getGlobalBounds().height / 2) + 220.0f);
		m_level2.setPosition((SCREEN_WIDTH / 2) - 150.0f, (SCREEN_HEIGHT / 2) -
			(m_level2.getGlobalBounds().height / 2) + 220.0f);
		m_level3.setPosition((SCREEN_WIDTH / 2) - 70.0f, (SCREEN_HEIGHT / 2) -
			(m_level3.getGlobalBounds().height / 2) + 220.0f);
		m_level4.setPosition((SCREEN_WIDTH / 2) + 10.0f, (SCREEN_HEIGHT / 2) -
			(m_level4.getGlobalBounds().height / 2) + 220.0f);
		m_level5.setPosition((SCREEN_WIDTH / 2) + 90.0f, (SCREEN_HEIGHT / 2) -
			(m_level5.getGlobalBounds().height / 2) + 220.0f);

		m_classicButton.setCharacterSize(35);
		m_modernButton.setCharacterSize(35);
		m_levelButton.setCharacterSize(35);

		m_levelButton.setFillColor(sf::Color::Cyan);
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

			if (m_data->input.IsSpriteClicked(m_playButton, sf::Mouse::Left, m_data->window))
			{
				m_data->states.AddState(StateRef(new GameState(m_data)), true);
			}

			if (m_data->input.IsTextClicked(m_backButton, sf::Mouse::Left,
				m_data->window))
			{
				if (m_isclassicButtonClicked || m_ismodernButtonClicked)
				{
					m_data->states.AddState(StateRef(new GameplayState(m_data)), true);
				}
				else
				{
					m_data->states.AddState(StateRef(new OptionState(m_data)), true);
				}
			}

			if (m_data->input.IsTextClicked(m_classicButton, sf::Mouse::Left,
				m_data->window))
			{
					m_isclassicButtonClicked = true;
					m_ismodernButtonClicked = false;
			}

			else if (m_data->input.IsTextClicked(m_modernButton, sf::Mouse::Left,
				m_data->window))
			{
				m_ismodernButtonClicked = true;
				m_isclassicButtonClicked = false;
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

				if (m_level1.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				{
					m_level1.setColor(sf::Color::Yellow);
				}
				else
				{
					m_level1.setColor(sf::Color::White);
				}


				if (m_level2.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				{
					m_level2.setColor(sf::Color::Yellow);
				}
				else
				{
					m_level2.setColor(sf::Color::White);
				}

				if (m_level3.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				{
					m_level3.setColor(sf::Color::Yellow);
				}
				else
				{
					m_level3.setColor(sf::Color::White);
				}


				if (m_level4.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				{
					m_level4.setColor(sf::Color::Yellow);
				}
				else
				{
					m_level4.setColor(sf::Color::White);
				}


				if (m_level5.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				{
					m_level5.setColor(sf::Color::Yellow);
				}
				else
				{
					m_level5.setColor(sf::Color::White);
				}

				if (m_playButton.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				{
					m_playButton.setColor(sf::Color::Green);
				}
				else
				{
					m_playButton.setColor(sf::Color::White);
				}

			}

			if (m_data->input.IsSpriteClicked(m_level1, sf::Mouse::Left,
				m_data->window))
			{
				m_isLevel1Clicked = true;
				m_isLevel2Clicked = false;
				m_isLevel3Clicked = false;
				m_isLevel4Clicked = false;
				m_isLevel5Clicked = false;
			}

			else if (m_data->input.IsSpriteClicked(m_level2, sf::Mouse::Left,
				m_data->window))
			{
				m_isLevel1Clicked = false;
				m_isLevel2Clicked = true;
				m_isLevel3Clicked = false;
				m_isLevel4Clicked = false;
				m_isLevel5Clicked = false;
			}

			else if (m_data->input.IsSpriteClicked(m_level3, sf::Mouse::Left,
				m_data->window))
			{
				m_isLevel1Clicked = false;
				m_isLevel2Clicked = false;
				m_isLevel3Clicked = true;
				m_isLevel4Clicked = false;
				m_isLevel5Clicked = false;
			}

			else if (m_data->input.IsSpriteClicked(m_level4, sf::Mouse::Left,
				m_data->window))
			{
				m_isLevel1Clicked = false;
				m_isLevel2Clicked = false;
				m_isLevel3Clicked = false;
				m_isLevel4Clicked = true;
				m_isLevel5Clicked = false;
			}

			else if (m_data->input.IsSpriteClicked(m_level5, sf::Mouse::Left,
				m_data->window))
			{
				m_isLevel1Clicked = false;
				m_isLevel2Clicked = false;
				m_isLevel3Clicked = false;
				m_isLevel4Clicked = false;
				m_isLevel5Clicked = true;
			}
		}
	}

	void GameplayState::Update(float dt)
	{
		sf::Event event;
		if (!m_isclassicButtonClicked)
		{
			m_classicButton.setOutlineColor(sf::Color::White);
			m_classicButton.setOutlineThickness(0);
			m_classicButton.setCharacterSize(35);
			while (m_data->window.pollEvent(event))
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
				}
		}

		if (!m_ismodernButtonClicked)
		{
			m_modernButton.setOutlineColor(sf::Color::White);
			m_modernButton.setOutlineThickness(0);;
			m_modernButton.setCharacterSize(35);
			while (m_data->window.pollEvent(event))
				if (sf::Event::MouseMoved == event.type)
				{
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

		
		if (!m_isLevel1Clicked)
		{
			m_level1.setPosition((SCREEN_WIDTH / 2) - 230.0f, (SCREEN_HEIGHT / 2) -
				(m_level1.getGlobalBounds().height / 2) + 220.0f);
			m_level1.setScale(1.0f, 1.0f);
			while (m_data->window.pollEvent(event))
				if (sf::Event::MouseMoved == event.type)
				{
					if (m_level1.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
					{
						m_level1.setColor(sf::Color::Yellow);
					}
					else
					{
						m_level1.setColor(sf::Color::White);
					}
				}

		}

		if (!m_isLevel2Clicked)
		{
			m_level2.setPosition((SCREEN_WIDTH / 2) - 150.0f, (SCREEN_HEIGHT / 2) -
				(m_level2.getGlobalBounds().height / 2) + 220.0f);
			m_level2.setScale(1.0f, 1.0f);
			while (m_data->window.pollEvent(event))
				if (sf::Event::MouseMoved == event.type)
				{
					if (m_level2.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
					{
						m_level2.setColor(sf::Color::Yellow);
					}
					else
					{
						m_level2.setColor(sf::Color::White);
					}
				}

		}

		if (!m_isLevel3Clicked)
		{
			m_level3.setPosition((SCREEN_WIDTH / 2) - 70.0f, (SCREEN_HEIGHT / 2) -
				(m_level3.getGlobalBounds().height / 2) + 220.0f);
			m_level3.setScale(1.0f, 1.0f);
			while (m_data->window.pollEvent(event))
				if (sf::Event::MouseMoved == event.type)
				{
					if (m_level3.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
					{
						m_level3.setColor(sf::Color::Yellow);
					}
					else
					{
						m_level3.setColor(sf::Color::White);
					}
				}

		}

		if (!m_isLevel4Clicked)
		{
			m_level4.setPosition((SCREEN_WIDTH / 2) + 10.0f, (SCREEN_HEIGHT / 2) -
				(m_level4.getGlobalBounds().height / 2) + 220.0f);
			m_level4.setScale(1.0f, 1.0f);
			while (m_data->window.pollEvent(event))
				if (sf::Event::MouseMoved == event.type)
				{
					if (m_level4.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
					{
						m_level4.setColor(sf::Color::Yellow);
					}
					else
					{
						m_level4.setColor(sf::Color::White);
					}
				}

		}

		if (!m_isLevel5Clicked)
		{
			m_level5.setPosition((SCREEN_WIDTH / 2) + 90.0f, (SCREEN_HEIGHT / 2) -
				(m_level5.getGlobalBounds().height / 2) + 220.0f);
			m_level5.setScale(1.0f, 1.0f);
			while (m_data->window.pollEvent(event))
				if (sf::Event::MouseMoved == event.type)
				{
					if (m_level5.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
					{
						m_level5.setColor(sf::Color::Yellow);
					}
					else
					{
						m_level5.setColor(sf::Color::White);
					}
				}

		}

		if (m_isLevel1Clicked)
		{
			m_level1.setColor(sf::Color::Yellow);
			m_level1.setPosition((SCREEN_WIDTH / 2) - 231.2f, (SCREEN_HEIGHT / 2) -
				(m_level1.getGlobalBounds().height / 2) + 218.8f);
			m_level1.setScale(1.2f, 1.2f);

		}

		if (m_isLevel2Clicked)
		{
			m_level2.setColor(sf::Color::Yellow);
			m_level2.setPosition((SCREEN_WIDTH / 2) - 151.2f, (SCREEN_HEIGHT / 2) -
				(m_level2.getGlobalBounds().height / 2) + 218.8f);
			m_level2.setScale(1.2f, 1.2f);

		}

		if (m_isLevel3Clicked)
		{
			m_level3.setColor(sf::Color::Yellow);
			m_level3.setPosition((SCREEN_WIDTH / 2) - 71.2f, (SCREEN_HEIGHT / 2) -
				(m_level3.getGlobalBounds().height / 2) + 218.8f);
			m_level3.setScale(1.2f, 1.2f);

		}

		if (m_isLevel4Clicked)
		{
			m_level4.setColor(sf::Color::Yellow);
			m_level4.setPosition((SCREEN_WIDTH / 2) + 8.8f, (SCREEN_HEIGHT / 2) -
				(m_level4.getGlobalBounds().height / 2) + 218.8f);
			m_level4.setScale(1.2f, 1.2f);
	
		}

		if (m_isLevel5Clicked)
		{
			m_level5.setColor(sf::Color::Yellow);
			m_level5.setPosition((SCREEN_WIDTH / 2) + 88.8f, (SCREEN_HEIGHT / 2) -
				(m_level5.getGlobalBounds().height / 2) + 218.8f);
			m_level5.setScale(1.2f, 1.2f);
;
		}


		if (m_isclassicButtonClicked)
		{
			m_classicButton.setFillColor(sf::Color::Yellow);
			m_classicButton.setOutlineColor(sf::Color::Red);
			m_classicButton.setCharacterSize(36);
			m_classicButton.setOutlineThickness(0.5);
		}

		if (m_ismodernButtonClicked)
		{
			m_modernButton.setFillColor(sf::Color::Yellow);
			m_modernButton.setOutlineColor(sf::Color::Red);
			m_modernButton.setCharacterSize(36);
			m_modernButton.setOutlineThickness(0.5);
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

		m_data->window.draw(m_levelButton);
		m_data->window.draw(m_level1);
		m_data->window.draw(m_level2);
		m_data->window.draw(m_level3);
		m_data->window.draw(m_level4);
		m_data->window.draw(m_level5);

		if ((m_isclassicButtonClicked && (m_isLevel1Clicked || m_isLevel2Clicked
			|| m_isLevel3Clicked || m_isLevel4Clicked || m_isLevel5Clicked)) || (m_ismodernButtonClicked && (m_isLevel1Clicked || m_isLevel2Clicked
				|| m_isLevel3Clicked || m_isLevel4Clicked || m_isLevel5Clicked)))
		{
			m_data->window.draw(m_playButton);
		}

		m_data->window.display();
	}

	std::string GameplayState::getGameplaySelected()
	{
		if (m_isclassicButtonClicked)
			return "classic";
		else if (m_ismodernButtonClicked)
			return "modern";
		return "Error";
	}

	int GameplayState::getLevelSelected()
	{
		if (m_isLevel1Clicked)
			return 1;
		else if (m_isLevel2Clicked)
			return 2;
		else if (m_isLevel3Clicked)
			return 3;
		else if (m_isLevel4Clicked)
			return 4;
		else if (m_isLevel5Clicked)
			return 5;
		return 0;
	}
}