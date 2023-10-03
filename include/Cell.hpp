#pragma once

class Cell
{
private:
    bool isAlive;
    int age;
public:
    Cell(bool isAlive = false, int age = 0);

    void setState(bool state);
    bool getState() const;

    void incrementAge(int incrementValue = 1);
    int getAge() const;
    void setAge(int newAge);
};
