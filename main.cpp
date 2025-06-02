#include "formation.h"
#include "managers.h"
#include "gameLogic.h"
#include <iostream>

int main()
{
    std::cout << "Welcome to Footy Man for Ubuntu!" << std::endl;
    std::cout << "This is a two (2) player game. Play with your friend to see who is the best manager in the Footy Verse." << std::endl << std::endl;
    
    std::cout << "Press 'c' to continue or 'q' to quit" << std::endl;
    char answer;
    char input;
    std::cin >> answer;
    std::cout << std::endl;

    const int MANAGER_ONE = 0;
    const int MANAGER_TWO = 1;    

    if (answer == 'c'){
        Managers m;
        GameLogic g;
        std::vector<Managers> manager; 

        m.createManagers(manager);
        m.chooseTraits(manager);
        m.chooseFormation(manager);
        m.setChance(manager);    
    
        while (input != 'q'){
            g.goalProbabilityTraits(manager);
            g.goalProbabilityFormation(manager);
            g.chanceInfluenceTraits(manager, MANAGER_ONE);
            g.chanceInfluenceTraits(manager, MANAGER_TWO);
            g.chanceInfluenceFormation(manager, MANAGER_ONE);
            g.chanceInfluenceFormation(manager, MANAGER_TWO);
            g.chanceInfluenceGoalProbability(manager, MANAGER_ONE);
            g.chanceInfluenceGoalProbability(manager, MANAGER_TWO);
            g.setAttackEvents(manager);

            g.simulateMatch(manager);
            std::cout << "Do you want to play again? Press 'c' to continue and 'q' to quit." << std::endl;
            std::cin >> input;
            manager.at(MANAGER_ONE).score = 0;
            manager.at(MANAGER_TWO).score = 0;
            manager.at(MANAGER_ONE).goalProbability = 0;
            manager.at(MANAGER_TWO).goalProbability = 0;
            m.setChance(manager);
        }
    }
    else{
        std::cout << "Exiting game..." << std::endl;
    }

    return 0;
}