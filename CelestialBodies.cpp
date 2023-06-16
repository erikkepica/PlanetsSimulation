#include "CelestialBodies.h"

void CelestialBody::PhysicsUpdate(float deltaTime, std::list<std::unique_ptr<CelestialBody>> &celestialBodies)
{
	SetPos(GetPos() + GetVel() * deltaTime);

	for (auto celestialBody = celestialBodies.begin(); celestialBody != celestialBodies.end();)
	{
		if (celestialBody->get() != this)
		{
			double distance = sqrt(pow(abs(GetPos().x - celestialBody->get()->GetPos().x), 2) + pow(abs(GetPos().y - celestialBody->get()->GetPos().y), 2));

			double force = (G * m_Mass * celestialBody->get()->m_Mass) / pow(distance, 2);
			double acceleration = force / m_Mass;

			sf::Vector2f dir = sf::Vector2f((GetPos().x - celestialBody->get()->GetPos().x) * -1, (GetPos().y - celestialBody->get()->GetPos().y) * -1);

			//Normalize
			if (abs(dir.x) > abs(dir.y))
			{
				dir = sf::Vector2f(dir.x / abs(dir.x), dir.y / abs(dir.x));
			}
			else
			{
				dir = sf::Vector2f(dir.x / abs(dir.y), dir.y / abs(dir.y));
			}

			SetVel(sf::Vector2f(dir.x * acceleration + m_StartingVelocity.x, dir.y * acceleration + m_StartingVelocity.y));


			if (distance < m_Shape.getRadius())
			{
				celestialBody->reset();
				celestialBodies.erase(celestialBody);
				break;
			}
			else
			{
			++celestialBody;
			}
		}
		else ++celestialBody;
	}


	m_Shape.setPosition(GetPos());
}

const sf::CircleShape CelestialBody::GetShape() const
{
	return m_Shape;
}

const sf::Vector2f CelestialBody::GetPos() const
{
	return m_Position;
}

const sf::Vector2f CelestialBody::GetVel() const
{
	return m_Velocity;
}

void CelestialBody::SetPos(sf::Vector2f pos)
{
	m_Position = pos;
}

void CelestialBody::SetVel(sf::Vector2f vel)
{
	m_Velocity = vel;
}

CelestialBody::CelestialBody(float radius, sf::Color color, float mass)
{
	m_Shape.setOrigin(sf::Vector2f(radius, radius));

	m_Mass = mass;

	m_Shape.setRadius(radius);
	m_Shape.setFillColor(color);
}

CelestialBody::CelestialBody(float radius, sf::Color color, float mass, sf::Vector2f pos, sf::Vector2f vel)
{
	m_Shape.setOrigin(sf::Vector2f(radius, radius));

	m_Mass = mass;

	m_Shape.setRadius(radius);
	m_Shape.setFillColor(color);

	SetPos(pos);
	m_Velocity = vel;
	m_StartingVelocity = vel;
}

CelestialBody::CelestialBody(float radius, sf::Color color, float mass, sf::Vector2f pos)
{
	m_Shape.setOrigin(sf::Vector2f(radius, radius));

	m_Mass = mass;

	m_Shape.setRadius(radius);
	m_Shape.setFillColor(color);

	SetPos(pos);
}

CelestialBody::CelestialBody(float radius, sf::Color color, float mass, float velX, float velY)
{
	m_Shape.setOrigin(sf::Vector2f(radius, radius));

	m_Mass = mass;

	m_Shape.setRadius(radius);
	m_Shape.setFillColor(color);

	m_Velocity = sf::Vector2f(velX, velY);
	m_StartingVelocity = m_Velocity;
}

CelestialBody::~CelestialBody()
{
}
