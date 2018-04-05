/*
 *  Game.cpp
 *
 *  Created on: 2017-12-21
 *      Author: David (GitHub: DPigeon)
 */


#include "Board.h"
#include "Pawn.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	//Variables
	int i = 0;
	string name, name2, fromCoords, toCoords;
	char start, pawn;

	cout<<"Player 1 enter your name please:"<<endl;
	cin>>name;
	Player P1(name);
	cout<<"Player 2 enter your name please:"<<endl;
	cin>>name2;
	Player P2(name2);
	cout<<"Welcome to DPigeon's chess Game, "<<name<<" and "<<name2<<" ! Press S to start a game."<<endl;
	cin>>start;
	if(start == 's' || start == 'S'){
		Board B1("Chess Game");
		Board Bcheck("");
		Pawn P("Chess Pawns"); //to show the pawns
		B1.Display();
		cout<<"Its "<<P1.getName()<<"'s turn ! Type the pawn's character and its coordinate. Example P B1"<<endl;
		cout<<"Then, type the coordinate that you want to move it to. Example: C1"<<endl;
		cout<<P.pawns.nickname<<" are pawns, "<<P.rook.nickname<<" are towers, "<<P.knight.nickname<<" are Knights, "<<P.bishop.nickname<<" are Bishops, "<<P.queen.nickname<<" are Queens and "<<P.king.nickname<<" are Kings."<<endl;
		cout<<P1.getName()<<" has the capital character pawns and "<<P2.getName()<<" has the lower character pawns at the bottom."<<endl;
		do{
			Bcheck = B1; //putting the board checking as same as original board
			if(i%2 == 0){ //p1 plays first every even numbers
				P1.setTurn(true);
				P2.setTurn(false);
				cout<<"It is "<<P1.getName()<<"'s turn !"<<endl;
			} else {
				P2.setTurn(false);
				P2.setTurn(true);
				cout<<"It is "<<P2.getName()<<"'s turn !"<<endl;
			}
			cin>>pawn>>fromCoords>>toCoords; //reads the pawn, its coords and the moving to coords
			if( ( (pawn == P.pawns.nickname || pawn == P.rook.nickname || pawn == P.bishop.nickname || pawn == P.knight.nickname || pawn == P.queen.nickname || pawn == P.king.nickname) && P1.isTurn() ) || ( (pawn == P.pawns.nickname2 || pawn == P.rook.nickname2 || pawn == P.bishop.nickname2 || pawn == P.knight.nickname2 || pawn == P.queen.nickname2 || pawn == P.king.nickname2) && P2.isTurn() ) ) //checking if they play with the right pawns
				B1.findPawnMove(pawn, fromCoords, toCoords); //changes board
			else
				cout<<"Please play with your right pawns !"<<endl;
			if(B1 != Bcheck) //if the board is not the same as previous one, change turn
				i++;
		}while(!B1.checkMate()); //keep going until check mate
		}

	else {
		cout<<"Terminating the game..."<<endl;
		exit(1);
	}
	return 0;
}
