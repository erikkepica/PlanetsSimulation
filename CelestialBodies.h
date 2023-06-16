#pragma once
#include<list>
#include<iostream>
#include"SFML/Graphics.hpp"
#include"Values.h"

class CelestialBody
{
public:
	void PhysicsUpdate(float deltaTime, std::list<std::unique_ptr<CelestialBody>> &celestialBodies);
	
	const sf::CircleShape GetShape() const;
	const sf::Vector2f GetPos() const;
	const sf::Vector2f GetVel() const;

	void SetPos(sf::Vector2f pos);
	void SetVel(sf::Vector2f vel);

	CelestialBody(float radius, sf::Color color, float mass);
	CelestialBody(float radius, sf::Color color, float mass, sf::Vector2f pos, sf::Vector2f vel);
	CelestialBody(float radius, sf::Color color, float mass, sf::Vector2f pos);
	CelestialBody(float radius, sf::Color color, float mass, float velX, float velY);
	~CelestialBody();

private:
	sf::CircleShape m_Shape;
	
	sf::Vector2f m_StartingVelocity = sf::Vector2f(0.f, 0.f);
	sf::Vector2f m_Velocity = sf::Vector2f(0.f ,0.f);
	sf::Vector2f m_Position = sf::Vector2f(0.f, 0.f);

	bool m_PhysicsUpdate;

	float m_Mass;
};

