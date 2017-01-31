/*
Card.h: implementation file for Card class
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
	default:symbol = "F";
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
	if (pip == "10") retVal[1] = "|" + pip + "   |";
	else retVal[1] = "|" + pip + "    |";
	retVal[2] = "|  " + symbol + "  |";
	if (pip == "10") retVal[3] = "|   " + pip + "|";
	else retVal[3] = "|    " + pip + "|";
	retVal[4] = "+-----+";
	return retVal;
}

std::vector<std::string> Card::drawBlank()
{
	std::vector<std::string> blank(5);
	blank[0] = "+-----+";
	blank[1] = "+*****+";
	blank[2] = "+*****+";
	blank[3] = "+*****+";
	blank[4] = "+-----+";
	return blank;
}

// changes the value of ace to the input value
void Card::setAce(int newvalue)
{
	if (number == 14)
	{
		value = newvalue;
	}
}

// returns number of card
int Card::getNumber()
{
	return number;
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

// returns a short version of the card's name and value
std::string Card::shortName() 
{
	std::string retVal;

	switch (number)
	{
	case 11:retVal += "J";
		break;
	case 12:retVal += "Q";
		break;
	case 13:retVal += "K";
		break;
	case 14:retVal += "A";
		break;
	default:std::string result;
		std::ostringstream convert;
		convert << number;
		retVal += convert.str();
		break;
	}

	switch (suit)
	{
	case 1: retVal += "\u2660"; // spade
		break;
	case 2: retVal += "\u2665"; // heart
		break;
	case 3: retVal += "\u2666"; // diamond
		break;
	case 4:	retVal += "\u2663"; // club
		break;
	default:retVal += "";
		break;
	}

	return retVal;
}
