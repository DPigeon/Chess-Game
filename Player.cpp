/*
 * Player.cpp
 *
 *  Created on: 2017-12-21
 *      Author: David (GitHub: DPigeon)
 */

#include "Player.h"

using namespace std;

Player::Player() {

}

Player::Player(string n){
	name = n;
	points = 0;
}

int Player::getPoints(){
	return points;
}

string Player::getName(){
	return name;
}

void Player::setTurn(bool t){
	turn = t;
}

bool Player::isTurn(){
	return turn;
}

Player::~Player() {

}
