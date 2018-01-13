/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements MEDUSA character (4 of 5) header file,
defines the functions.
*********************************************************************/

#include "3medusa.hpp"

void medusa::attack(character* opponent) {	   // 2d6, SA = glare
    totalRoll = 0;
    for (int i = 0; i < 2; i++) {			   // # rolls
	   roll = dieRoll(dieAttackM);
	   totalRoll += roll;
    }
    //roll = 12;
    if (totalRoll == 12) {
	   glare(opponent);
	  // this->attackVal = totalRoll;
	   //break;						   // exit one level of loop, for/while/doWhile
    }
    this->attackVal = totalRoll;
}

void medusa::defense(character* opponent) {	   // 1d6
    this->defenseVal = dieRoll(dieDefenseM);
}

int medusa::specialAbility() {
    return 0;
    //return NULL;
}

void medusa::updateLP(int damage) {
    this->strengthPoints -= damage;
}
 
void medusa::glare(character* opponent) {
    cout << endl << "**GLARE** USED ON " << opponent->getName() << endl;	 // display GLARE SA

    if (opponent->getName() == "Barbarian" || opponent->getName() == "Blue Men") {
	   opponent->updateLP(opponent->getStrengthPoints());				 // set opponent LP =0
    }
    else if (opponent->getName() == "Vampire") {						 // charm taken into account when attack is calculated
	   if (opponent->specialAbility() == false) {					 // charm returns bool value
		  opponent->setStrengthPoints(0);							 // set opponent strenghtPoint=0
		  cout << " --> Medusa successfully used GLARE. Vampire will die." << endl;
		  cout << endl;
	   }
	   else {
		  cout << " --> Vampire used CHARM. GLARE had no effect. " << endl;
		  cout << endl;
	   }
    }
    else if (opponent->getName() == "Harry Potter") {					 //if getLife = 2, -1 keep HP alive
	   if (opponent->specialAbility() == 2) {
		  cout << " --> Harry Potter used HOWARTS. GLARE killed Harry Potter's first life." << endl;
		  opponent->setStrengthPoints(0);							 // set opponent strenghtPoint=0
	   }
	   else {
		  cout << " --> Medusa succesfully used GLARE on Harry Potter's second life. Harry Potter will die. " << endl;
		  opponent->setStrengthPoints(0);				
	   }
    }

}