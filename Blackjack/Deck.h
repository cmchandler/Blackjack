#pragma once
#include <vector>
#include "Card.h"

class Deck
{
private: 
	std::vector<Card> myDeck;

public:
	Deck();
	~Deck();

	void shuffle();
	Card pop();
};

