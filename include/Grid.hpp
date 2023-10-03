#pragma once
#include <vector>
#include "Cell.hpp"

class Grid {
private:
    std::vector<std::vector<Cell>> grid;
    const int maxAge = 100;  // Maximum age for cells

public:
    Grid(int width, int height);
    void init();
    void update();
    bool getCellState(int x, int y) const;
    int getCellAge(int x, int y) const;
    void countAliveNeighbors(int x, int y, int& aliveNeighbors) const;
};
