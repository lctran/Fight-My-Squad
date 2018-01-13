/*********************************************************************
** Program name: Project 3 - Fantasy Combat Game
** Author: Laura Tran (932373639)
** Date: 05 NOV 2017
** Description:  Create a child character VAMPIRE. Has special ability
call CHARM.
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class vampire : public character {
public:
    vampire(int num) : character() {	// P = playerNum 1 or 2

	   dieAttackV = 12;				// 1d12
	   dieDefenseV = 6;				// 1d6 - SA | charm
	   armorV = 1;
	   strengthPointsV = 18;

	   this->dieAttack = dieAttackV;
	   this->dieDefense = dieDefenseV;
	   this->armor = armorV;
	   this->strengthPoints = strengthPointsV;

	   this->name = "Vampire";
	   this->playerNum = num;
	   charmed = false;				// SA | bool value if VAMPIRE charms or not
    }

    virtual void attack(character*);   
    virtual void defense(character*);  
    virtual int specialAbility();		// VAMPIRE SPECIAL ABILITY - charm
    virtual void updateLP(int);
    
    void charm();					// SA | charm gives 50% chance of no damage
    int getCharm();					// can be used to pass to another character by calling specialAbility() (eg Medusa)

private:
    int dieAttackV;
    int dieDefenseV;
    int armorV;
    int strengthPointsV;

    int charmedNum;					// SA | bool charm(), store random number 0 or 1
    bool charmed;					// SA | bool charm(), return t/f
};

#endif