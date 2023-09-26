#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <omp.h>

const int gridWidth = 100;
const int gridHeight = 100;
const int cellWidth = 19;  // 1920 / 100
const int cellHeight = 10; // 1080 / 100


void create(sf::RectangleShape& rect, sf::RenderWindow& window, int x, int y) {
    rect.setPosition(x * cellWidth, y * cellHeight);
    window.draw(rect);
}



int main()
{
    const int width = 800;
    const int height = 600;


    // Initialize the Mersenne Twister PRNG with a seed
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);



    sf::RectangleShape rect(sf::Vector2f(cellWidth, cellHeight));
    rect.setFillColor(sf::Color::White);

    auto window = sf::RenderWindow{ { 1920u, 1080u }, "RaptorsGameOfLife" };
    window.setFramerateLimit(144);

    #pragma omp parallel for
    for (int i = 0; i < gridHeight; i++)
    {
        for (int j = 0; j < gridWidth; j++)
        {
            int random_number = dist(mt);
            if (random_number == 1) {
                std::cout << "Added cell at " << j << ", " << i << std::endl;
                create(rect, window, j, i);
            }
        }
    }



    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.display();
    }

    return 0;

}