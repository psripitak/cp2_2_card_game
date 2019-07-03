//*****************************************************************************
//header file type.h for global variables
//*****************************************************************************

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

#ifndef TYPE_H
#define TYPE_H

//constants
const int MAX_CARDS = 52;		//max number of cards
const int MAX_PLAYERS = 4;		//max number of players
const int PLAYER_CARDS = 13;	//number of cards per player

enum CardSuitType{DIAMOND, CLUB, HEART, SPADE};

struct CardStruct
{
	CardSuitType suit;
	int value;
	int points;
};

//end of header file
#endif
