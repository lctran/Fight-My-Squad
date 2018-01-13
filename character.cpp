/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements CHARACTER header file, defines the functions.
*********************************************************************/

#include "character.hpp"

character::character() {
    srand(static_cast<unsigned>(time(NULL)));	   // set seed for random number generator
}

character::~character() {}

// getters
int character::getAttack() {
    return attackVal;
}

int character::getDefense() {
    return defenseVal;
}

int character::getArmor() {
    return armor;
}

int character::getStrengthPoints() {
    return strengthPoints;
}

string character::getName() {
    return name;
}

int character::getPNum() {
    return playerNum;
}

//setters
void character::setStrengthPoints(int LP) {
    strengthPoints = LP;
}

//roll die
int character::dieRoll(int dieType) {
    roll = rand() % dieType + 1;	 // range 1 - dieType
    return roll;
}


// PROJECT 4 TOURNAMENT
void character::setNewName(string name) {
    cout << "FIGHTER NAME:  ";
    cin >> newName;
}

string character::getNewName() {
    return newName;
}

void character::recover(int currentStrengthPoints) {
    cout << endl;
    anyTempVal = currentStrengthPoints;
    healPercentage = rand() % 3 + 1;		   // range 1-3
    cout << "HEAL MULTIPLIER =  " << healPercentage << "x" << endl;
    strengthPoints *= healPercentage;			  // just add 10 LPs
    cout << "PREVIOUS STRENGTH POINTS =  " << anyTempVal << endl;
    cout << "UPDATED STRENGTH POINTS =   " << strengthPoints << endl;
}

void character::setTeamNum(int setTeam) {
    teamNumber = setTeam;
}

int character::getTeamNum() {
    return teamNumber;
}