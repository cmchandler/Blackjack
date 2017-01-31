#include <cstdio>
#include <iostream>
#include <string>
#include "Deck.h"
#include "Hand.h"
using namespace std;

void drawLogo();
void drawHands(Hand &d, Hand &p);

int main()
{
	int bank = 100;
	int betAmount;
	int choice;

	drawLogo();

	cout << "\nWelcome to Blackjack." << endl;
	while(true)
	{	
		do 
		{
			cout << "\nYour bank balance is $" << bank << endl;
			cout << "\nHow much would you like to bet?: ";
			cin >> betAmount;
		} while (betAmount < 0 || betAmount > bank);


		// set up the deck and draw two cards for player and dealer
		Deck theDeck;
		theDeck.shuffle();
		Hand playerHand(theDeck.deal(), theDeck.deal());
		Hand dealerHand(theDeck.deal(), theDeck.deal());
		dealerHand.makeDealer();

		// look for blackjacks
		if (playerHand.isBlackJack && dealerHand.isBlackJack)
		{	
			drawHands(dealerHand, playerHand);
			cout << "\nYou and the dealer have blackjacks!  It's a draw.";
		}
		else if (playerHand.isBlackJack)
		{
			drawHands(dealerHand, playerHand);
			cout << "\nBlackjack! You win!" << endl;
			bank += betAmount;
		}
		else if (dealerHand.isBlackJack)
		{
			drawHands(dealerHand, playerHand);
			cout << "\nThe dealer has blackjack. You lose." << endl;
			bank -= betAmount;
		}
		
		// play game
		else
		{
			// dealer hits until rules are complete: hits on soft 17
			while (true)
			{
				if (dealerHand.getValue() >= 17) goto dealerdone;
				else 
				{
					dealerHand.add(theDeck.deal());
				}
			}
			
			dealerdone:;

			// see if dealer busted
			if (dealerHand.isBust)
			{	
				dealerHand.unDealer();
				drawHands(dealerHand, playerHand);
				cout << "Dealer busted.  You win." << endl;
				bank += betAmount;
				goto done;
			}


			// player can hit or stand until desired
			choice = 0;

			while (true)
			{
				drawHands(dealerHand, playerHand);
				cout << "\n1) Hit" << endl;
				cout << "2) Stand" << endl;
				cout << "=========" << endl;
				cout << "?: ";
				cin >> choice;
				
				// if 1, adds a card from the deck to player's hand
				switch (choice)
				{
				case 1:	playerHand.add(theDeck.deal());
						drawHands(dealerHand, playerHand);
					break;
				// if 2, evaluates the winner of the hand
				case 2: dealerHand.unDealer();
						drawHands(dealerHand, playerHand);
						if (playerHand.getValue() > dealerHand.getValue())
						{
							cout << "You win!" << endl;
							bank += betAmount;
							goto done;
						}
						else if (playerHand.getValue() == dealerHand.getValue())
						{
							cout << "\nDraw." << endl;
							goto done;
						}
						else
						{
							cout << "Dealer had " << dealerHand.getValue() << ".  You lose." << endl;
							bank -= betAmount;
							goto done;
						}
						break;
				default: break;
				}

				// see if player is over 21
				if (playerHand.isBust) 
				{
					dealerHand.unDealer();
					drawHands(dealerHand, playerHand);
					cout << "You busted. You lose." << endl;
					bank -= betAmount;
					goto done;
				}
			}
		done:;
		}
		if (bank <= 0)
		{
			cout << "You are broke.  Thanks for playing!\n" << endl;
			return 0;
		}
	}
}

// shows the hands of the player and dealer
void drawHands(Hand &d, Hand &p)
{
	cout << "\n\n----------------------------" << endl;
	cout << "\nDealer's hand:" << endl;
	d.show();
	cout << "\nYour hand (" << p.getValue() << "):" << endl;
	p.show();
	cout << "\n----------------------------" << endl;
}

// draws the opening ascii art
void drawLogo()
{
	cout << endl;
	cout << "\033[2J\033[1;1H";
	cout << ",-,---. .          .             .   \n";
	cout << " '|___/ |  ,-. ,-. | , . ,-. ,-. | , \n";
	cout << " ,|   \\ |  ,-| |   |<  | ,-| |   |<  \n";
	cout << "`-^---' `' `-^ `-' ' ` | `-^ `-' ' ` \n";
	cout << "                       |             \n";
	cout << "                      `'             \n";
}