#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <omp.h>

const int gridWidth = 100;
const int gridHeight = 100;
const int cellWidth = 19;  // 1920 / 100
const int cellHeight = 10; // 1080 / 100

bool grid[gridWidth][gridHeight];
bool nextGrid[gridWidth][gridHeight];

void create(sf::RectangleShape& rect, sf::RenderWindow& window, int x, int y) {
    rect.setPosition(x * cellWidth, y * cellHeight);
    window.draw(rect);
}

void initGrid(std::mt19937& mt, std::uniform_int_distribution<int>& dist) {
    {
        for (int i = 0; i < gridHeight; ++i) {
            for (int j = 0; j < gridWidth; ++j) {
                int random_number = dist(mt);
                grid[i][j] = random_number == 1;
            }
        }
    }
}

void updateGrid() {
    int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

    for (int i = 0; i < gridHeight; ++i) {
        for (int j = 0; j < gridWidth; ++j) {
            int aliveNeighbors = 0;

            for (int k = 0; k < 8; ++k) {
                int newX = i + dx[k];
                int newY = j + dy[k];

                if (newX >= 0 && newX < gridHeight && newY >= 0 && newY < gridWidth) {
                    aliveNeighbors += grid[newX][newY];
                }
            }

            if (grid[i][j]) {
                nextGrid[i][j] = (aliveNeighbors == 2 || aliveNeighbors == 3);
            }
            else {
                nextGrid[i][j] = (aliveNeighbors == 3);
            }
        }
    }

    std::swap(grid, nextGrid);
}



int main()
{    // Initialize the Mersenne Twister PRNG with a seed. Initialized here so that
	 // we get a new set of random numbers every time we run the program.
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);


	initGrid(mt, dist);

    sf::RectangleShape rect(sf::Vector2f(cellWidth, cellHeight));
    rect.setFillColor(sf::Color::White);

    auto window = sf::RenderWindow{ { 1920u, 1080u }, "RaptorsGameOfLife" };
    window.setFramerateLimit(20);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        for (int i = 0; i < gridHeight; ++i) {
            for (int j = 0; j < gridWidth; ++j) {
                if (grid[i][j]) {
                    create(rect, window, j, i);
                }
            }
        }
        window.display();
        updateGrid();
    }

    return 0;

}