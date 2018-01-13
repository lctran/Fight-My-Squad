/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements lineup hpp file. Create team linked list 
to store character* pointers.
*********************************************************************/

#include "lineup.hpp"

// default constructor
lineup::lineup() {
    head = nullptr;
    tail = nullptr;
    numFighters = 0;
}

// destructor
lineup::~lineup() {
    //fighter* deletePtr = head;						// start at the end of list (tail)

    //while (deletePtr != tail) {
	   //fighter* garbage = deletePtr;					// garbage stores pointer to be deleted
	   //deletePtr = deletePtr->nextFighter;					// delete ptr FILO
	   //delete garbage;								// delete the dead ptr stored in garbage
    //}

    //delete deletePtr;								// delete temp ptr	
}

// add a player to lineup via linked list
void lineup::addFighter(character* f) {
    fighter* upcomingFighter = new fighter; 
    upcomingFighter->fighterCharacter = f;

    if (head == nullptr) {
	   upcomingFighter->nextFighter = nullptr;
	   upcomingFighter->prevFighter = nullptr;
	   head = upcomingFighter;
	   tail = head;
    }
    else {
	   while (tail->nextFighter != nullptr) {
		  tail = tail->nextFighter;
	   }
	   tail->nextFighter = upcomingFighter;
	   upcomingFighter->prevFighter = tail;
	   upcomingFighter->nextFighter = nullptr;
	   tail = upcomingFighter;
    }
    numFighters++;
}

// remove recent fighter (node) and point to the next fighter (node)
character* lineup::removeFighter() {
    numFighters--;
    fighter* headFighter = head;
    fighter* nextFighter = headFighter->nextFighter;
    head = nextFighter;

    character* returnFighter = headFighter->fighterCharacter;

    delete headFighter;
    return returnFighter;

   // return setFighter;

    //if (head == nullptr) {  // not fighters in line
	   //// do nothing
	   //cout << "No fighters in lineup." << endl;
	   //character* upcomingFighter = nullptr;
	   //return upcomingFighter;

    //}
    //else if (head->nextFighter == nullptr) {		  // if one fighter in lineup

	   //character* upcomingFighter = head->fighterCharacter;
	   //delete head;						  // delete fighter from lineup (container)
	   //head = nullptr;
	   //tail = nullptr;
	   //
	   //return upcomingFighter;
    //}
    //else {								  // more than 1 fighter in lineup
	   ////

	   //fighter* nextFighter = head;
	   //head = head->nextFighter;
	   //character* upcomingFighterX = head->fighterCharacter;
	   //delete nextFighter;

	   //return upcomingFighterX;
	   ////

	   ////fighter* deleteF = nullptr;
	   ////deleteF = head;
	   ////head = head->nextFighter;				  // set the head to point to next fighter in line
	   ////delete deleteF;

	   ////character* upcomingFighter = head->fighterX;	 // set character to figther
	   ////delete head;							 // delete current fighter
	   ////
	   ////head->prevFighter = nullptr;
	   ////return upcomingFighter;
    //}
}

//bool lineup::isAlive() {
//    if (head == nullptr)
//	   return true;
//
//    return false;
//}

void lineup::setNumFighters(int numF) {
    numFighters = numF;
    tempF = numF;
}

int lineup::getNumFighters() {
    return numFighters;
}
