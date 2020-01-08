/*
 * Player.h
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Participant.h"
#include "Game.h"

using namespace std;

// inherient from Participant class
// Player is a Participant
class Player : public Participant {
private:
	int chips = 50; // each player have 50 chips at beginning
	int bets  = 0; // hold players' betting number for each turn
	bool lose = false; // check whether the player loses before the game finish
	vector<int> hand; // cards in hand

public:
	Player();
	~Player();
	int getChips();
	int getBets();
	void updateChips(int cost); // update players' chips
	void setBets(int num);
	bool isLose();
	void setFlag(); // set the flag to true if the player lose before game finish
	void clearHand() override; // override virtual function from parent class
	void Hit() override; // override virtual function from parent class
	void Stand();
	int CheckHand() override; // override virtual function from parent class
	char choice();
};

#endif