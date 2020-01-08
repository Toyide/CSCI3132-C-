/*
 * main.cpp
 */
#include "Game.h"

int main(void) {
	Game game;
	//Add a Dealer
	game.addDealer();
	//Add players depend on input number
	while (1) {
		SYSTEM("Choose number of player to participate in game");
		SYSTEM("Press a number betwenn 2 and 5");
		char n = ' ';
		cin >> n;
		if (isdigit(n)) {
			if ((int)(n - '0') >= 2 && (int)(n - '0') <= 5){
				for (int i = 0; i < (int)(n - '0'); i++)
					game.addPlayer();
				break;
			}
		}
		else {
			WARNING("Invalid input, try again.");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
	}
	
	//Start game
	int turns = 5;
	for (int i = 0; i < turns; i++) {
		game.start();
		game.turn();
		game.checkWin();
	}
	game.finalCheckWin();
	
	//system("pause");
    return 0;
}
