#include "Deck.h"

Deck::Deck()
{
	myDeck.resize(52);
	for (int suit = 1; suit < 5; suit++) {
		for (int number = 2; number < 14; number++) {
			myDeck.push_back(Card(number, suit));
		}
	}
}


Deck::~Deck()
{
}

void Deck::shuffle()
{

}

Card Deck::pop()
{

}
