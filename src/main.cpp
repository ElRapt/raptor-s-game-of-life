#include <SFML/Graphics.hpp>

void kill(sf::Uint8* grid, int x, int y, int width)
{
	grid[(y * width + x) * 4 + 0] = 0;
	grid[(y * width + x) * 4 + 1] = 0;
	grid[(y * width + x) * 4 + 2] = 0;
	grid[(y * width + x) * 4 + 3] = 255;

}

void create(sf::Uint8* grid, int x, int y, int width)
{
    grid[(y * width + x) * 4 + 0] = 255;
    grid[(y * width + x) * 4 + 1] = 255;
    grid[(y * width + x) * 4 + 2] = 255;
    grid[(y * width + x) * 4 + 3] = 255;

}

int main()
{
    const int width = 1920;
    const int height = 1080;
    sf::Uint8* grid = new sf::Uint8[width * height * 4];




    auto window = sf::RenderWindow{ { 1920u, 1080u }, "RaptorsGameOfLife" };
    window.setFramerateLimit(144);

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
        window.display();
    }
}