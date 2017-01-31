/*
Deck.cpp: implementation file for Deck class
Christien Chandler
CSCI 487
Special Project
*/

#include <string>
#include <cstdlib>
#include <ctime>
#include "Deck.h"

// initializes the object, fills deck with 52 cards in order
Deck::Deck()
{
	for (int suit = 1; suit < 5; suit++) {
		for (int number = 2; number < 15; number++) {
			myDeck.push_back(Card(number, suit));
		}
	}
}

// default destructor
Deck::~Deck()
{
}

// shuffles the order of the remaining cards in the deck using Fisher-Yates shuffle
void Deck::shuffle()
{
	srand((int)time(0));
	int r;
	for (int i = myDeck.size()-1; i > 0; i--)
	{
		r = (rand() % i);
		std::swap(myDeck[i], myDeck[r]);
	}
}

// returns the current number of cards in the deck
int Deck::size()
{
	return (int) myDeck.size();
}

// returns the top card of the deck, removes from deck
Card Deck::deal()
{
	Card temp;
	temp = myDeck[myDeck.size() - 1];
	myDeck.pop_back();
	return temp;
}

// returns a string containing a list of the remaining cards in the deck 
std::string Deck::printDeck()
{	
	std::string retVal = "";
	for (int j = 0; j < myDeck.size(); j++)
	{
		retVal += myDeck[j].shortName();
		retVal += "\n";
	}
	return retVal;
}