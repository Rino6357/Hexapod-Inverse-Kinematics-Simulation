#include <SFML/Graphics.hpp>
#include <iostream>
#include "Line.h"

const double PI{ 3.14159265359 };

int main() {
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML Line");

    sf::Vector2f origin{ 300.f, 300.f };
    sf::Vector2f joint{ 500.f, 300.f };
    Line first{ origin, joint };

    sf::Clock clock;
    float speed = 1.5f;

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        first.rotateLine(PI, deltaTime);

        window.clear(sf::Color(50, 40, 80));
        first.draw(window);
        window.display();
    }
}
