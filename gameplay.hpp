/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description: Gameplay class is the menu. It sets up the game, 
creates characters per player, validate user input, and display results.
*********************************************************************/

#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "character.hpp"
#include "0vampire.hpp"
#include "1barbarian.hpp"
#include "2bluemen.hpp"
#include "3medusa.hpp"
#include "4harrypotter.hpp"

#include <iostream>
using namespace std;

class gameplay {
public:
    gameplay();								 // default constructor
    ~gameplay();
    void menu();								 // calls funcs to start game, repeat [in main]
    void chooseCharacter();						 // list characters and take user input/choice
    void setupGame();							 // create character and starts combat
    character* createCharacter(int, character*, int);	 // P = enum character (user input), new character ptr, playerNumber 1/2
    void round(character*, character*, int);			 // [recursion] P = 2 x character ptr (att/def), defender strengthPoints
    void calcDamage(character*, character*, int);		 // P = same parameters as above, calculate damage

    void initialMenu(character*, character*);		 // disp playerstatus before attacks, menu req 1-2
    void postMenu(character*, character*);			 // after attacks/defense dice roll, menu req 3-6

    double validateFloat(double, int, int);			 // validate user input, handle floats

    // tournament
    character* getRoundWinner();					 // return winner to fighting() in tournament
    character* getRoundLoser();					 // return loser to fighting() in tournament
    double getP1Choice();
    double getP2Choice();

private:
    enum characters { vampires, barbarians, blueMens, medusas, harryPotters };

    character* p1;	    // character objects created per player
    character* p2;
    character* tempC;   // [recursion] round(), swap players between attacker/defender
    int tempLP;	    // [recursion] round(), swap LP
    int hitCounter;	    // round()

    double p1Choice;    // chooseCharacter()
    double p2Choice; 

    int damage;	    // calcDamage()
    int negDamageTemp;  // postMenu()
    int attackerVal;    // store attacker rolls
    int defenderVal;    // store defender rolls
    int armorVal;	    // store get defender armor

    double play;	    // menu(), userInput for repeat

    // tournament
    character* roundWinner;
    character* roundLoser;


};

#endif
