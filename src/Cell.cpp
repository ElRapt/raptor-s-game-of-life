#include "Cell.hpp"

Cell::Cell() : isAlive(false), age(0) {}

void Cell::setState(bool state) {
	isAlive = state;
}

bool Cell::getState() const {
	return isAlive;
}

void Cell::incrementAge() {
	age++;
}

int Cell::getAge() const {
	return age;
}

void Cell::setAge(int newAge) {
	age = newAge;
}