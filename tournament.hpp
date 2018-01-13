/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Tournament functions designed to run tournament and 
work STL containers.
*********************************************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include <cctype>			  // isdigit for inputValidation

#include "lineup.hpp"
#include "loserBracket.hpp"

#include "gameplay.hpp"
#include "character.hpp"
#include "0vampire.hpp"
#include "1barbarian.hpp"
#include "2bluemen.hpp"
#include "3medusa.hpp"
#include "4harrypotter.hpp"

class tournament {
protected:
    enum characterz { vampires, barbarians, blueMens, medusas, harryPotters };

    lineup team1;
    lineup team2;
    gameplay g1;
    character* winner;
    character* loser;

    int scoreTeam1;		   // +1 for win, +0 lose (tie is determined at end of final score)
    int scoreTeam2;


    double numberOfFighters;		 // tourneySetup(), user input
    int roundCounter;			 // fighting()
    bool tournamentEnd;			 // fighting()
    int cont;					 // tourneySetup(), looper to continue
    int heal;					 // restoreLP
    int multiplierHeal;			 // restoreLP() die roll

    character* newFighter;		 // createTeam()
    loserBracket listOfLosers;

    int uChoice;				 // tourneySetup()
    int tournamentCounter;		 // tourneySetup() in while loop, display in displayFinalResults()
    int counterTemp;
    character* A;				 // able to delete later
    character* B;

public:
    tournament();		   // default constructor
    ~tournament();		   // destructor

    void displayIntro();				    // display rules and introduction, CALLED IN MAIN
    void tourneySetup();				    // tournament menu/setup
    void createTeam(int, int, string);	    // P = T1/2, charType, charName - create char, add to lineup 
    void fighting();
    void displayFinalResults();		    // P = 1 or 2 - display lineup list of Team1/Team2
    
// getters
    int getScoreTeam1();
    int getScoreTeam2();

// input validation
    double validateFloat(double, int, int);
};
#endif
