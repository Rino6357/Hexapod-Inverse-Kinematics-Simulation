#pragma once
#include "Line.h"

class Leg
{
public:
	Leg(sf::Vector2f joint1, sf::Vector2f joint2, sf::Vector2f joint3, sf::Vector2f end)
		: m_joint1{ joint1 }, m_joint2{ joint2 }, m_joint3{ joint3 }, m_end{ end }
	{

	}

	void draw(sf::RenderWindow& window) const;

private:
	Line m_coxa{ m_joint1, m_joint2 };
	Line m_femur{ m_joint2, m_joint3 };
	Line m_tibia{ m_joint3, m_end };

	sf::Vector2f m_joint1{};
	sf::Vector2f m_joint2{};
	sf::Vector2f m_joint3{};
	sf::Vector2f m_end{};
};

