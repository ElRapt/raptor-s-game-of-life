#include "Cell.hpp"

// Initialize with default or given values
Cell::Cell(bool isAlive, int age) : isAlive(isAlive), age(age) {}

void Cell::setState(bool state) {
    isAlive = state;
}

bool Cell::getState() const {
    return isAlive;
}

void Cell::incrementAge(int incrementValue) {
    age += incrementValue;
}

int Cell::getAge() const {
    return age;
}

void Cell::setAge(int newAge) {
    age = newAge;
}
