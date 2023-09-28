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
    rect.setFillColor(sf::Color::White);

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
                    rect.setPosition(j * 19, i * 10);
                    window.draw(rect);
                }
            }
        }
        window.display();
        grid.update();
    }
}
