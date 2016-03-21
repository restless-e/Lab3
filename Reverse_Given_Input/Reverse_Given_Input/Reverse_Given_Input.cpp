// Reverse_Given_Input.cpp : Defines the entry point for the console application.
// p4.12
// Write a program that reads a word and prints the word in reverse.For example, if the
// user provides the input
// "Harry", the program prints "yrraH"

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;

	cout << "Please type a string to be reversed:" << endl;
	cin >> input;


	// set int variable "i" as the length of the string
	// while i (length) is more than 0
	// subtract 1 from i
	for (int i = input.length(); i > 0; i--)
	{
		// since i is the length, it will be the highest coordinate in the string
		// we print out input[n] and then subtract 1 to go from the end to the beginneing
		// ie length = 3rd letter then 2nd then 1st such as CAT input will be TAC output.
		cout << input[i-1] << " ";
	}


	system("pause");

    return 0;
}

