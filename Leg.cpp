#include "Leg.h"

Leg::Leg(sf::Vector2f joint1, sf::Vector2f joint2, sf::Vector2f joint3, sf::Vector2f end)
	: m_joint1{ joint1 }, m_joint2{ joint2 }, m_joint3{ joint3 }, m_end{ end }
{
	this->color();
}

void Leg::draw(sf::RenderWindow& window) {
	m_coxa.color(m_color1);
	m_femur.color(m_color2);
	m_tibia.color(m_color3);

	m_coxa.draw(window);
	m_femur.draw(window);
	m_tibia.draw(window);
}

void Leg::color(sf::Color color1, sf::Color color2, sf::Color color3) {
	m_color1 = color1;
	m_color2 = color2;
	m_color3 = color3;
}