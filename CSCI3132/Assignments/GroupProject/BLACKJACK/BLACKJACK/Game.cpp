/*
 * Game.cpp
 */
#include "Game.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string>

vector<Dealer*>dealerSet;
vector<Player*>playerSet;


Game::Game() {
	// default Game constructor
}

Game::~Game() {
	// default Game destructor
}

/*--------deck part*/
const int Ace = 1;
const int J = 10;
const int Q = 10;
const int K = 10;
vector<int> cards;

int Game::getTurn() {
	return turnCount;
}

void Game::setTurn(int num) {
	turnCount = num;
}

void Game::Betting() {
	int playerNum = 0;
	//bool valid = false;
	for (auto p : playerSet) { // let all players to bet
		playerNum++;
		cout << endl;
		SYSTEM("***********Player" << playerNum << "'s betting***********");
		SYSTEM("Current chips: " << p->getChips());
		if (p->isLose() == true) { // if a player has no chips left and lose, skip this player
			SYSTEM("Player" << playerNum << " has no chips left. Automatically lose the game!");
			continue;
		}
		while(1) {
			SYSTEM("The betting number should be between 1 and 50, and not greater than the players current chips");
			SYSTEM("Press a betting number to continue the game");
			int b;
			cin >> b;
			if (cin.good() && (b>= 1 && b <= 50 && b <= p->getChips())) {
				p->setBets(b);
				p->updateChips(-b);
				break;
			}
			else {
				WARNING("Invalid input, try again.");
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
		}
	}
}

void Game::Distribute() {
	for (auto p : playerSet) {
		if (p->isLose() == false) { // if a player has no chips left and lose, skip this player
			p->Hit();
			p->Hit();
		}
	}
}

void Game::Shuffler() {
	cards = { Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
		      Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
		      Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
		      Ace,2,3,4,5,6,7,8,9,10,J,Q,K }; // update deck at the beginning of each turn
	srand((unsigned)time(0));
	for (int i = 0; i < 52; i++) 
		swap(cards[i], cards[rand() % 52]);
	SYSTEM("***********Deck Shuffled!***********");
}

int Game::getCard() {
	int card = cards.front();
	cards.erase(cards.begin()); // remove card from deck after Hit
	return card;
}

bool Game::is_deck_empty() {
	return cards.empty();
}
/*---------end deck part*/


void Game::addDealer() {
	Dealer* d = new Dealer();
	dealerSet.push_back(d);
}

void Game::addPlayer() {
	Player* d = new Player();
	playerSet.push_back(d);
}

void Game::start() {
	int turnNum = getTurn();
	turnNum++;
	setTurn(turnNum);
	cout << endl;
	SYSTEM("************Turn" << turnNum << " Start!************");
	Shuffler();
	Dealer* d = dealerSet.front();
	d->Hit();
	d->Hit();
	Betting();
	Distribute();
}

void Game::checkWin() {
	SYSTEM("*************Check Win**************");
	Dealer* d = dealerSet.front();
	int dealerHand=d->CheckHand();
	cout << endl;
	
	int playerNum = 0;
	for (auto p : playerSet) {
		string res = "";
		playerNum++;
		if (p->isLose() == true) {
			SYSTEM("Player" << playerNum << " has no chips left. Automatically lose the game!\n");
			continue;
		}
		SYSTEM("Player" << playerNum << "'s Hand");
		int playerHand = p->CheckHand();
		if (playerHand == 21 && dealerHand == 21) { // case both player and dealer are blackjack
			res += "Player";
			res += (char)(playerNum + '0');
			res +=" Blackjack Push!";
			p->updateChips(p->getBets());
		}
		else if (playerHand == 21 && dealerHand != 21) { // case player is blackjack and win
			res += "Player";
			res += (char)(playerNum + '0');
			res += " Wins, Blackjack!";
			p->updateChips(3*p->getBets());
		}
		else if(playerHand != 21 && dealerHand == 21) { // case dealer is blackjack and win
			res += "Dealer Wins, Blackjack!";
		}
		else if (playerHand <21 && playerHand > dealerHand) { // case player wins but not blackjack
			res += "Player";
			res += (char)(playerNum + '0');
			res += " Wins!";
			p->updateChips(2*p->getBets());
		}
		else if (playerHand > 21) { // case player is bust
			res += "Player";
			res += (char)(playerNum + '0');
			res += " Bust, lose!";
		}
		else if (dealerHand > 21) { // case dealer is bust
			res += "Dealer Bust, Player Wins!";
			p->updateChips(2*p->getBets());
		}
		else if (playerHand == dealerHand) { // case player and dealer tie and not blackjack
			res += "Player";
			res += (char)(playerNum + '0');
			res += " Push!";
			p->updateChips(p->getBets());
		}
		else if (playerHand < dealerHand) { // case player loses and dealer is not blackjack
			res += "Player";
			res += (char)(playerNum + '0');
			res += " lose!";
		}
		SYSTEM(res);
		SYSTEM("Left chips: " << p->getChips() << endl); // print left chips
		if (p->getChips() == 0) // disable losing players
			p->setFlag();
	}

	dealerSet[0]->clearHand(); // clear the cards in hand
	for (auto p : playerSet)
		p->clearHand(); // clear the cards in hand

	/*
	 * check if all players lose before the game finish
	 */
	int losePlayerNUm = 0;
	for (auto p : playerSet)
		if (p->isLose() == true)
			losePlayerNUm++;
	if (losePlayerNUm == playerSet.size()) {
		SYSTEM("All players lose before game finish, no winner!\n");
		exit(0);
	}
}

void Game::turn() {
	Dealer* d = dealerSet.front();
	int playerNum = 0;
	for (auto p : playerSet) {
		playerNum++;
		cout << endl;
		SYSTEM("***********Player" << playerNum << "'s move***********");
		if (p->isLose() == true) { // if a player has no chips left and lose, skip this player
			SYSTEM("Player" << playerNum << " has no chips left. Automatically lose the game!");
			continue;
		}
		SYSTEM("Player" << playerNum << "'s Hand");
		int playerHand = p->CheckHand();
		char c = ' ';
		while (c != 'S' && playerHand < 21) {
			c = p->choice();
			if (c == 'H') 
				p->Hit();
			else if (c == 'S') 
				/*Stand, do nothing*/;
			else 
				WARNING("Invalid input, try again.");
			playerHand = p->CheckHand();
		}
		if (playerHand > 21)
			SYSTEM("Bust!");
	}
	cout << endl;
	SYSTEM("*************Turns end!*************");
	while (d->CheckHand() < 17) 
		d->Hit();
	cout << endl;
}

void Game::finalCheckWin() {
	int highest = 0;
	for (auto p : playerSet) // get the highest chips number
		if (p->getChips() > highest)
			highest = p->getChips();
	if (highest == 0) // if all players lose, no winner
		SYSTEM("All players lose, no winner!");
	if (highest > 0) {
		int playerNum = 0;
		for (auto p : playerSet) { // if a player win, print congratulations
			playerNum++;
			if (p->getChips() == highest)
				SYSTEM("Player" << playerNum << " is the final winner, CONGRATULATIONS!");
		}
	}
	cout << endl;
}