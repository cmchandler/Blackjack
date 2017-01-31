/*
Card.h: header file for Hand class
Christien Chandler
CSCI 487
Special Project
*/


#include "Hand.h"


Hand::Hand()
{
	value = 0;
	isBust = false;
	isBlackJack = false;
}

Hand::Hand(Card one, Card two)
{
	value = 0;
	add(one);
	add(two);
	isBlackJack = false;
	isBust = false;
	isDealer = false;

	cardCount = 2;
	if ((one.getNumber() == 14 && two.getValue() == 10) || (two.getNumber() == 14 && one.getValue() == 10))
	{
		isBlackJack = true;
	}
}

Hand::~Hand()
{
}

void Hand::add(Card toAdd)
{
	myHand.push_back(toAdd);
	if (toAdd.getNumber() == 14)
	{
		if (toAdd.getValue() + value > 21) {
			toAdd.setAce(1);
		}
	}
	if (toAdd.getValue() + value > 21)
	{
		isBust = true;
	}
	value += toAdd.getValue();
	cardCount++;
}

void Hand::show()
{



	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < myHand.size(); j++)
		{		
			if (isDealer && j == 0)
			{
				std::cout << myHand[j].drawBlank()[i] << " ";
			}
			else
			{
				std::cout << myHand[j].draw()[i] << " ";
			}
		}
		std::cout << std::endl;
	}
}

// returns the current value of the hand
int Hand::getValue() 
{
	return value;
}

void Hand::makeDealer()
{
	isDealer = true;
}
void Hand::unDealer()
{
	isDealer = false;
}



