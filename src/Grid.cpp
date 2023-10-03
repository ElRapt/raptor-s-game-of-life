#include "Grid.hpp"
#include <random>

Grid::Grid(int width, int height) {
    this->width = width;
    this->height = height;
    grid.resize(height, std::vector<Cell>(width));
}


void Grid::init() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    for (auto& row : grid) {
        for (auto& cell : row) {
            int random_number = dist(mt);
            cell.setState(random_number == 1);
        }
    }
}

void Grid::countAliveNeighbors(int i, int j, int& aliveNeighbors) const {
    int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

    aliveNeighbors = 0;
    for (int k = 0; k < 8; ++k) {
        int newX = i + dx[k];
        int newY = j + dy[k];
        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[i].size()) {
            aliveNeighbors += grid[newX][newY].getState();
        }
    }
}

void Grid::update() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    std::vector<std::vector<Cell>> nextGrid = grid;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            int aliveNeighbors;
            countAliveNeighbors(i, j, aliveNeighbors);

            nextGrid[i][j] = grid[i][j];
            bool currentState = grid[i][j].getState();

            if (currentState) {
                bool stayAlive = aliveNeighbors == 2 || aliveNeighbors == 3;
                double random_chance = dist(mt);
                int age = grid[i][j].getAge();

                if ((age <= 20 && random_chance < 0.001) ||
                    (age > 20 && age <= 40 && random_chance < 0.005) ||
                    (age > 40 && age <= 70 && random_chance < 0.01) ||
                    (age > 70 && random_chance < 0.05)) {
                    stayAlive = false;
                }

                nextGrid[i][j].setState(stayAlive);

                if (stayAlive) {
                    nextGrid[i][j].incrementAge();
                    if (nextGrid[i][j].getAge() > maxAge) {
                        nextGrid[i][j].setState(false);
                    }
                }
            }
            else {
                bool becomeAlive = aliveNeighbors == 3;
                nextGrid[i][j].setState(becomeAlive);
                if (becomeAlive) {
                    nextGrid[i][j].setAge(0);
                }
            }
        }
    }
    grid = std::move(nextGrid);
}

bool Grid::getCellState(int x, int y) const {
    return grid[y][x].getState();
}

int Grid::getCellAge(int x, int y) const {
    return grid[y][x].getAge();
}
