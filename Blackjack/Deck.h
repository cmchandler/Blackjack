/*
Deck.h: header file for Deck class
Christien Chandler
CSCI 487
Special Project
*/

#pragma once
#include <vector>
#include <string>
#include "Card.h"


class Deck
{
private: 
	std::vector<Card> myDeck;

public:
	Deck();
	~Deck();

	void shuffle();
	int size();
	Card deal();
	std::string printDeck();
};

