//*****************************************************************************
// By: Pete Sripitak
// header file PlayerClass.h for class PlayerClass
//*****************************************************************************

#include "type.h"
using namespace std;

#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

class PlayerClass
{
public:
	PlayerClass();
	//description:		default constructor, initializes the data of this class
	//precondition:		none
	//postcondition:	data of this class are 0, and exist

	void AddACard(const CardStruct toAdd);
	//description:		adds one card to the player's hand, sum the points
	//precondition:		remainHand < 13
	//postcondition:	one card is added to player's hand,
	//					remainHand + 1, points are add to the sum

	void SortCard();
	//description:		sorts the cards in player's hand by suit
	//precondition:		none
	//postcondition:	player's cards are sorted by suit

	friend ostream& operator << (ostream& os, const PlayerClass& rhs);
	//description:		overloaded operator prints the cards in 
	//					the player's hand in table format
	//precondition:		none
	//postcondition:	the cards in player's hand are printed in table format

private:
	CardStruct playerHand[PLAYER_CARDS];	//array for players' cards
	int remainHand;							//store number of cards the player has
	int score;								//store player's total score
};	//end class

//end of header file
#endif
