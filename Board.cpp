/*
 * Board.cpp
 *
 *  Created on: 2017-12-17
 *      Author: David (GitHub: DPigeon)
 */

#include "Board.h"
#include "Pawn.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

//Global Variables
Pawn Pa;
const int rows[] = {1, 2, 3, 4, 5, 6, 7, 8};
const char cols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
const char p1[] = {Pa.bishop.nickname, Pa.king.nickname, Pa.knight.nickname, Pa.pawns.nickname, Pa.queen.nickname, Pa.rook.nickname};
const char p2[] = {Pa.bishop.nickname2, Pa.king.nickname2, Pa.knight.nickname2, Pa.pawns.nickname2, Pa.queen.nickname2, Pa.rook.nickname2};

Board::Board() {
}

Board::Board(string n){

	name = n;
	//Initialize each spot on the board to something
	for(int i = 0; i < getSize(); i++){
		for(int j = 0; j < getSize(); j++){
			bGame[i][j] = '-';
		}
	}
	//Puts the actual real pawns into the board
	//Adding Towers
	bGame[0][0] = Pa.rook.nickname;
	bGame[0][7] = Pa.rook.nickname;
	bGame[7][0] = Pa.rook.nickname2;
	bGame[7][7] = Pa.rook.nickname2;
	//Adding Knights
	bGame[0][1] = Pa.knight.nickname;
	bGame[0][6] = Pa.knight.nickname;
	bGame[7][1] = Pa.knight.nickname2;
	bGame[7][6] = Pa.knight.nickname2;
	//Adding Bishops (Fous)
	bGame[0][2] = Pa.bishop.nickname;
	bGame[0][5] = Pa.bishop.nickname;
	bGame[7][2] = Pa.bishop.nickname2;
	bGame[7][5] = Pa.bishop.nickname2;
	//Adding Queens
	bGame[0][3] = Pa.queen.nickname;
	bGame[7][3] = Pa.queen.nickname2;
	//Adding Kings
	bGame[0][4] = Pa.king.nickname;
	bGame[7][4] = Pa.king.nickname2;
	//Adding Pawns
	for(int i = 0; i < 8; i++){
		bGame[1][i] = Pa.pawns.nickname;
		bGame[6][i] = Pa.pawns.nickname2;
	}
}
Board::Board(Board& B){
	this->name = B.name;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			bGame[i][j] = B.bGame[i][j];
	}
}

bool Board::checkMate(){
	return false; //for now, let it be false
}

bool Board::isPlayer1(int x, int y){ //looks if player1 is moving the right pawns
	for(int i = 0; i < getSize(); i++){
		if(bGame[charToInt(x)][y-1] == Pa.rook.nickname || bGame[charToInt(x)][y] == Pa.knight.nickname || bGame[charToInt(x)][y] == Pa.bishop.nickname || bGame[charToInt(x)][y] == Pa.queen.nickname || bGame[charToInt(x)][y] == Pa.king.nickname || bGame[charToInt(x)][y] == Pa.pawns.nickname){
			return true;
		}
	}
	return false;
}

int Board::charToInt(char c){
	//convert column chars to integers
	int index;
	for(int i = 0; i < 8; i++){
		if(cols[i] == c)
			index = i;
	}
	return index;
}

//if direction X is negative, that means pawn is going down in x
int Board::getDirectionX(int b, int a){
	return b-a;
}

//if direction Y is negative, that means pawn is going left in y
int Board::getDirectionY(int b, int a){
	return b-a;
}

bool Board::searchPawn(char p, char c, int n){
	//search for the pawn nickname
	for(int i = 0; i < getSize(); i++){
		for(int j = 0; j < getSize(); j++)
			if(bGame[charToInt(c)][n-1] != p){
				return false;
			}
	}
	return true;
}

/*char Board::searchTeam1(char p){ //if false, then its in team 2 (not capital letters)
	for(int i = 0; i < 6; i++){ //search through all team 1's capital pawn letters
		if(p1[i] != p)

	}

}*/

