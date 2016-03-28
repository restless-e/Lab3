// GameOfNim.cpp : Defines the entry point for the console application.
//4.24
// The game of Nim
// This is a well - known game with a number of variants.The
// following variant has an interesting winning strategy.Two players alternately take
// marbles from a pile. In each move, a player chooses how many marbles to take. The
// player must take at least one but at most half of the marbles. Then the other player
// takes a turn. The player who takes the last marble loses.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//variables
int totalMarbles, remainMarbles, takeMarbles, maxTakeMarbles, turn = 0;
short pturn = 2;
string player = "Player 2";


//functions
void gameFlow();
int playerTurn();
bool checkVictory(int remainMarbles);

//int TakeMarbs(int takeMarbles);
void dumbBot()
{
	takeMarbles = rand() % maxTakeMarbles + 1;
	cout << "CompPlayer has taken " << takeMarbles << " marbles." << endl;
}
void pickUpMarbles()
{
	cin >> takeMarbles;
	if (!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, please try again: " << endl;
		pickUpMarbles();
	}
	else if (takeMarbles > remainMarbles)
	{
		cout << "Taking too many marbles, please take less." << endl;
		pickUpMarbles();
	}
}

int main() // game setup
{
	srand(time(NULL));

	cout << "How many marbles do you want to play with?:" << endl;
	cin >> totalMarbles;

	remainMarbles = totalMarbles;
	maxTakeMarbles = (remainMarbles / 2);// +0.5;

	cout << "Excellent, we will play NIM with " << totalMarbles << " marbles!" << endl;
	cout << "Player 1, we will begin with you. Please take at least 1 and up to " << maxTakeMarbles << " marbles." << endl;
	cin >> takeMarbles;
	//player has taken marbles - subtract and recount.
	remainMarbles = remainMarbles - takeMarbles;

	// output remaining marbles.
	// next players turn.
	// redo max take of marbles.

	while (checkVictory(remainMarbles) == false)
	{
		playerTurn();//function was below gameflow before, testing.
		gameFlow();
		
	}

	cout << "Congratulations " << player << "! You have won!" << endl;

	system("pause");
	return 0;
}

void gameFlow()
{
	turn = turn++;
	maxTakeMarbles = (remainMarbles / 2) + 0.5;
	cout << remainMarbles << " marbles remain." << endl;
	cout << player << " it is your turn. You may take 1 - " << maxTakeMarbles << " marbles." << endl;
	if (pturn == 2)
	{
		dumbBot();
	}
	else if (pturn == 1)
	{
		cin >> takeMarbles;
	}
	//TakeMarbs(cin) >> takeMarbles;
	if ((remainMarbles - takeMarbles) > 1)
		remainMarbles = remainMarbles - takeMarbles;
	else if ((remainMarbles - takeMarbles) == 0)
	{
		cout << "you have lost" << endl;
		//checkVictory = 1;
	}
	else if ((remainMarbles - takeMarbles) < 0)
	{
		cout << "Taking too many marbles, try taking less." << endl;
		cin >> takeMarbles;
	}

}

int playerTurn()
{
	//pturn = (pturn ? 1 : 2);

	switch (pturn)
	{	
	case 1:
		player = "Player One";
		pturn = 2;
		break;
	case 2:
		player = "Player Two";
		pturn = 1;
		break;
	default:
		player = "Player unknown";
		break;
	}
	return pturn;
}

bool checkVictory(int remainMarbles)
{
	if (remainMarbles == 1 || remainMarbles == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//
//int TakeMarbs(int takeMarbles)
//{
//	while (true)
//	{
//		cin >> takeMarbles;
//		if (takeMarbles > 1 && takeMarbles <= maxTakeMarbles)
//		{
//			break;
//		}
//		else if (takeMarbles < 1 && takeMarbles > maxTakeMarbles)
//		{
//			cin.clear();
//			cin.ignore();
//			cout << "Incorrect range. Try again: ";
//		}
//		else if (cin.fail())
//		{
//			cin.clear();
//			cin.ignore();
//			cout << "Incorrect entry. Try again: ";
//		}
//	}
//	return 0;
//}