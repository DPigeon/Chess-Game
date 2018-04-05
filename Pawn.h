/*
 * Pawn.h
 *
 *  Created on: 2017-12-17
 *      Author: David (GitHub: DPigeon)
 */

#ifndef PAWN_H_
#define PAWN_H_

#include <iostream>

using namespace std;

class Pawn {
private:
	string name;
public:
	Pawn();
	Pawn(string);
	//info for each pawns
	struct Pawns{
		static const char nickname = 'P';
		static const char nickname2 = 'p'; //other player
		static const int points = 1;
		static const int maxTitles = 1;
		static const char replacement = 'Q';
	};
	struct Rook{
		static const char nickname = 'T';
		static const char nickname2 = 't';
		static const int points = 5;
		static const int maxTitles = 7;
		static const char replacement = 'K';
	};
	struct Knight{
		static const char nickname = 'N';
		static const char nickname2 = 'n';
		static const int points = 3;
		static const int maxTitles = 3;
	};
	struct Bishop{
		static const char nickname = 'O';
		static const char nickname2 = 'o';
		static const int points = 3;
		static const int maxTitles = 7;
	};
	struct Queen{
		static const char nickname = 'Q';
		static const char nickname2 = 'q';
		static const int points = 6;
		static const int maxTitles = 7;
	};
	struct King{
			//if points, game over
		static const char nickname = 'K';
		static const char nickname2 = 'k';
		static const int maxTitles = 1;
		static const char replacement = 'T';
	};
	//initializing an instance for each struct
	 Pawns pawns;
	 Rook rook;
	 Knight knight;
	 Bishop bishop;
	 Queen queen;
	 King king;
	~Pawn();
};

#endif /* PAWN_H_ */
