#pragma once
#include <SFML/Graphics.hpp>

class Line
{
public:
	Line(sf::Vector2f origin, sf::Vector2f joint);

	void rotateLine(double angle, float dt, float speed = 1.5f);

	void draw(sf::RenderWindow& window) const;

	void color(sf::Color color);

	void moveLine(sf::Vector2f delta);

	sf::VertexArray getVertexArray() const;

private:
	float m_length() const;

	sf::VertexArray m_vertexArray{ sf::PrimitiveType::Lines };
	sf::Vector2f m_origin{};
	sf::Vector2f m_joint{};
	double m_theta{ 0.f };
};

