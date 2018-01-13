/*********************************************************************
** Program name: Project 4 - Fantasy Combat Game TOURNAMENT EDITION
** Author: Laura Tran (932373639)
** Date: 19 NOV 2017
** Description:  Implements tournament hpp file. Defines the functions
that will run the game and called directing in main()
*********************************************************************/

#include "tournament.hpp"


// default constructor
tournament::tournament() {
    tournamentCounter = 0;
    cont = 1;			   // 0 = false, 1 = true
    uChoice = 0;
}

// destructor
tournament::~tournament() {
    delete newFighter;
}

// display any intro stuff and rules
void tournament::displayIntro() {
    cout << "****************************************************" << endl;
    cout << " Welcome to Fantasy Combat Game Tournament Edition! " << endl;
    cout << "****************************************************" << endl;
    cout << "Rules/Instructions: " << endl;
    cout << "--------------------" << endl;
    cout << " --> Form 2 teams up to 4 fighters each" << endl;
    cout << " --> Choose x number of fighters from a list of characters and fight" << endl;
    cout << " --> During combat round, winner gain 1x, 2x, or 3x, their current strength points" << endl;
    cout << " --> Winner/Tie determined when all fighters of a team die" << endl;
    cout << " --> After each tournament, teams fighters reset (mean doesn't carry over)" << endl;
    cout << "--------------------" << endl;
    cout << endl;
}

// tournament menu/setup, runs the tournament
void tournament::tourneySetup() {
    displayIntro();				 // display intro and rules

    while (cont == 1) {
	   tournamentCounter++;
	   roundCounter = 0;
	   scoreTeam1 = 0;
	   scoreTeam2 = 0;
	   numberOfFighters = 0;

	   cout << "How many fighters can a team have?" << endl;
	   cout << "NUMBER OF FIGHTERS:  ";
	   cin >> numberOfFighters;
	   numberOfFighters = validateFloat(numberOfFighters, 1, 4);   // set limit to 4 fighters per team
	   cout << endl;

    for (int i = 0; i < numberOfFighters; i++) {
	   g1.chooseCharacter();
	   createTeam(1, g1.getP1Choice(), " ");
	   createTeam(2, g1.getP2Choice(), " ");
    }

    fighting();

// user option to display list of losers
    cout << endl;
    cout << "Would you like to see the list of losers? 1 = YES, 0 = NO " << endl;
    cout << "CHOICE:  ";
    cin.ignore();
    cin >> uChoice;
    uChoice = validateFloat(uChoice, 0, 1);
    if (uChoice == 1) {
	   listOfLosers.printLoserBracket();
    }

    counterTemp = listOfLosers.getNumLosers();
    for (int z = 0; z < counterTemp; z++) {
	   listOfLosers.removeLoser();
    }


// user option to play or quit
    cout << endl;	 
    cout << "Would you like to play again? 1 = YES, 0 = NO " << endl;
    cout << "CHOICE:  ";
    cin >> cont;
    cont = validateFloat(cont, 0, 1);
    }

    if (cont == 0) {
	   cout << "You decided to quit game." << endl;
    }
}

// create character obj and add to lineup
void tournament::createTeam(int teamNum, int charType, string charName) {
    switch (charType) {
    case vampires:
	   newFighter = new vampire(teamNum);
	   break;
    case barbarians:
	   newFighter = new barbarian(teamNum);
	   break;
    case blueMens:
	   newFighter = new bluemen(teamNum);
	   break;
    case medusas:
	   newFighter = new medusa(teamNum);
	   break;
    case harryPotters:
	   newFighter = new harrypotter(teamNum);
	   break;
    default:
	   newFighter = nullptr;
	   break;
    }

    newFighter->setNewName(charName);
    newFighter->setTeamNum(teamNum);

    if (teamNum == 1) {
	   A = newFighter;
	   team1.addFighter(newFighter);
    }
    else if (teamNum == 2) {
	   B = newFighter;
	   team2.addFighter(newFighter);
    }
    
    //delete newFighter;
}

