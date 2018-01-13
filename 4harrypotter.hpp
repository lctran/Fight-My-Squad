/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Create a child character HARRY POTTER. Includes an 
override function for HOGWARTS special ability.
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"

class harrypotter : public character {
public:
    harrypotter(int num) : character() {    // P = playerNum 1 or 2

	   dieAttackHP = 6;				    // 2d6
	   dieDefenseHP = 6;			    // 2d6
	   armorHP = 0;
	   strengthPointsHP = 10;		    // SA | starting is 10, SA - HOGWARTS = 20

	   this->dieAttack = dieAttackHP;	    // sets variables in character.hpp
	   this->dieDefense = dieDefenseHP;
	   this->armor = armorHP;
	   this->strengthPoints = strengthPointsHP;
	   
	   this->name = "Harry Potter";
	   this->playerNum = num;
	   numLives = 2;				    // SA | starts off with 2 lives
    }

    virtual void attack(character*);   
    virtual void defense(character*);  
    virtual int specialAbility();	 
    virtual void updateLP(int);

    void hogwarts();				    // HARRY POTTER SPECIAL ABILITY - gets 2 lives, after first die get 20hp instead of 10hp
    
private:
    //int dieAttackHP = 6;	 
    //int dieDefenseHP = 6;	 
    //int armorHP = 0;
    //int strengthPointsHP = 10;  

    int dieAttackHP;	  
    int dieDefenseHP;	  
    int armorHP;
    int strengthPointsHP;  // starting is 10, SA - HOGWARTS = 20
    
    int numLives;		  // SA | hogwarts
};

#endif