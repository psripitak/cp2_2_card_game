//*****************************************************************************
// By: Pete Sripitak
// implementation file CardClass.cpp for class CardClass
//*****************************************************************************

#include "CardClass.h"
using namespace std;

CardClass::CardClass()
{
	//initialize suit, value, and points for each card
	for (int i=0; i<MAX_CARDS; i++)
	{
		//initialize thirteen cards for each suit
		if (i / 13 == 0)
			cards[i].suit = DIAMOND;
		else if (i / 13 == 1)
			cards[i].suit = CLUB;
		else if (i / 13 ==2)
			cards[i].suit = HEART;
		else
			cards[i].suit = SPADE;

		cards[i].value = (i % 13) + 1;

		//assign points for each card. Heart < 10 is 5 points, Heart >= 10 is 10 points
		//Queen of Spade is 100 points, and Jack of Club is -100 points
		if (cards[i].suit == HEART && cards[i].value < 10)
			cards[i].points = 5;
		else if (cards[i].suit == HEART && cards[i].value >= 10)
			cards[i].points = 10;
		else if (cards[i].suit == SPADE && cards[i].value == 12)
			cards[i].points = 100;
		else if (cards[i].suit == CLUB && cards[i].value == 11)
			cards[i].points = -100;
		else
			cards[i].points = 0;
	}

	remainCards = MAX_CARDS;
}	//end constructor

void CardClass::Print() const
{
	cout << "\nCard Deck\n";
	cout << " SUIT            VALUE            POINTS" << endl;

	//for each card in deck
	for (int i=0; i<MAX_CARDS; i++)
	{
		//print suit accordingly
		switch (cards[i].suit)
		{
			case DIAMOND:
				cout << left << setw(7) << "Diamond";
				break;
			case CLUB:
				cout << left << setw(7) << "Club";
				break;
			case HEART:
				cout << left << setw(7) << "Heart";
				break;
			case SPADE:
				cout << left << setw(7) << "Spade";
				break;
		}

		//print value accordingly
		switch (cards[i].value)
		{
			case 1:
				cout << right << setw(13) << "A";
				break;
			case 11:
				cout << right << setw(13) << "J";
				break;
			case 12:
				cout << right << setw(13) << "Q";
				break;
			case 13:
				cout << right << setw(13) << "K";
				break;
			default:
				cout << right << setw(13) << cards[i].value;
				break;
		}

		cout << right << setw(18) << cards[i].points;
		cout << endl;
	}

	cout << endl;
}	//end Print

void CardClass::ShuffleCard()
{
	CardStruct temp;	//temp variable
	int num, num2;		//store random index

	//pick two random numbers, then swap cards
	for (int i=0; i<MAX_CARDS; i++)
	{
		num = rand() % MAX_CARDS;
		num2 = rand() % MAX_CARDS;

		temp = cards[num];
		cards[num] = cards[num2];
		cards[num2] = temp;
	}
}	//end ShuffleCard

CardStruct CardClass::DealCard()
{
	remainCards--;
	return cards[remainCards];
}	//end DealCard

//end of implementation file