// call combat
void tournament::fighting() {
    tournamentEnd = false;
    while (!tournamentEnd) {
	   roundCounter++;

	   cout << endl;
	   cout << "---------------------------------------------" << endl;
	   cout << " Round #" << roundCounter << endl;
	   cout << "---------------------------------------------" << endl;

	   character* tempP1 = team1.removeFighter();
	   character* tempP2 = team2.removeFighter();

	   if (tempP1 != nullptr || tempP2 != nullptr) {
		  g1.round(tempP1, tempP2, tempP2->getStrengthPoints());
		  winner = g1.getRoundWinner();
		  loser = g1.getRoundLoser();
		  cout << "Team " << winner->getTeamNum() << " " << winner->getName() << " " << winner->getNewName() << " vs. Team " << loser->getTeamNum() << " " << loser->getName() << " " << loser->getNewName() << endl;
		  cout << "ROUND " << roundCounter << " WINNER:  " << winner->getName() << " " << winner->getNewName() << endl;
	   }
	   
	   if (winner == tempP1) {
		  scoreTeam1++;
		  tempP1->recover(tempP1->getStrengthPoints());
		  team1.addFighter(tempP1);					// add tempP1 back to end of list
		  listOfLosers.addLoser(tempP2);
	   }
	   else if (winner == tempP2) {
		  scoreTeam2++;
		  tempP2->recover(tempP2->getStrengthPoints());
		  team2.addFighter(tempP2);
		  listOfLosers.addLoser(tempP1);
	   }

	   if (team1.getNumFighters() == 0 || team2.getNumFighters() == 0) {
		  displayFinalResults();
		  tournamentEnd = true;
		  break;
	   }
    }
}


// wrap up... display winner and deallocate the rest of lineup
void tournament::displayFinalResults() {
// display final results
    cout << " FINAL RESULTS " << endl;
    cout << "------------------------------------" << endl;
    cout << "TEAM 1 POINTS =  " << scoreTeam1 << endl;
    cout << "TEAM 2 POINTS =  " << scoreTeam2 << endl;

    if (scoreTeam1 == scoreTeam2)
	   cout << "Tournament " << tournamentCounter << "is a TIE." << endl;
    else
	   cout << "Tournament " << tournamentCounter << " winner is TEAM " << winner->getTeamNum() << endl;

    cout << "------------------------------------" << endl;

// deallocate/delete all fighters in tourney for fresh start next tourney
    if (winner->getTeamNum() == 1) {
	   for (int a = 0; a <= team1.getNumFighters(); a++) {
		  character* deleteMe = team1.removeFighter();
		  delete deleteMe;
	   } 
    }
    else if (winner->getTeamNum() == 2) {
	   for (int a = 0; a <= team2.getNumFighters(); a++) {
		  character* deleteMe = team2.removeFighter();
		  delete deleteMe;
	   }
    }
}

// getters
int tournament::getScoreTeam1() {
    return scoreTeam1;
}

int tournament::getScoreTeam2() {
    return scoreTeam2;
}


/*********************************************************************
** Description: Handle Floats - To input validate choices within a range
need #include <cctype>
*********************************************************************/
double tournament::validateFloat(double choice, int lowerLimit, int upperLimit) {
    bool floatNum = false;

    if (!isalpha(choice)) {							// check if choice = non-digit (letters)
	   for (int i = lowerLimit; i <= upperLimit; i++) {	// check if it is a whole number
		  if (choice == i) {
			 floatNum = true;
			 break;
		  }
	   }
    }

    if (floatNum == false || isalpha(choice)) {			// if not a whole number
	   while (!(choice >= lowerLimit && choice <= upperLimit && floatNum == true) || cin.fail()) {
		  cout << "ERROR! Enter whole digits between " << lowerLimit << " and " << upperLimit << ". What is your choice?" << endl;
		  cout << "NEW INPUT:  ";
		  cin.clear();
		  cin.ignore(100, '\n');
		  cin >> choice;

		  for (int i = lowerLimit; i <= upperLimit; i++) {// check if it is a whole number re-entered
			 if (choice == i) {
				floatNum = true;
				break;
			 }
		  }
	   }
    }

    return choice;
}