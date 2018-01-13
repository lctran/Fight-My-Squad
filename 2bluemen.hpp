/*********************************************************************
** Program name: Project 3 - Fantasy Combat Game
** Author: Laura Tran (932373639)
** Date: 05 NOV 2017
** Description:  Create a child character BLUE MEN. Include function 
for special ability MOB.
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class bluemen : public character {
public:
    bluemen(int num) : character() {			  // P = playerNum 1 or 2
	   
	   dieAttackBM = 10;					  // 2d10
	   dieDefenseBM = 6;					  // 3d6
	   armorBM = 3;						  
	   strengthPointsBM = 12;
	   numDefenseDice = 3;					  // SA | mob, start w/ 3 dice

	   this->dieAttack = dieAttackBM;
	   this->dieDefense = dieDefenseBM;
	   this->armor = armorBM;
	   this->strengthPoints = strengthPointsBM;	  // SA | mob us called

	   this->name = "Blue Men";
	   this->playerNum = num;
    }

    virtual void attack(character*);   
    virtual void defense(character*);  
    virtual int specialAbility();	
    virtual void updateLP(int);

    int mob();								  // BLUE MEN SPECIAL ABILITY | determine number of def dice to roll

private:
    //int dieAttackBM = 10;
    //int dieDefenseBM = 6;
    //int armorBM = 3;
    //int strengthPointsBM = 12;

    int dieAttackBM;
    int dieDefenseBM;
    int armorBM;
    int strengthPointsBM;

    int numDefenseDice;						  // SA | 3d6, for mob(), lose 1 die for every 4 damage points

};
#endif