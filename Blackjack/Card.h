/*
Card.h: header file for Card class
Christien Chandler
CSCI 487 
Special Project
*/

#pragma once
#include <string>
#include <vector>

class Card
{
private:
	int number, value, suit;

public:
	Card();
	Card(int number, int suit);

	std::vector<std::string> draw();
	std::vector<std::string> drawBlank();
	void setAce(int newvalue);

	int getNumber();
	int getValue();
	int getSuit();

	std::string shortName();
};

