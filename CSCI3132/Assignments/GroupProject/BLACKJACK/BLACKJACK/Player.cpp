/*
 * Player.cpp
 */
#include "Player.h"

Player::Player() {
	SYSTEM("Player was created by default");
}

Player::~Player() {
	hand.clear();
}

int Player::getChips() {
	return chips;
}

int Player::getBets() {
	return bets;
}

void Player::updateChips(int cost) {
	chips += cost; // update players' chips
}

void Player::setBets(int num) {
	bets = num;
}

bool Player::isLose() {
	return lose;
}

void Player::setFlag() {
	lose = true; // set the flag to true if the player lose before game finish
}

// override virtual function from parent class
void Player::clearHand() {
	hand.clear(); // clear hand cards for each turn
}

// override virtual function from parent class
void Player::Hit() {
	Game game;
	this->hand.push_back(game.getCard());
}

void Player::Stand() {
	//Stand, do nothing.
}

// override virtual function from parent class
int Player::CheckHand() {
	int sum = 0;
	int cardNum = 1;
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

// let player choose between Hit or Stand
char Player::choice() {
	SYSTEM("Non Blackjack, Hit or Stand?");
	SYSTEM("Press H to draw a card, press S to stand.");
	char c = ' ';
	cin >> c;
	return c;
}