void Board::findPawnMove(char p, string from, string to){ //ex: P c1 ---> find P, move it to [2][0]
	//we first extract the 'from' coordinate
	stringstream ssF; //the from one
	ssF<<from;
	char c;
	int n;
	ssF>>c;
	ssF>>n;
	//second, we extract the 'to' coordinate
	stringstream ssT; //the to one
	ssT<<to;
	char c2;
	int nn;
	ssT>>c2;
	ssT>>nn;
	int index = charToInt(c);
	int newIndex = charToInt(c2);
	int x = getDirectionX(index, newIndex); // letters (cols)
	int y = getDirectionY(nn-1, n-1); // numbers (rows)
	if(searchPawn(p, c, n)){ //if we find the good pawn
		if(!pawnInDirection(p, c, n, c2, nn, x, y)){
			bGame[index][n-1] = '-'; //the old spot gets covered by a dash
			bGame[newIndex][nn-1] = p; //we move it
			Display(); //updates the board
		} else {
			cout<<"You cannot play this pawn, try again."<<endl;
		}
	} else {
		cout<<"Please type in the right coordinates with pawn character and try again."<<endl;
	}
}

//still have to do the clipping part where we look for right team
//add the max amount of titles each pawn can do
bool Board::pawnInDirection(char p, char c, int n, char cNew, int nNew, int x, int y){ //gets direction & looks
			//for towers, pawns, queen, king
	if(p == Pa.rook.nickname || p == Pa.rook.nickname2 || p == Pa.queen.nickname || p == Pa.queen.nickname2 || p == Pa.king.nickname || p == Pa.king.nickname2 || p == Pa.pawns.nickname || p == Pa.pawns.nickname2){ //towers, for same team
		if(x > 0 && y == 0){ //goes up x
			for(int i = charToInt(c)-1; i >= charToInt(cNew); i--){
				if(bGame[i][n-1] != '-') // || searchTeam1(bGame[i][n-1])){ //checks if has a pawn in all direction's titles
					return true;
			}
		}
		if(x < 0 && y == 0){ //goes down x
			for(int i = charToInt(c)+1; i <= charToInt(cNew); i++){
				if(bGame[i][n-1] != '-') // || searchTeam1(bGame[i][n-1])){ //checks if has a pawn in all direction's titles
					return true;
			}
		}
		if(x == 0 && y > 0){ //goes right y
			for(int i = n; i < nNew; i++){
				if(bGame[charToInt(c)][i] != '-') // || searchTeam1(bGame[i][n-1])){ //checks if has a pawn in all direction's titles
					return true;
			}
		}
		if(x == 0 && y < 0){ //goes left y
			for(int i = n-2; i >= nNew-1; i--){
				if(bGame[charToInt(c)][i] != '-') // || searchTeam1(bGame[i][n-1])){ //checks if has a pawn in all direction's titles
					return true;
			}
		}
	}
			//for queens, bishops, kings (1)
	if(p == Pa.queen.nickname || p == Pa.queen.nickname2 || p == Pa.bishop.nickname || p == Pa.bishop.nickname2 || p == Pa.king.nickname || p == Pa.king.nickname2){
		if(x > 0 && y > 0){ //goes diagonally NE
			for(int i = charToInt(c)-1; i >= charToInt(cNew); i--){
				for(int j = n; j < nNew; j++){
					if(bGame[i][j] != '-')
						//H4 - G5 -> F6 -> E7 -> D8
						return true;
				}
			}
		}
		if(x < 0 && y < 0){ //goes diagonally SW

		}
		if(x > 0 && y < 0){ //goes diagonally SE

		}
		if(x < 0 && y > 0){ //goes diagonally NW

		}
	}
	return false;
}

bool Board::operator ==(const Board& rightS) const{
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(bGame[i][j] != rightS.bGame[i][j]) //looks if they are not the same
				return false;
		}
	}
	return true;
}

bool Board::operator!=(const Board& rightS) const{
	return !(*this == rightS); // invokes == operator
}

void Board::Display() const{ //displays the entire board
	//Has to display the numbers on row and alphabet on columns
	cout<<"  ";
	for(int i = 0; i < 8; i++)
		cout<<setw(3)<<rows[i];
	cout<<endl;
	cout<<endl;
	int line = 0;
	for(int i = 0; i < 8; i++){
		cout<<cols[i]<<" ";
		for(int j = 0; j < 8; j++)
			cout<<setw(3)<<bGame[i][j];
		cout<<endl;
		line++;
		if(line == 1){
			cout<<endl;
			line = 0;
		}
	}

}

int Board::getSize(){
	return size;
}

Board::~Board() {

}
