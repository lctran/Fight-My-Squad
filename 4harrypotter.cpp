/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements HARRY POTTER character (5 of 5) header file,
defines the functions.
*********************************************************************/

#include "4harrypotter.hpp"

void harrypotter::attack(character* opponent) {	  // 2d6
    totalRoll = 0;
    for (int i = 0; i < 2; i++) {
	   roll = dieRoll(dieAttackHP);
	   totalRoll += roll;
    }

    this->attackVal = totalRoll;
}

void harrypotter::defense(character* opponent) {	  // 2d6
    totalRoll = 0;
    for (int i = 0; i < 2; i++) {
	   roll = dieRoll(dieDefenseHP);
	   totalRoll += roll;
    }

    this->defenseVal = totalRoll;
}

int harrypotter::specialAbility() {
    if (numLives == 2)
	   cout << " --> This is Harry Potter's first life." << endl;
    else if (numLives == 1)
	   cout << " --> This is Harry Potter's second life." << endl;

    return numLives;
}

void harrypotter::updateLP(int damage) {
    this->strengthPoints -= damage;
    hogwarts();					    // check the strengthpoints 
}

void harrypotter::hogwarts() {
    if (strengthPoints <= 0 && numLives == 2) {
	   strengthPoints = 20;
	   numLives--;					    // decrement lives by 1, numLives = 1
	   cout << endl << "**HOGWARTS** Harry Potter came back to life with STRENGTH POINTS = 20" << endl << endl;
    }
    else if (strengthPoints <= 0 && numLives == 1) {
	   cout << " --> Harry Potter can not use HOGWARTS, this is his second life." << endl << endl;
    }
}



