/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements BARBARIAN character (2 of 5) header file,
defines the functions.
*********************************************************************/

#include "1barbarian.hpp"

void barbarian::attack(character* opponent) {
    totalRoll = 0;
    for (int i = 0; i < 2; i++) {
	   roll = dieRoll(dieAttackB);
	   totalRoll += roll;
    }
    this->attackVal = totalRoll;
}

void barbarian::defense(character* opponent){
    totalRoll = 0;
    for (int i = 0; i < 2; i++) {
	   roll = dieRoll(dieDefenseB);
	   totalRoll += roll;
    }
    this->defenseVal = totalRoll;
}

int barbarian::specialAbility() {
    // none
    //return NULL;
    return 0;
}

void barbarian::updateLP(int damage) {
    this->strengthPoints -= damage;
}