/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements VAMPIRE character (1 of 5) header file,
defines the functions.
*********************************************************************/

#include "0vampire.hpp"

void vampire::attack(character* opponent) {	  
    this->attackVal = dieRoll(dieAttackV);
}

void vampire::defense(character* opponent) {	
    this->defenseVal = dieRoll(dieDefenseV);
    charm();
}

int vampire::specialAbility() {
    return getCharm();
}

void vampire::updateLP(int damage) {
    if (charmed == true) {
	   cout << endl << "**CHARM** Vampire used charm. Damage will not be taken." << endl << endl;
    }
    else if (charmed == false) {
	   this->strengthPoints -= damage;
    }
}
void vampire::charm() {
    charmedNum = rand() % 2;	  // random number 0 or 1
    charmed = charmedNum;	  // 1=true, 0=false
   
}

int vampire::getCharm() {
    return charmed;
}