#include "Game.hpp"

Game::Game(int width, int height) : grid(width, height), window(sf::VideoMode(1920, 1080), "Game of Life") {
    grid.init();
    window.setFramerateLimit(15);
}

void Game::run() {
    sf::RectangleShape rect(sf::Vector2f(19, 10));

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // Draw and color cells based on their age
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                if (grid.getCellState(j, i)) {
                    int age = grid.getCellAge(j, i);
                    sf::Uint8 red = static_cast<sf::Uint8>(255 * age / maxAge);
                    rect.setFillColor(sf::Color(red, 255 - red, 255 - red));
                    rect.setPosition(j * 19, i * 10);
                    window.draw(rect);
                }
            }
        }
        window.display();
        grid.update();
    }
}
