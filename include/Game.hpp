#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.hpp"

class Game {
private:
    Grid grid;
    sf::RenderWindow window;
public:
    Game(int width, int height);
    void run();
};
