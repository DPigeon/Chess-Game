/*
 * Player.h
 *
 *  Created on: 2017-12-21
 *      Author: David (GitHub: DPigeon)
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Pawn.h"

using namespace std;

class Player {
private:
	int points;
	string name;
	bool turn; //determines who plays
public:
	Player();
	Player(string);
	int getPoints();
	string getName();
	void setTurn(bool);
	bool isTurn();
	~Player();
};

#endif /* PLAYER_H_ */
