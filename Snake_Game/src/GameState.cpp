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
		m_data->assets.LoadTexture("Food", FOOD_FILEPATH);
		m_data->assets.LoadTexture("Snake", SNAKE_FILEPATH);
		m_data->assets.LoadTexture("Wall", WALL_FILEPATH, true);
		m_data->assets.LoadTexture("Grass", GRASS_FILEPATH, true);

		m_background.setTexture(m_data->assets.GetTexture("Game Background"));

		m_grass.setTexture(m_data->assets.GetTexture("Grass"));
		m_grass.setTextureRect(sf::IntRect({ 0, 0, 750, 720 }));

		for (auto& wall : m_walls)
		{
			wall.setTexture(m_data->assets.GetTexture("Wall"));
		}

		m_walls[0].setTextureRect({ 0, 0, 750, 16 });
		m_walls[1].setTextureRect({ 0, 0, 750, 16 });
		m_walls[1].setPosition(0, 720 - 16);

		m_walls[2].setTextureRect({ 0, 0, 16, 720 });
		m_walls[3].setTextureRect({ 0, 0, 16, 720 });
		m_walls[3].setPosition(750 - 16, 0);

		m_food.setTexture(m_data->assets.GetTexture("Food"));
		m_food.setPosition(750 - 400, 720 - 400);
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
		m_data->window.draw(m_grass);

		for (auto& wall : m_walls)
		{
			m_data->window.draw(wall);
		}

		m_data->window.draw(m_food);

		m_data->window.display();
	}

	void GameState::Pause()
	{

	}

	void GameState::Resume()
	{

	}

}