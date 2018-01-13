/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Create a child character BARBARIAN. Has no special
ability.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class barbarian : public character {
public:
    barbarian(int num) : character() {			 // P = playerNum 1 or 2

	   dieAttackB = 6;						 // 2d6
	   dieDefenseB = 6;						 // 2d6
	   armorB = 0;
	   strengthPointsB = 12;

	   this->dieAttack = dieAttackB;
	   this->dieDefense = dieDefenseB;
	   this->armor = armorB;
	   this->strengthPoints = strengthPointsB;

	   this->name = "Barbarian";
	   this->playerNum = num;
    }

    virtual void attack(character*);  
    virtual void defense(character*);  
    virtual int specialAbility();				 // BARBARIAN HAS NO SPECIAL ABILITY
    virtual void updateLP(int);

private:
    //int dieAttackB = 6;
    //int dieDefenseB = 6;
    //int armorB = 0;
    //int strengthPointsB = 12;

    int dieAttackB;
    int dieDefenseB;
    int armorB;
    int strengthPointsB;
};
#endif