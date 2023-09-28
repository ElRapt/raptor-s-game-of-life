#pragma once
#include <vector>
#include <random>
#include "Cell.hpp"

class Grid {
private:
    std::vector<std::vector<Cell>> grid;
public:
    Grid(int width, int height);
    void init(std::mt19937& mt, std::uniform_int_distribution<int>& dist);
    void update();
    bool getCellState(int x, int y) const;
    int getCellAge(int x, int y) const;
};
