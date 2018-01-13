/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Creates lineup hpp file. Defines the functions
that will store and remove character* pointers from a list.
*********************************************************************/

#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "character.hpp"

class lineup {
protected:
    struct fighter {
	   fighter* prevFighter;		 // *prev node
	   fighter* nextFighter;		 // *next node

	   character* fighterCharacter;// *character pointer
    };

    fighter *head;				 // left of linked list
    fighter *tail;				 // right

    int numFighters;			 // number of players
    int tempF;

public:
    lineup();					 // default constructor
    ~lineup();					 // destructor

    void addFighter(character*);	 // P = character(fighter) ptr, add fighter to lineup
    character* removeFighter();	 // remove recent fighter and point to the next fighter

   // bool isAlive();				 // check if team has living fighters
    void setNumFighters(int);	 // P = num of fighters
    int getNumFighters();		 // get numFighters
};

#endif