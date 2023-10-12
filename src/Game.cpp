#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

const float PI = 3.14159265358979323846;


Game::Game(int width, int height) : grid(width, height), window(sf::VideoMode(1920, 1080), "Game of Life") {
    grid.init();
    window.setFramerateLimit(15);
}


// Function to calculate hexagon vertices
std::vector<sf::Vector2f> calculateHexagonVertices(float centerX, float centerY, float radius) {
    std::vector<sf::Vector2f> vertices;
    for (int i = 0; i < 6; ++i) {
        float angle_deg = 60 * i;
        float angle_rad = PI / 180 * angle_deg;

        float x = centerX + radius * std::cos(angle_rad);
        float y = centerY + radius * std::sin(angle_rad);
        vertices.emplace_back(x, y);
    }
    return vertices;
}

void Game::run() {
    bool isPaused = false;  
    bool needsRedraw = true;  

    float hexRadius = 20.0f;
    float dx = hexRadius * sqrt(3);
    float dy = hexRadius * 1.5;

    // Create a hexagon using CircleShape with 6 points
    sf::CircleShape hexagon(hexRadius, 6);
    hexagon.setOutlineThickness(1);
    hexagon.setOrigin(hexRadius, hexRadius);
    hexagon.setOutlineColor(sf::Color::Black);

    float offsetX = (1920 - dx * grid.width) / 2;
    float offsetY = (1080 - dy * grid.height) / 2;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                isPaused = !isPaused;
                needsRedraw = true;  // Frame needs to be redrawn when pausing or resuming
            }
        }

        if (!isPaused || needsRedraw) {
            window.clear();  

            for (int y = 0; y < grid.height; ++y) {
                for (int x = 0; x < grid.width; ++x) {
                    int age = grid.getCellAge(x, y);
                    sf::Uint8 red = static_cast<sf::Uint8>(255 * age / maxAge);


                    float rowOffset = (y % 2 == 0) ? 0 : (dx / 2);
                    float posX = x * dx + offsetX + rowOffset;
                    float posY = y * dy + offsetY;

                    hexagon.setPosition(posX, posY);

                    if (grid.getCellState(x, y)) {
                        hexagon.setFillColor(sf::Color(red, 255 - red, 255 - red));
                    }
                    else {
                        hexagon.setFillColor(sf::Color::White);
                    }

                    window.draw(hexagon);
                }
            }

            if (!isPaused) {
                grid.update();  
            }

            window.display();  
            needsRedraw = false; 
        }
    }
}






