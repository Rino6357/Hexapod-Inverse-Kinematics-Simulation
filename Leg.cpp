#include "Leg.h"

void Leg::draw(sf::RenderWindow& window) const {
	m_coxa.draw(window);
	m_femur.draw(window);
	m_tibia.draw(window);
}

