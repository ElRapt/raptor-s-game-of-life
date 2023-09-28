#include "Game.hpp"

Game::Game(int width, int height) : grid(width, height), window(sf::VideoMode(1920, 1080), "Game of Life") {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    grid.init(mt, dist);

    window.setFramerateLimit(15);
}

void Game::run() {
    sf::RectangleShape rect(sf::Vector2f(19, 10));
    int max_age = 100;  

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                if (grid.getCellState(j, i)) {
                    int age = grid.getCellAge(j, i); 

                    // Calculate the color based on age. Here it transitions from white to red.
                    sf::Uint8 red = static_cast<sf::Uint8>(255 * age / max_age);
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

