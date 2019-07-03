//*****************************************************************************
////Programmer:		Pete Sripitak
//File name:		CardMain.cpp

//Description:		This program will implement the preparation routines used
//					in card game played among four players.

//Input:			none

//Output:			1.	CardStruct players[]:	array of struct CardStruct
//*****************************************************************************

#include "CardClass.h"
#include "PlayerClass.h"
using namespace std;

int main()
{
	//variable declarations
	CardClass cardDeck;					//CardClass object for a deck of card
	PlayerClass players[MAX_PLAYERS];	//PlayerClass object for players' cards
	
	//random seeding
	srand(time(NULL));

	cardDeck.ShuffleCard();

	//for thirteen turns
	for (int j=0; j<PLAYER_CARDS; j++)
	{
		//each player deal one card
		for (int i=0; i<MAX_PLAYERS; i++)
		{
			players[i].AddACard(cardDeck.DealCard());
		}
	}

	cout << endl;

	//sort and print cards for each player
	for (int i=0; i<MAX_PLAYERS; i++)
	{
		players[i].SortCard();
		cout << "PLAYER " << i+1 << endl;
		cout << players[i];
	}

	return 0;
}	//end main

//end of client file
