#include "Cell.hpp"

Cell::Cell() : isAlive(false) {}

void Cell::setState(bool state) {
	isAlive = state;
}

bool Cell::getState() const {
	return isAlive;
}