#pragma once


class Cell 
{
public:
	bool isAlive;
	int age;
	Cell();

	void setState(bool state);
	bool getState() const;
	
};