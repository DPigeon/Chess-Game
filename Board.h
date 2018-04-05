/*
 * Board.h
 *
 *  Created on: 2017-12-17
 *      Author: David (GitHub: DPigeon)
 */

#include "Pawn.h"
#include <iostream>

using namespace std;

#ifndef BOARD_H_
#define BOARD_H_

class Board {
private:
	static const int size = 64; //Max size of the board
	char bGame[size][size]; //The board of the game
	string name;
public:
	Board();
	Board(string);
	Board(Board&);
	bool checkMate();
	bool isPlayer1(int, int); //if false, then player 2
	int charToInt(char);
	int getDirectionX(int, int);
	int getDirectionY(int, int);
	bool searchPawn(char, char, int);
	char searchTeam1(char);
	void findPawnMove(char, string, string); //finds the pawn that will be moved in the board andmove it
	//pawn (char), old coordx (char), old coordy (int), new coordx (char), new coordy (int), directX, directY
	bool pawnInDirection(char, char, int, char, int, int, int); //not for knight (horse)
	bool operator==(const Board&) const; // equality assignment ==
	bool operator!=(const Board&) const; // not equal !=
	void Display() const; //displays the board
	int getSize();
	~Board();
};

#endif /* BOARD_H_ */
