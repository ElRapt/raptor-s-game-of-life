#pragma once


class Cell 
{
private:
	bool isAlive;
	int age;
public:
	Cell();

	void setState(bool state);
	bool getState() const;
	
	void incrementAge();
	int getAge() const;
	void setAge(int newAge);
};