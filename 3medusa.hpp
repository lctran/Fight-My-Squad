/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Create a child character MEDUSA. Includes an
override function for GLARE special ability.
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"

class medusa : public character {
public:
    medusa(int num) : character() {	// P = playerNum 1 or 2

	   dieAttackM = 6;				// 2d6
	   dieDefenseM = 6;				// 1d6
	   armorM = 3;
	   strengthPointsM = 8;
  
	   this->dieAttack = dieAttackM;
	   this->dieDefense = dieDefenseM;
	   this->armor = armorM;
	   this->strengthPoints = strengthPointsM;

	   this->name = "Medusa";
	   this->playerNum = num;
    }

    virtual void attack(character*);	// SA | Glare
    virtual void defense(character*);  
    virtual int specialAbility();	
    virtual void updateLP(int);

    void glare(character*);			// MEDUSA SPECIAL ABILITY - if rolled a 12 medusa wins, if against HP first life HP will come back to life

private:
    //int dieAttackM = 6;
    //int dieDefenseM = 6;
    //int armorM = 3;
    //int strengthPointsM = 8;

    int dieAttackM;
    int dieDefenseM;
    int armorM;
    int strengthPointsM;
    
    bool glared;					// SA | glare(character*)
};

#endif