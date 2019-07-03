//*****************************************************************************
// By: Pete Sripitak
// Implementation file PlayerClass.cpp for class PlayerClass
//*****************************************************************************

#include "PlayerClass.h"
using namespace std;

PlayerClass::PlayerClass()
{
	//initialize player's cards
	for (int i=0; i<PLAYER_CARDS; i++)
	{
		playerHand[i].suit = DIAMOND;
		playerHand[i].value = 0;
		playerHand[i].points = 0;
	}

	remainHand = 0;
	score = 0;
}	//end constructor

void PlayerClass::AddACard(const CardStruct toAdd)
{
	playerHand[remainHand] = toAdd;
	remainHand++;
	score += toAdd.points;
}	//end AddACard

void PlayerClass::SortCard()
{
	bool sorted = false;			//flag control
	int last = PLAYER_CARDS - 1;	//last player's card
	CardStruct temp;				//temp variable

	//while sorted is not true
	while (!sorted)
	{
		sorted = true;

		//for i is less than last element
		for (int i=0; i<last; i++)
		{
			//if first suit is greater than second suit, swap
			if (playerHand[i].suit > playerHand[i+1].suit)
			{
				temp = playerHand[i];
				playerHand[i] = playerHand[i+1];
				playerHand[i+1] = temp;
				sorted = false;
			}
		}

		last--;
	}
}	//end SortCard

ostream& operator << (ostream& os, const PlayerClass& rhs)
{
	os << " SUIT            VALUE            POINTS\n";

	//for each player's card
	for (int i=0; i<PLAYER_CARDS; i++)
	{
		//print suit accordingly
		switch (rhs.playerHand[i].suit)
		{
			case DIAMOND:
				os << left << setw(7) << "Diamond";
				break;
			case CLUB:
				os << left << setw(7) << "Club";
				break;
			case HEART:
				os << left << setw(7) << "Heart";
				break;
			case SPADE:
				os << left << setw(7) << "Spade";
				break;
		}

		//print value accordingly
		switch (rhs.playerHand[i].value)
		{
			case 1:
				os << right << setw(13) << "A";
				break;
			case 11:
				os << right << setw(13) << "J";
				break;
			case 12:
				os << right << setw(13) << "Q";
				break;
			case 13:
				os << right << setw(13) << "K";
				break;
			default:
				os << right << setw(13) << rhs.playerHand[i].value;
				break;
		}

		os << right << setw(18) << rhs.playerHand[i].points;
		os << endl;
	}

	os << "TOTAL SCORE: " << rhs.score;
	os << endl << endl << endl;

	return os;
}	//end overloaded << operator

//end of implementation file
