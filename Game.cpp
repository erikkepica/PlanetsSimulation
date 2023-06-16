#include "Game.h"


void Game::Render()
{
	mp_Window->clear(sf::Color(18, 18, 18, 255));

	for (const auto& celestialBody : m_CelestialBodies)
	{
		mp_Window->draw(celestialBody->GetShape());
	}

	mp_Window->display();
}

void Game::Update()
{
	PollEvents();
	Render();

	for (const auto& celestialBody : m_CelestialBodies)
	{
		celestialBody->PhysicsUpdate(m_DeltaClock.getElapsedTime().asSeconds(), m_CelestialBodies);
	}

	open = mp_Window->isOpen();
	m_DeltaClock.restart();
}

void Game::PollEvents()
{
	sf::Event event;
	while (mp_Window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mp_Window->close();
		
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) { mp_Window->close(); }
		}
	}
}

Game::Game(std::string title)
{
	sf::VideoMode mode;

	mode.width = WIDTH;
	mode.height = HEIGHT;

	mp_Window = std::make_unique<sf::RenderWindow>(mode, title, sf::Style::Close);
	mp_Window->setFramerateLimit(60);
	open = true;


	m_CelestialBodies.push_back(
		std::make_unique<CelestialBody>(100.f, sf::Color::Yellow, 100.f, sf::Vector2f(500, 500), sf::Vector2f(0, 0)));
	
	m_CelestialBodies.push_back(
		std::make_unique<CelestialBody>(10.f, sf::Color::Red, 1.2f, sf::Vector2f(800, 500), sf::Vector2f(0, 1)));
}

Game::~Game()
{
}


void DrawOrbits()
{

}