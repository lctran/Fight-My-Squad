/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Creates loserBracket hpp file. Defines the functions
that will store and remove character* losers/pointers from a list.
*********************************************************************/

#ifndef LOSERBRACKET_HPP
#define LOSERBRACKET_HPP

#include "character.hpp"

class loserBracket {
protected:
    struct loser {
	   character* loserCharacter;
	   loser* nextLoser;
	   loser* prevLoser;
    };

    loser* head;
    loser* tail;
    int numLosers;

public:
    loserBracket();					// default constructor
    ~loserBracket();					// destructor

    void addLoser(character*);		// P = character ptr
    void removeLoser();

    void printLoser();
    void printLoserBracket();

    int getNumLosers();				// used to deallocate after displaying loser bracket
};

#endif