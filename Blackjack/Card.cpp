/*
Card.h: header file for Card class
Christien Chandler
CSCI 487
Special Project
*/

#include "Card.h"
#include <sstream>
#include <vector>

// default constructor
Card::Card() : number(-1), suit(-1), value(-1)
{
}

// initializes the object
Card::Card(int number, int suit) : number(number), suit(suit)
{
	if (number <= 10)
	{
		value = number;
	}
	else if (number <= 13)
	{
		value = 10;
	}
	else
		value = 11;
}

// returns a string array containing a representation of the card
std::vector<std::string> Card::draw()
{
	std::vector<std::string> retVal(5);
	std::string symbol;
	std::string pip;

	switch (suit)
	{
	case 1: symbol = "\u2660"; // spade
			break;
	case 2: symbol = "\u2665"; // heart
			break;
	case 3: symbol = "\u2666"; // diamond
			break;
	case 4:	symbol = "\u2663"; // club
			break;
	default:symbol = "";
			break;
	}

	switch (number)
	{
	case 11:pip = "J";
			break;
	case 12:pip = "Q";
			break;
	case 13:pip = "K";
			break;
	case 14:pip = "A";
			break;
	default:std::string result;
			std::ostringstream convert;
			convert << number;
			pip = convert.str();
			break;
	}


	retVal[0] = "+-----+";
	retVal[1] = "|" + pip + "    |";
	retVal[2] = "|  " + symbol + "  |";
	retVal[3] = "|    " + pip + "|";
	retVal[4] = "+-----+";
	return retVal;
}

// changes the value of ace to the input value
void Card::setAce(int newvalue)
{
	if (number == 14)
	{
		value = newvalue;
	}
}

// returns value of card
int Card::getValue()
{
	return value;
}

// returns suit of card
int Card::getSuit()
{
	return suit;
}