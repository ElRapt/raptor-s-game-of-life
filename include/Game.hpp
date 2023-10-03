#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.hpp"

class Game {
private:
    Grid grid;
    sf::RenderWindow window;
    const int maxAge = 100;  // Maximum age for cells

public:
    Game(int width, int height);
    void run();
};
