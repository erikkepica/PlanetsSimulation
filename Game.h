#pragma once
#include<iostream>
#include<list>
#include"SFML/Graphics.hpp"
#include"CelestialBodies.h"

class Game
{
public:
	bool open;
	sf::Clock m_DeltaClock;

	void Render();
	void PollEvents();
	void Update();


	Game(std::string title);
	~Game();

private:
	std::unique_ptr<sf::RenderWindow> mp_Window = std::make_unique<sf::RenderWindow>();
	sf::VideoMode m_VideoMode;

	std::list<std::unique_ptr<CelestialBody>> m_CelestialBodies;

	const int WIDTH = 1000;
	const int HEIGHT = 1000;
};

