#include "Game.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

void Game::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "ENGINULI", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Vector2f velocity(0.f, 0.f);
    const float acceleration = 10.f;
    const float friction = 0.80f;

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        float deltaTime = elapsedTime.asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) 
                    {
                        window.close();
                        break;
                    }
                    else if (event.key.code == sf::Keyboard::Left)
                    {
                        velocity.x -= acceleration;
                    }
                    else if (event.key.code == sf::Keyboard::Up)
                    {
                        velocity.y -= acceleration;
                    }
                    else if (event.key.code == sf::Keyboard::Right)
                    {
                        velocity.x += acceleration;
                    }
                    else if (event.key.code == sf::Keyboard::Down)
                    {
                        velocity.y += acceleration;
                    }
                   

            }
        }
            
        velocity *= (1.0f - friction * deltaTime);
        shape.move(velocity * deltaTime);
        window.clear();
        window.draw(shape);
        window.display();
    }
}


