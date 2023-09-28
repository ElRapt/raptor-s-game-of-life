#include "Grid.hpp"

Grid::Grid(int width, int height) {
    grid.resize(height, std::vector<Cell>(width));
}

void Grid::init(std::mt19937& mt, std::uniform_int_distribution<int>& dist) {
    for (auto& row : grid) {
        for (auto& cell : row) {
            int random_number = dist(mt);
            cell.setState(random_number == 1);
        }
    }
}

void Grid::update() {
    std::vector<std::vector<Cell>> nextGrid = grid;
    int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int max_age = 100;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            int aliveNeighbors = 0;
            for (int k = 0; k < 8; ++k) {
                int newX = i + dx[k];
                int newY = j + dy[k];
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[i].size()) {
                    aliveNeighbors += grid[newX][newY].getState();
                }
            }

            nextGrid[i][j] = grid[i][j]; 

            if (grid[i][j].getState()) {
                nextGrid[i][j].setState(aliveNeighbors == 2 || aliveNeighbors == 3);
                if (nextGrid[i][j].getState()) {
                    nextGrid[i][j].incrementAge();
                    if (nextGrid[i][j].getAge() > max_age) {
                        nextGrid[i][j].setState(false);
                    }
                }
            }
            else {
                nextGrid[i][j].setState(aliveNeighbors == 3);
                if (nextGrid[i][j].getState()) {
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