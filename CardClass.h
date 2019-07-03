//*****************************************************************************
// By: Pete Sripitak
// header file CardClass.h for class CardClass
//*****************************************************************************

#include "type.h"
using namespace std;

#ifndef CARDCLASS_H
#define CARDCLASS_H

class CardClass
{
public:
	CardClass();
	//description:		default constructor, form a deck of card,
	//					initialize the count of number of cards
	//precondition:		none
	//postcondition:	a deck of card with its suit/value/points exist

	void Print() const;
	//description:		prints out the entire deck of cards in table format
	//precondition:		none
	//postcondition:	the entire deck of cards is printed in table format

	void ShuffleCard();
	//description:		shuffle the cards into random order
	//precondition:		none
	//postcondition:	cards from the deck are in random order

	CardStruct DealCard();
	//description:		deals out one card, decrement remaining by one
	//precondition:		remainCards > -1
	//postcondition:	return one card, remainCards - 1

private:
	int remainCards;				//store number of cards left in deck
	CardStruct cards[MAX_CARDS];	//array for card deck
};	//end class

//end of header file
#endif
