#pragma once
#include "Line.h"

class Leg
{
public:
	Leg(sf::Vector2f joint1, sf::Vector2f joint2, sf::Vector2f joint3, sf::Vector2f end);

	void draw(sf::RenderWindow& window);

	void color(sf::Color color1 = sf::Color::Red, sf::Color color2 = sf::Color::White, sf::Color color3 = sf::Color::Green);

private:
	sf::Vector2f m_joint1{};
	sf::Vector2f m_joint2{};
	sf::Vector2f m_joint3{};
	sf::Vector2f m_end{};

	sf::Color m_color1{};
	sf::Color m_color2{};
	sf::Color m_color3{};

	Line m_coxa{ m_joint1, m_joint2 };
	Line m_femur{ m_joint2, m_joint3 };
	Line m_tibia{ m_joint3, m_end };
};

