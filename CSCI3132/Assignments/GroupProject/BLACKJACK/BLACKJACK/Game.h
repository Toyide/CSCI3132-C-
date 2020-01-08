/*
 * Game.h
 */
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include "Player.h"
#include "Dealer.h"

using namespace std;

class Game {
private:
	int turnCount = 0;
public:
	Game();
	~Game();
	int getTurn(); // return turn number
	void setTurn(int num); // set turn number
	void Betting(); // let players choose a betting number
	void Distribute(); // initial Hit 2 times
	void Shuffler(); // refresh the deck
	int  getCard(); // get card from the deck
	bool is_deck_empty(); // check if the deck is empty
	void addDealer(); // add a dealer to the game
	void addPlayer(); // add a player to the game
	void start(); // start a game
	void checkWin(); // check winner at the end of each turn
	void turn(); // process each turn
	void finalCheckWin(); // check the final winner when all turns end
};

#endif