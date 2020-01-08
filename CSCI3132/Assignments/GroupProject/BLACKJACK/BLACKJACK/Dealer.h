/*
 * Dealer.h
 */
#ifndef DEALER_H
#define DEALER_H

#include <vector>
#include "Participant.h"
#include "Game.h"

using namespace std;

// inherient from Participant class
// Dealer is a Participant
class Dealer : public Participant {
private:
	vector<int> hand; // cards in hand

public:	
	Dealer();
	~Dealer();
	void clearHand() override; // override virtual function from parent class
	void Hit() override; // override virtual function from parent class
	int CheckHand() override; // override virtual function from parent class
};

#endif