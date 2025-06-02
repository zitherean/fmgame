#include "managers.h"
#include "formation.h"
#include <iostream>
#include <vector>

void Managers::createManagers(std::vector<Managers>& manager)
{
    std::cout << "It is time to choose your manager name. Enter the names of exactly " << MAX_PLAYERS << " managers." << std::endl;

    manager.resize(MAX_PLAYERS);

    for (int i = 0; i < MAX_PLAYERS; i++){
        std::cout << "Enter the name of manager " << i + 1 << ":" << std::endl;
        std::cin >> manager.at(i).name; 
    }

    std::cout << std::endl;

    std::cout << "Welcome to the Footy Verse ";

    for (int i = 0; i < MAX_PLAYERS; i++){
        std::cout << manager.at(i).name;
        if (i < MAX_PLAYERS - 1){
            std::cout << " and ";
        }
        if (i == MAX_PLAYERS - 1){
            std::cout << "!" << std::endl;
        }
    }

    std::cout << std::endl;
}

void Managers::chooseTraits(std::vector<Managers>& manager)
{
    std::cout << "It is time to setup your manager traits. There are 5 traits that every manager in the Footy Verse has. " 
                    "Each trait can have a minimum of 1 point and a maximum of 10 points. You have 25 points in total to use on your traits. " 
                    " Use 'l', 'c', 'd', 'm', 'p' to toggle between traits. Press 'f' to move on to the next phase." << std::endl;


    for (unsigned int i = 0; i < manager.size(); i++){
        std::cout << manager.at(i).name << " it is your turn to add your manager traits." << std::endl;
        std::cout << "Leadership (l)      Communication (c)      Decision-making (d)      Motivation (m)      Passion (p)      Next (f)" << std::endl;

        char c;
        bool nextPhase = false;
        while (std::cin >> c){
            switch (c){
                case 'l':
                    std::cout << "Leadership reflects your ability to inspire and guide your team, boosting morale and influencing game outcomes." << std::endl;
                    std::cout << "Leadership: " << manager.at(i).leadership << std::endl;
                    std::cout << "Enter a number between 1 and 10: ";
                    std::cin >> manager.at(i).leadership;
                    if (manager.at(i).leadership > MAX_POINTS_TRAIT){
                        std::cout << "Please enter a value between 1 and 10." << std::endl;
                        continue;
                    }
                    else{
                        break;
                    }
                case 'c':
                    std::cout << "Communication shows how well you interact with players on and off the pitch, ensuring clear strategy and unity." << std::endl;
                    std::cout << "Communication: " << manager.at(i).communication << std::endl;
                    std::cout << "Enter a number between 1 and 10: ";
                    std::cin >> manager.at(i).communication;
                    if (manager.at(i).communication > MAX_POINTS_TRAIT){
                        std::cout << "Please enter a value between 1 and 10." << std::endl;
                        continue;
                    }
                    else{
                        break;
                    }
                case 'd':
                    std::cout << "Decision-making is your skill in assessing situations and choosing the right action, especially in high-pressure moments." << std::endl;
                    std::cout << "Decision-making: " << manager.at(i).decisions << std::endl;
                    std::cout << "Enter a number between 1 and 10: ";
                    std::cin >> manager.at(i).decisions;
                    if (manager.at(i).decisions > MAX_POINTS_TRAIT){
                        std::cout << "Please enter a value between 1 and 10." << std::endl;
                        continue;
                    }
                    else{
                        break;
                    }
                case 'm':
                    std::cout << "Motivation drives your team's performance, helping them push through challenges and stay focused on success." << std::endl;
                    std::cout << "Motivation: " << manager.at(i).motivation << std::endl;
                    std::cout << "Enter a number between 1 and 10: ";
                    std::cin >> manager.at(i).motivation;
                    if (manager.at(i).motivation > MAX_POINTS_TRAIT){
                        std::cout << "Please enter a value between 1 and 10." << std::endl;
                        continue;
                    }
                    else{
                        break;
                    }
                case 'p':
                    std::cout << "Passion represents your dedication and love for the game, inspiring those around you and keeping energy levels high." << std::endl;
                    std::cout << "Passion: " << manager.at(i).passion << std::endl;
                    std::cout << "Enter a number between 1 and 10: ";
                    std::cin >> manager.at(i).passion;
                    if (manager.at(i).passion > MAX_POINTS_TRAIT){
                        std::cout << "Please enter a value between 1 and 10." << std::endl;
                        continue;
                    }
                    else{
                        break;
                    }
                case 'f':
                    int sum = 0; // so that the sum resets for each player 
                    sum = manager.at(i).leadership + manager.at(i).communication + manager.at(i).decisions + manager.at(i).motivation + manager.at(i).passion;
                    int pointsLeft = MAX_PLAYER_TRAIT_POINTS - sum;
                    if (sum > MAX_PLAYER_TRAIT_POINTS){
                        std::cout << "You have assigned too many trait points. A maximum of 30 points is allowed. You currently assigned " << sum << " points. You need to discard " << -pointsLeft << " points." << std::endl;
                        std::cout << "Leadership: " << manager.at(i).leadership << "    Communication: " << manager.at(i).communication << "    Decision-making: " << manager.at(i).decisions 
                                    << "   Motivation: " << manager.at(i).motivation << "   Passion: " << manager.at(i).passion << std::endl;
                        std::cout << "Discard a few trait points " << manager.at(i).name << "!" << std::endl; 
                        continue;
                    }
                    else if (sum < MAX_PLAYER_TRAIT_POINTS){
                        std::cout << "You have assigned too little trait points. A maximum of 30 points is allowed. You currently assigned " << sum << " points. You have " << pointsLeft << " points left." << std::endl;
                        std::cout << "Leadership: " << manager.at(i).leadership << "    Communication: " << manager.at(i).communication << "    Decision-making: " << manager.at(i).decisions 
                                    << "   Motivation: " << manager.at(i).motivation << "   Passion: " << manager.at(i).passion << std::endl;
                        std::cout << "Add more trait points " << manager.at(i).name << "!" << std::endl;
                        continue;
                    }
                    else{
                        char answer;
                        std::cout << "You currently assigned " << sum << " points." << std::endl;
                        std::cout << "Leadership: " << manager.at(i).leadership << "    Communication: " << manager.at(i).communication << "    Decision-making: " << manager.at(i).decisions 
                                    << "   Motivation: " << manager.at(i).motivation << "   Passion: " << manager.at(i).passion << std::endl;
                        std::cout << "Are you ready to finish? [y/n]" << std::endl;
                        std::cin >> answer;
                        if (answer == 'n'){
                            continue;
                        }
                        if (answer == 'y'){
                            nextPhase = true;
                            break;
                        }
                        break;
                    }
                // default:
                //     break;
            }

            if (nextPhase == true){
                break;
            }
        }    
        std::cout << std::endl;        
    }
}

