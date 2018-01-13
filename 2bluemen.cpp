/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements BLUE MEN character (3 of 5) header file,
defines the functions.
*********************************************************************/

#include "2bluemen.hpp"

void bluemen::attack(character* opponent) {	  // 2d10, set attack
    totalRoll = 0;
    for (int i = 0; i < 2; i++) {	 // 2 rolls
	   roll = dieRoll(dieAttackBM);
	   totalRoll += roll;
    }
    this->attackVal = totalRoll;
    //cout << "BlueMen Attack:  " << attackVal << endl;
}
void bluemen::defense(character* opponent) {		 // 3d6
    totalRoll = 0;
    cout << "**MOB** NUMBER OF DEFENSE DICE USED =  " << mob() << endl;	 // display MOB SA
    for (int i = 0; i < mob(); i++) {	// roll x number of times
	   roll = dieRoll(dieDefenseBM);	// roll value
	   totalRoll += roll;  
    }
    this->defenseVal = totalRoll;
    //cout << "BlueMen Defense:  " << defenseVal << endl;
}

int bluemen::specialAbility() {
    return 0;
}

void bluemen::updateLP(int damage) {
    this->strengthPoints -= damage;
    //cout << "BlueMen Life Points =  " << strengthPoints << endl;
}

// sets numDefenseDie for number of rolls
int bluemen::mob() {
    if (strengthPoints > 8)
	   numDefenseDice = 3;
    else if (strengthPoints <= 8 && strengthPoints > 4)
	   numDefenseDice = 2;
    else if (strengthPoints <= 4)
	   numDefenseDice = 1;

    return numDefenseDice;
}