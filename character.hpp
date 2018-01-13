/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Create CHARACTER abstract class with several children
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cstdlib>					    // srand, rand
#include <time.h>
#include <string>
#include <iostream>
using namespace std;

class character {
public:
    character();					    // default constructor
    ~character();					    // destructor
	   
    virtual void attack(character*) = 0;    // required | P = opponent character, does attack rolls
    virtual void defense(character*) = 0;   // required | P = opponent character, does defense rolls
    virtual int specialAbility() = 0;	    // call character specific func for their SPECIAL ABILITY
    virtual void updateLP(int) = 0;	    // update stengthPoint of each player

    int getAttack();				    // getters
    int getDefense();
    int getArmor();
    int getStrengthPoints();
    string getName();
    int getPNum();

    void setStrengthPoints(int);		    // setters

    int dieRoll(int);				    // P = dieType 6 or 12

    // project 4 tournament added
    void setNewName(string);			    // set name for fighter
    string getNewName();				    // get user input name in lineup
    void recover(int);				    // restore some life points
    void setTeamNum(int);			    // set which team for fighter
    int getTeamNum();				    

protected:
    int attackVal;		   // character characteristics
    int defenseVal;
    int armor;
    int strengthPoints;
    string name;
    int playerNum;

    int dieAttack;		   // roll dies
    int dieDefense;

    int roll;			   // store die roll result
    int totalRoll;		   // if character has more than 1 die roll


    // project 4 tournament added
    string newName;
    int teamNumber;
    int healPercentage;	   // recover()
    int anyTempVal;
};
#endif