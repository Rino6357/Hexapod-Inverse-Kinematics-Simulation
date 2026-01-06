#include "Line.h"

Line::Line(sf::Vector2f origin, sf::Vector2f joint) 
    : m_origin{ origin }, m_joint{ joint } 
{
	m_vertexArray.append(sf::Vertex{ m_origin });
	m_vertexArray.append(sf::Vertex{ m_joint });
}

void Line::rotateLine(double angle, float dt, float speed) {
    m_vertexArray[1].position.x = m_vertexArray[0].position.x + this->m_length() * std::cosf(m_theta);
    m_vertexArray[1].position.y = m_vertexArray[0].position.y + -this->m_length() * std::sinf(m_theta);
    if (m_theta <= angle) {
        m_theta += speed * dt;
    }

    return;
}

void Line::draw(sf::RenderWindow& window) const {
	window.draw(m_vertexArray);
}

float Line::m_length() const {
    float horizontalDist{ std::abs(m_origin.x - m_joint.x) };
    float verticalDist{ std::abs(m_origin.y - m_joint.y) };

    float length{ std::sqrt(horizontalDist * horizontalDist + verticalDist * verticalDist) };
    return length;
}
