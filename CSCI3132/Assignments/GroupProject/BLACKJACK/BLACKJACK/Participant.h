/*
 * Participant.h
 */
#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <iostream>

#define SYSTEM(x) std::cout << "[SYSTEM]: " << x << std::endl;
#define WARNING(x) std::cout << "[WARNING]: " << x << std::endl;

class Participant {
private:

public:
	Participant();
	virtual ~Participant();
	virtual void clearHand() = 0; // pure virtual function
	virtual void Hit() = 0; // pure virtual function 
	virtual int CheckHand() = 0; // pure virtual function
};

#endif