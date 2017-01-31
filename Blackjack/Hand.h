/*
Hand.h: header file for Hand class
Christien Chandler
CSCI 487
Special Project
*/

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Card.h"

class Hand
{
public:
	bool isBust, isBlackJack, isDealer;

	Hand();
	Hand(Card one, Card two);
	~Hand();
	
	void add(Card toAdd);
	void show();
	int getValue();
	void makeDealer();
	void unDealer();

private:
	std::vector<Card> myHand;
	int value, cardCount;
};

