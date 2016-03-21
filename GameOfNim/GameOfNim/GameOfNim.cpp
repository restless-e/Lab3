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

using namespace std;

//variables
int totalMarbles, remainMarbles, takeMarbles, maxTakeMarbles, turn = 0;
int pturn = 2;
string player = "Player two";

void gameFlow();
int playerTurn(int pturn);
bool checkVictory(int remainMarbles);
int TakeMarbs(int takeMarbles);

int main() // game setup
{
	cout << "How many marbles do you want to play with?:" << endl;
	cin >> totalMarbles;

	remainMarbles = totalMarbles;
	maxTakeMarbles = (remainMarbles / 2);// +0.5;

	cout << "Excellent, we will play NIM with " << totalMarbles << " marbles!" << endl << endl;// << endl;
	cout << "Player 1, we will begin with you. Please take at least 1 and up to " << maxTakeMarbles << " marbles." << endl;
	cin >> takeMarbles;
	//player has taken marbles - subtract and recount.
	remainMarbles = remainMarbles - takeMarbles;

	// output remaining marbles.
	// next players turn.
	// redo max take of marbles.

	while (checkVictory(remainMarbles) == false)
	{
		//main(); // game setup
		gameFlow();
		playerTurn(pturn);
	}

	cout << "Congratulations " << player << "! You have won!" << endl;
	//sequence();

	system("pause");
	return 0;
}

void gameFlow()
{
	turn = turn++;
	maxTakeMarbles = (remainMarbles / 2) + 0.5;
	cout << remainMarbles << " marbles remain." << endl;
	cout << player << " it is your turn. You may take 1 - " << maxTakeMarbles << " marbles." << endl;
	cin >> takeMarbles;
	//TakeMarbs(cin) >> takeMarbles;
	remainMarbles = remainMarbles - takeMarbles;
}

int playerTurn(int pturn)
{
	switch (pturn)
	{	
	case 1:
		player = "Player two";
		//	pturn = 2;
		return 2;
		break;
	case 2:
		player = "Player one";
		//pturn = 1;
		return 1;
		break;
	default:
		player = "Player one";
		//pturn = 1;
		return 1;
		break;
	}
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

int TakeMarbs(int takeMarbles)
{
	while (true)
	{
		cin >> takeMarbles;
		if (takeMarbles > 1 && takeMarbles <= maxTakeMarbles)
		{
			break;
		}
		else if (takeMarbles < 1 && takeMarbles > maxTakeMarbles)
		{
			cin.clear();
			cin.ignore();
			cout << "Incorrect range. Try again: ";
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Incorrect entry. Try again: ";
		}
	}
	return 0;
}