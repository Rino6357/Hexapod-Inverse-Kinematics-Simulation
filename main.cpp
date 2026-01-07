#include <SFML/Graphics.hpp>
#include <iostream>
#include "Leg.h"
#include "Constants.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML Line");

    sf::Vertex point{{ 600.f, 400.f }};

    sf::Vector2f joint1{ 300.f, 300.f };
    sf::Vector2f joint2{ 400.f, 300.f };
    sf::Vector2f joint3{ 550.f, 300.f };
    sf::Vector2f end{ 700.f, 300.f };
    Leg first{ joint1, joint2, joint3, end };

    sf::Clock clock;
    float speed = 1.5f;

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        first.rotateCoxa(PI * 2, deltaTime);
        first.rotateFemur(PI * 2, deltaTime, 4.5f);
        first.rotateTibia(PI * 2, deltaTime, 3.f);

        window.clear(sf::Color(50, 40, 80));
        first.draw(window);
        window.draw(&point, 1, sf::PrimitiveType::Points);
        window.display();
    }
}
