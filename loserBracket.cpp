/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements loserBracket hpp file and defines function
in detail here. 
*********************************************************************/

#include "loserBracket.hpp"

// default constructor
loserBracket::loserBracket() {
    head = nullptr;
    tail = nullptr;
    numLosers = 0;
}

// destructor
loserBracket::~loserBracket() {
    // do nothing, no new operator in this file

    //loser* deleteMe = head;

    //while (deleteMe != nullptr) {
	   //loser* garbage = deleteMe;
	   //deleteMe = deleteMe->nextLoser;
	   //delete garbage;
    //}

    //delete deleteMe;
}

// add loser struct to losers bracket 
void loserBracket::addLoser(character* aLoser) {
    //loser* headLoser = head;
    //loser* newLoser = new loser;
    //newLoser->nextLoser = headLoser;
    //newLoser->loserCharacter = aLoser;
    //head = headLoser;

    loser* upcomingLoser = new loser;
    upcomingLoser->loserCharacter = aLoser;
    //upcomingFighter->nextFighter = nullptr;
    //upcomingFighter->prevFighter = nullptr;

    if (head == nullptr) {
	   upcomingLoser->nextLoser = nullptr;
	   upcomingLoser->prevLoser = nullptr;
	   head = upcomingLoser;
	   tail = head;
    }
    else {
	   while (tail->nextLoser != nullptr) {
		  tail = tail->nextLoser;
	   }
	   tail->nextLoser = upcomingLoser;
	   upcomingLoser->prevLoser = tail;
	   upcomingLoser->nextLoser = nullptr;
	   tail = upcomingLoser;
    }
    numLosers++;
    printLoser();
}

// [deallocate] remove loser struct from losers brack
void loserBracket::removeLoser() {

    numLosers--;
    loser* headLoserR = head;
    loser* nextLoserR = headLoserR->nextLoser;
    head = nextLoserR;;

    character* returnLoser = headLoserR->loserCharacter;
    delete headLoserR;
   // return returnLoser;
}

void loserBracket::printLoser() {
    cout << "LOSER ADDED:  " << tail->loserCharacter->getName() << " " << tail->loserCharacter->getNewName() << endl;

}

void loserBracket::printLoserBracket() {
    cout << "LOSERS' BRACKET [Top to Bottom]" << endl;
    loser* printMe = tail;
    while (printMe != nullptr) {
	   cout << "Team " << printMe->loserCharacter->getTeamNum() << ":  " << printMe->loserCharacter->getName() << " " << printMe->loserCharacter->getNewName() << endl;
	   printMe = printMe->prevLoser;

	   if (printMe == nullptr)
		  cout << "Loser bracket is empty now." << endl;
    }
    delete printMe;


}

int loserBracket::getNumLosers() {
    return numLosers;
}