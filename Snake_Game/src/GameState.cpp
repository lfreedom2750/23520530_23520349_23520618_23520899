#include <GameState.hpp>
#include <DEFINITIONS.hpp>

#include <SFML/Window/Event.hpp>

#include <sstream>
#include <iostream>

namespace Engine
{
	GameState::GameState(GameDataRef data) : m_data(data), m_direction({ 16.f, 0.f }),
		m_elapsedTime(0.f)
	{

	}

	void GameState::Init()
	{
		std::cout << "Game State" << std::endl;

		m_data->assets.LoadTexture("Game Background",
			GAME_BACKGROUND_FILEPATH);
		m_data->assets.LoadTexture("Food", FOOD_FILEPATH);
		m_data->assets.LoadTexture("Snake", SNAKE_FILEPATH);
		m_data->assets.LoadTexture("Wall", WALL_FILEPATH, true);
		m_data->assets.LoadTexture("Grass", GRASS_FILEPATH, true);

		m_background.setTexture(m_data->assets.GetTexture("Game Background"));

		m_grass.setTexture(m_data->assets.GetTexture("Grass"));
		m_grass.setTextureRect(sf::IntRect({ 0, 0, GAME_FRAME_WIDTH, GAME_FRAME_HEIGHT }));

		for (auto& wall : m_walls)
		{
			wall.setTexture(m_data->assets.GetTexture("Wall"));
		}

		m_walls[0].setTextureRect({ 0, 0, GAME_FRAME_WIDTH, 16 });
		m_walls[1].setTextureRect({ 0, 0, GAME_FRAME_WIDTH, 16 });
		m_walls[1].setPosition(0, GAME_FRAME_HEIGHT - 16);

		m_walls[2].setTextureRect({ 0, 0, 16, GAME_FRAME_HEIGHT });
		m_walls[3].setTextureRect({ 0, 0, 16, GAME_FRAME_HEIGHT });
		m_walls[3].setPosition(GAME_FRAME_WIDTH - 16, 0);

		m_food.setTexture(m_data->assets.GetTexture("Food"));
		m_food.setPosition(GAME_FRAME_WIDTH - 400, GAME_FRAME_HEIGHT - 400);

		m_snake.Init(m_data->assets.GetTexture("Snake"));
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
			else if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
				case sf::Keyboard::W:
					m_direction = { 0.f, -16.f };
					break;
				case sf::Keyboard::Down:
				case sf::Keyboard::S:
					m_direction = { 0.f, 16.f };
					break;
				case sf::Keyboard::Right:
				case sf::Keyboard::D:
					m_direction = { 16.f, 0.f };
					break;
				case sf::Keyboard::Left:
				case sf::Keyboard::A:
					m_direction = { -16.f, 0.f };
					break;
				default:
					break;
				}
			}

		}
	}

	void GameState::Update(float dt)
	{
		m_elapsedTime += dt;
		if (m_elapsedTime > SNAKE_SPEED)
		{
			if (m_snake.IsOn(m_food))
			{
				m_snake.Grow(m_direction);
			}
			else
			{
				m_snake.Move(m_direction);
			}
			m_elapsedTime = 0;
		}
	}

	void GameState::Draw(float dt)
	{
		m_data->window.clear();

		m_data->window.draw(m_background);
		m_data->window.draw(m_grass);

		for (auto& wall : m_walls)
		{
			m_data->window.draw(wall);
		}

		m_data->window.draw(m_food);
		m_data->window.draw(m_snake);

		m_data->window.display();
	}

	void GameState::Pause()
	{

	}

	void GameState::Resume()
	{

	}

}