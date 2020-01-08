/*
 * Dealer.cpp
 */
#include "Dealer.h"

Dealer::Dealer() {
	SYSTEM("Dealer was created by default");
}

Dealer::~Dealer() {
	hand.clear();
}

// override virtual function from parent class
void Dealer::clearHand() {
	hand.clear(); // clear hand cards for each turn
}

// override virtual function from parent class
void Dealer::Hit() {
	Game game;
	this->hand.push_back(game.getCard());
}

// override virtual function from parent class
int Dealer::CheckHand() {
	int sum = 0;
	int cardNum = 1;
	SYSTEM("Dealer Hand:");
	for (auto i : this->hand) {
		if (i == 1 && sum + 11 <= 21)
			i = 11;
		SYSTEM("Card" << cardNum << ": " << i);
		sum += i;
		cardNum++;
	}
	SYSTEM("Total: " << sum);
	return sum;
}