void Managers::chooseFormation(std::vector<Managers>& manager)
{
    std::cout << "You can now choose the formation that you want to play with. There are 3 formations to choose from. " 
                    "Each formation has its pros and cons. Use 'y', 'i', and 'p' to toggle between formations. "
                    "Press 's' to finalize your selection or 'b' to choose another formation." << std::endl;

    for (unsigned int i = 0; i < manager.size(); i++){
        std::cout << manager.at(i).name << " it is your turn to choose a formation." << std::endl;
        std::cout << "4-4-2 (y)       4-5-1 (i)       3-5-2 (p)       Select (s)      Back (b)" << std::endl;

        char formation;
        bool nextStep = false;
        char choice;
        while (std::cin >> formation){
            switch (formation){
                case 'y':
                    fourFourTwo.displayFormation();
                    std::cout << "Press 's' to select this formation or 'b' to select another formation." << std::endl;
                    std::cin >> choice;
                    if (choice == 's'){
                        std::cout << manager.at(i).name << " you have selected 4-4-2." << std::endl;
                        manager.at(i).formationAttack = fourFourTwo.ATTACK;
                        manager.at(i).formationDefence = fourFourTwo.DEFENCE;
                        manager.at(i).formationTransition = fourFourTwo.TRANSITION;
                        nextStep = true;
                        break;
                    }
                    break;
                case 'i':
                    fourFiveOne.displayFormation();
                    std::cout << "Press 's' to select this formation or 'b' to select another formation." << std::endl;
                    std::cin >> choice;
                    if (choice == 's'){
                        std::cout << manager.at(i).name << " you have selected 4-5-1." << std::endl;
                        manager.at(i).formationAttack = fourFiveOne.ATTACK;
                        manager.at(i).formationDefence = fourFiveOne.DEFENCE;
                        manager.at(i).formationTransition = fourFiveOne.TRANSITION;
                        nextStep = true;
                        break;
                    }
                    break;
                case 'p':
                    threeFiveTwo.displayFormation();
                    std::cout << "Press 's' to select this formation or 'b' to select another formation." << std::endl;
                    std::cin >> choice;
                    if (choice == 's'){
                        std::cout << manager.at(i).name << " you have selected 3-5-2." << std::endl;
                        manager.at(i).formationAttack = threeFiveTwo.ATTACK;
                        manager.at(i).formationDefence = threeFiveTwo.DEFENCE;
                        manager.at(i).formationTransition = threeFiveTwo.TRANSITION;
                        nextStep = true;
                        break;
                    }
                    break;
                default:
                    break;
            }

            if (nextStep == true){
                break;
            }
        }
        std::cout << std::endl;
    }
}

void Managers::setChance(std::vector<Managers>& manager)
{
    std::srand(time(0));
    
    for (unsigned int i = 0; i < manager.size(); i++){
        manager.at(i).chance = std::rand() % 10 + 1;
    }
}