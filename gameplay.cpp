/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game Tournament Edition
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements GAMEPLAY header file, defines the functions.
*********************************************************************/

#include "gameplay.hpp"

// default constructor
gameplay::gameplay() {
    hitCounter = 1;		   // counter to display attacks in each combat round()
}

// menu requirement
void gameplay::menu() {
    cout << "*************************************" << endl;
    cout << " WELCOME TO THE FANTASY COMBAT GAME! " << endl;
    cout << "*************************************" << endl;
    play = 1;			   // 0 = false, 1 = true

    while (play == 1) {
	   setupGame();	   // user choose character, assign to p1/p2, start combat
	   cout << endl;	   // ask user if they want to repeat game
	   cout << "Would you guys like to play again? 1 = YES, 0 = NO " << endl;
	   cout << "CHOICE:  ";
	   cin >> play;
	   play = validateFloat(play, 0, 1);
    }

    if (play == 0) {
	   cout << "You decided to quit game." << endl;
	  // exit(1);
    }
}

gameplay::~gameplay() {
    cout << "Memory deallocation~" << endl;
    /*delete p1;
    delete p2;*/
    //delete winner;
    //delete tempC;
}
// get user input for which character player wants
void gameplay::chooseCharacter() {
    cout << "CHARACTERS" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Enter the number corresponding to the character you want: " << endl;
    cout << " 0 - Vampire " << endl;
    cout << " 1 - Barbarian " << endl;
    cout << " 2 - Blue Men " << endl;
    cout << " 3 - Medusa " << endl;
    cout << " 4 - Harry Potter " << endl;
    cout << "-----------------------------------------------------------" << endl;
   
    cout << "PLAYER 1:  ";
    cin >> p1Choice;
    p1Choice = validateFloat(p1Choice, 0, 4);
   
    cout << "PLAYER 2:  ";
    cin >> p2Choice;
    p2Choice = validateFloat(p2Choice, 0, 4);
}

// start combat/game
void gameplay::setupGame() {
    chooseCharacter();					   // choose character
    p1 = createCharacter(p1Choice, p1, 1);	   // create character for p1/p2
    p2 = createCharacter(p2Choice, p2, 2);
    round(p1, p2, p2->getStrengthPoints());	   // start combat - set p1 to be attacker, p2 to be defender first
    delete p1;
    delete p2;
}

// create character objects
character* gameplay::createCharacter(int choice, character* player, int playerNum) {
    switch (choice) {
    case vampires:
	   player = new vampire(playerNum);
	   break;
    case barbarians:
	   player = new barbarian(playerNum);
	   break;
    case blueMens:
	   player = new bluemen(playerNum);
	   break;
    case medusas:
	   player = new medusa(playerNum);
	   break;
    case harryPotters:
	   player = new harrypotter(playerNum);
	   break;
    }
    return player;
}

//play to loop until player dies
void gameplay::round(character* attacker, character* defender, int LP) {
    cout << endl << "Hit #" << hitCounter << endl;  // hitCounter starts = 1, display each attack
    hitCounter++;							  

    initialMenu(attacker, defender);			  // display menu requirements 1-2

    defender->defense(attacker);				  // defender rolls and set defense value(s)
    attacker->attack(defender);				  // attacker rolls and set attack value(s)
    calcDamage(attacker, defender, LP);			  // calculate damage

    if (defender->getStrengthPoints() <= 0) {	  // base case - displays which player lost
	   roundWinner = attacker;				  // set winner
	   roundLoser = defender;				  // set loser
	   if (hitCounter % 2 == 0)				   
		  cout << "[Player 2] ";
	   else
		  cout << "[Player 1] ";
	   cout << defender->getName() << " lost!" << endl;
	   hitCounter = 1;						  // reset counter
    }
    else {
	   tempC = attacker;					  // swaps between attacker/defender and set new LP to do recursion
	   attacker = defender;
	   defender = tempC;
	   LP = defender->getStrengthPoints();
	   round(attacker, defender, LP);			  // call own function
    }
}

// calc damage and update lifepoints 
void gameplay::calcDamage(character* a, character* d, int LP) { 
    attackerVal = a->getAttack();				  // get attack points of attacking player
    defenderVal = d->getDefense();				  // get defense points of defender
    armorVal = d->getArmor();					  // get armor of defender 
    damage = attackerVal - defenderVal - armorVal;  // calc of damage to defender
    negDamageTemp = damage;
    if (damage <= 0) {						  // if calculated damage is negative, damage taken should = 0
	   negDamageTemp = damage;
	   damage = 0;
    }

    d->updateLP(damage);						  // update strengthPoint of character using virtualFunc character.hpp

    postMenu(a, d);							  //display menu requirements 3-6
}

// result req part 1
void gameplay::initialMenu(character* attacker, character* defender) {
    //1. attacker type
    cout << "ATTACKER TYPE =  " << attacker->getName();
    cout << " [PLAYER #" << attacker->getPNum() << "]" << endl;
    //2. defender type, armor, strengthpoint
    cout << "DEFENDER TYPE =  " << defender->getName();
    cout << " [PLAYER #" << defender->getPNum() << "]" << endl;
    cout << "DEFENDER ARMOR =  " << defender->getArmor() << endl;
    cout << "DEFENDER STRENGTH POINT =  " << defender->getStrengthPoints() << endl;
}

//result req part 2
void gameplay::postMenu(character* a, character* d) {
    //3. attacker's dice roll
    cout << "ATTACKER DICE ROLL [PLAYER #" << a->getPNum() << "] =  " << a->getAttack() << endl;
    //4. defender's dice roll
    cout << "DEFENDER DICE ROLL [PLAYER #" << d->getPNum() << "] =  " << d->getDefense() << endl;
    //5. actual damage inflicted
    cout << "ACTUAL DAMAGE INFLICTED CALCULATION =  " << negDamageTemp << endl;
    cout << "DAMAGE TAKEN =  " << damage << endl;
    //6. defender's new strength point after subtracting damage
    cout << "DEFENDER'S UPDATED STRENGTH POINT =  " << d->getStrengthPoints() << endl;
}

/*********************************************************************
** Description: Handle Floats - To input validate choices within a range
*********************************************************************/
double gameplay::validateFloat(double choice, int lowerLimit, int upperLimit) {
    bool floatNum = false;

    for (int i = lowerLimit; i <= upperLimit; i++) {			  // check if it is a whole number
	   if (choice == i) {
		  floatNum = true;
		  break;
	   }
    }

    if (floatNum == false) {								 // if not a whole number
	   while (!(choice >= lowerLimit && choice <= upperLimit && floatNum == true) || cin.fail()) {
		  cout << "ERROR! Enter whole digits between " << lowerLimit << " and " << upperLimit << ". What is your choice?" << endl;
		  cout << "NEW INPUT:  ";
		  cin.clear();
		  cin.ignore(100, '\n');
		  cin >> choice;

		  for (int i = lowerLimit; i <= upperLimit; i++) {	// check if it is a whole number re-entered
			 if (choice == i) {
				floatNum = true;
				break;
			 }
		  }
	   }
    }

    return choice;
}

 
// tournament
// return winner to fighting in tournament
character* gameplay::getRoundWinner() {
    return roundWinner;
}
character* gameplay::getRoundLoser() {
    return roundLoser;
}
double gameplay::getP1Choice() {
    return p1Choice;
}
double gameplay::getP2Choice() {
    return p2Choice;
}

