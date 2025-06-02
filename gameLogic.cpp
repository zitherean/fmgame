#include <unistd.h>
#include "gameLogic.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void GameLogic::goalProbabilityTraits(std::vector<Managers>& manager)
{
    if (manager.at(MANAGER_ONE).leadership > manager.at(MANAGER_TWO).leadership){
        manager.at(MANAGER_ONE).goalProbability += 0.02;
    }
    else if (manager.at(MANAGER_ONE).leadership < manager.at(MANAGER_TWO).leadership){
        manager.at(MANAGER_TWO).goalProbability += 0.02;
    }

    if (manager.at(MANAGER_ONE).communication > manager.at(MANAGER_TWO).communication){
        manager.at(MANAGER_ONE).goalProbability += 0.02;
    }
    else if (manager.at(MANAGER_ONE).communication < manager.at(MANAGER_TWO).communication){
        manager.at(MANAGER_TWO).goalProbability += 0.02;
    }

    if (manager.at(MANAGER_ONE).decisions > manager.at(MANAGER_TWO).decisions){
        manager.at(MANAGER_ONE).goalProbability += 0.02;
    }
    else if (manager.at(MANAGER_ONE).decisions < manager.at(MANAGER_TWO).decisions){
        manager.at(MANAGER_TWO).goalProbability += 0.02;
    }

    if (manager.at(MANAGER_ONE).motivation > manager.at(MANAGER_TWO).motivation){
        manager.at(MANAGER_ONE).goalProbability += 0.02;
    }
    else if (manager.at(MANAGER_ONE).motivation < manager.at(MANAGER_TWO).motivation){
        manager.at(MANAGER_TWO).goalProbability += 0.02;
    }

    if (manager.at(MANAGER_ONE).passion > manager.at(MANAGER_TWO).passion){
        manager.at(MANAGER_ONE).goalProbability += 0.02;
    }
    else if (manager.at(MANAGER_ONE).passion < manager.at(MANAGER_TWO).passion){
        manager.at(MANAGER_TWO).goalProbability += 0.02;
    }
}

void GameLogic::goalProbabilityFormation(std::vector<Managers>& manager)
{
    if (manager.at(MANAGER_ONE).formationAttack > manager.at(MANAGER_TWO).formationAttack){
        manager.at(MANAGER_ONE).goalProbability += 0.05;
    }
    else if (manager.at(MANAGER_ONE).formationAttack < manager.at(MANAGER_TWO).formationAttack){
        manager.at(MANAGER_TWO).goalProbability += 0.05;
    }

    if (manager.at(MANAGER_ONE).formationDefence > manager.at(MANAGER_TWO).formationDefence){ // goal probability should go down if the other team has a strong defence.
        manager.at(MANAGER_TWO).goalProbability += -0.05; 
    }
    else if (manager.at(MANAGER_ONE).formationDefence < manager.at(MANAGER_TWO).formationDefence){
        manager.at(MANAGER_ONE).goalProbability += -0.05;
    }

    if (manager.at(MANAGER_ONE).formationTransition > manager.at(MANAGER_TWO).formationTransition){
        manager.at(MANAGER_ONE).goalProbability += 0.02;
    }
    else if (manager.at(MANAGER_ONE).formationTransition < manager.at(MANAGER_TWO).formationTransition){
        manager.at(MANAGER_TWO).goalProbability += 0.02;
    }

    if (((manager.at(MANAGER_ONE).formationTransition + manager.at(MANAGER_ONE).formationAttack) / 2) > ((manager.at(MANAGER_TWO).formationTransition + manager.at(MANAGER_TWO).formationAttack) / 2)){
        manager.at(MANAGER_ONE).goalProbability += 0.05;
    }
    else if (((manager.at(MANAGER_ONE).formationTransition + manager.at(MANAGER_ONE).formationAttack) / 2) < ((manager.at(MANAGER_TWO).formationTransition + manager.at(MANAGER_TWO).formationAttack) / 2)){
        manager.at(MANAGER_TWO).goalProbability += 0.05;
    }

    if (((manager.at(MANAGER_ONE).formationTransition + manager.at(MANAGER_ONE).formationDefence) / 2) > ((manager.at(MANAGER_TWO).formationTransition + manager.at(MANAGER_TWO).formationDefence) / 2)){
        manager.at(MANAGER_ONE).goalProbability += 0.01;
        manager.at(MANAGER_TWO).goalProbability += -0.02;
    }
    else if (((manager.at(MANAGER_ONE).formationTransition + manager.at(MANAGER_ONE).formationDefence) / 2) < ((manager.at(MANAGER_TWO).formationTransition + manager.at(MANAGER_TWO).formationDefence) / 2)){
        manager.at(MANAGER_ONE).goalProbability += -0.02;
        manager.at(MANAGER_TWO).goalProbability += 0.01;
    }

    if (((manager.at(MANAGER_ONE).formationDefence + manager.at(MANAGER_ONE).formationAttack) / 2) > ((manager.at(MANAGER_TWO).formationDefence + manager.at(MANAGER_TWO).formationAttack) / 2)){
        manager.at(MANAGER_ONE).goalProbability += 0.01;
    }
    else if (((manager.at(MANAGER_ONE).formationDefence + manager.at(MANAGER_ONE).formationAttack) / 2) < ((manager.at(MANAGER_TWO).formationDefence + manager.at(MANAGER_TWO).formationAttack) / 2)){
        manager.at(MANAGER_TWO).goalProbability += 0.01;
    }
}

void GameLogic::chanceInfluenceTraits(std::vector<Managers>& manager, const int MANAGER_NUMBER)
{
    int random = randomNumberGenerator(NUM_TRAITS);

    if (manager.at(MANAGER_NUMBER).chance == 10){ // 10 means really lucky
        manager.at(MANAGER_NUMBER).leadership += INFLUENCE_VALUE_TRAITS;
        manager.at(MANAGER_NUMBER).communication += INFLUENCE_VALUE_TRAITS;
        manager.at(MANAGER_NUMBER).decisions += INFLUENCE_VALUE_TRAITS;
        manager.at(MANAGER_NUMBER).motivation += INFLUENCE_VALUE_TRAITS;
        manager.at(MANAGER_NUMBER).passion += INFLUENCE_VALUE_TRAITS;
    }
    else if (manager.at(MANAGER_NUMBER).chance >= 6 && manager.at(MANAGER_NUMBER).chance <= 9){ // slightly lucky
        if (random == 1){
            manager.at(MANAGER_NUMBER).leadership += INFLUENCE_VALUE_TRAITS;
        }
        else if (random == 2){
            manager.at(MANAGER_NUMBER).communication += INFLUENCE_VALUE_TRAITS;
        }
        else if (random == 3){
            manager.at(MANAGER_NUMBER).decisions += INFLUENCE_VALUE_TRAITS;
        }
        else if (random == 4){
            manager.at(MANAGER_NUMBER).motivation += INFLUENCE_VALUE_TRAITS;
        }
        else if (random == 5){
            manager.at(MANAGER_NUMBER).passion += INFLUENCE_VALUE_TRAITS;
        }
    }
    else if (manager.at(MANAGER_NUMBER).chance >= 2 && manager.at(MANAGER_NUMBER).chance <= 4){ // slightly unlucky
        if (random == 1){
            manager.at(MANAGER_NUMBER).leadership -= INFLUENCE_VALUE_TRAITS;
        }
        else if (random == 2){
            manager.at(MANAGER_NUMBER).communication -= INFLUENCE_VALUE_TRAITS;
        }
        else if (random == 3){
            manager.at(MANAGER_NUMBER).decisions -= INFLUENCE_VALUE_TRAITS;
        }
        else if (random == 4){
            manager.at(MANAGER_NUMBER).motivation -= INFLUENCE_VALUE_TRAITS;
        }
        else if (random == 5){
            manager.at(MANAGER_NUMBER).passion -= INFLUENCE_VALUE_TRAITS;
        }        
    }
    else if (manager.at(MANAGER_NUMBER).chance == 1){ // 1 means really unlucky
        manager.at(MANAGER_NUMBER).leadership -= INFLUENCE_VALUE_TRAITS;
        manager.at(MANAGER_NUMBER).communication -= INFLUENCE_VALUE_TRAITS;
        manager.at(MANAGER_NUMBER).decisions -= INFLUENCE_VALUE_TRAITS;
        manager.at(MANAGER_NUMBER).motivation -= INFLUENCE_VALUE_TRAITS;
        manager.at(MANAGER_NUMBER).passion -= INFLUENCE_VALUE_TRAITS;
    }
}

void GameLogic::chanceInfluenceFormation(std::vector<Managers>& manager, const int MANAGER_NUMBER)
{
    int random = randomNumberGenerator(NUM_FORMATION_ATTRIBUTES);

    if (manager.at(MANAGER_NUMBER).chance == 10){ // 10 means really lucky
        manager.at(MANAGER_NUMBER).formationAttack += INFLUENCE_VALUE_FORMATION;
        manager.at(MANAGER_NUMBER).formationDefence += INFLUENCE_VALUE_FORMATION;
        manager.at(MANAGER_NUMBER).formationTransition += INFLUENCE_VALUE_FORMATION;
    }
    else if (manager.at(MANAGER_NUMBER).chance >= 6 && manager.at(MANAGER_NUMBER).chance <= 9){ // slightly lucky
        if (random == 1){
            manager.at(MANAGER_NUMBER).formationAttack += INFLUENCE_VALUE_FORMATION;
        }
        else if (random == 2){
            manager.at(MANAGER_NUMBER).formationDefence += INFLUENCE_VALUE_FORMATION;
        }
        else if (random == 3){
            manager.at(MANAGER_NUMBER).formationTransition += INFLUENCE_VALUE_FORMATION;
        }
    }
    else if (manager.at(MANAGER_NUMBER).chance >= 2 && manager.at(MANAGER_NUMBER).chance <= 4){ // slightly unlucky
        if (random == 1){
            manager.at(MANAGER_NUMBER).formationAttack -= INFLUENCE_VALUE_FORMATION;
        }
        else if (random == 2){
            manager.at(MANAGER_NUMBER).formationDefence -= INFLUENCE_VALUE_FORMATION;
        }
        else if (random == 3){
            manager.at(MANAGER_NUMBER).formationTransition -= INFLUENCE_VALUE_FORMATION;
        }
    }
    else if (manager.at(MANAGER_NUMBER).chance == 1){ // 1 means really unlucky
        manager.at(MANAGER_NUMBER).formationAttack -= INFLUENCE_VALUE_FORMATION;
        manager.at(MANAGER_NUMBER).formationDefence -= INFLUENCE_VALUE_FORMATION;
        manager.at(MANAGER_NUMBER).formationTransition -= INFLUENCE_VALUE_FORMATION;
    }    
}

void GameLogic::chanceInfluenceGoalProbability(std::vector<Managers>& manager, const int MANAGER_NUMBER)
{
    if (manager.at(MANAGER_NUMBER).chance == 10){ // 10 means really lucky
        manager.at(MANAGER_NUMBER).goalProbability += 0.1;
    }
    else if (manager.at(MANAGER_NUMBER).chance >= 6 && manager.at(MANAGER_NUMBER).chance <= 9){ // slightly lucky
        manager.at(MANAGER_NUMBER).goalProbability += 0.02;
    }
    else if (manager.at(MANAGER_NUMBER).chance >= 2 && manager.at(MANAGER_NUMBER).chance <= 4){ // slightly unlucky
        manager.at(MANAGER_NUMBER).goalProbability -= 0.02;
    }
    else if (manager.at(MANAGER_NUMBER).chance == 1){ // 1 means really unlucky
        manager.at(MANAGER_NUMBER).goalProbability -= 0.05;
    }
}

void GameLogic::setAttackEvents(std::vector<Managers>& manager)
{
    for (unsigned int i = 0; i < manager.size(); i++){
        manager.at(i).attackEvents = (manager.at(i).formationAttack / MAX_ATTACK) * MAX_ATTACK_EVENTS;
    }
}

void GameLogic::simulateMatch(std::vector<Managers>& manager)
{
    std::cout << "The teams are lining up..." << std::endl;
    sleep(10);
    std::vector<int> allAttackEvents;
    for (int i = 0; i < manager.at(MANAGER_ONE).attackEvents; i++){
        allAttackEvents.push_back(MANAGER_ONE);
    }
    for (int i = 0; i < manager.at(MANAGER_TWO).attackEvents; i++){
        allAttackEvents.push_back(MANAGER_TWO);
    }

    auto random = std::random_device {}; 
    auto range = std::default_random_engine { random() };
    std::shuffle(allAttackEvents.begin(), allAttackEvents.end(), range);

    int totalEvents = allAttackEvents.size() - 1;
    unsigned int halfTime = randomNumberGenerator(totalEvents);

    char answer = ' ';
    for (unsigned int i = 0; i < allAttackEvents.size(); i++){
        if (i == halfTime){
            std::cout << "Half Time" << std::endl;
            std::cout << "HALFTIME SCORE: " << manager.at(MANAGER_ONE).score << " - " << manager.at(MANAGER_TWO).score << std::endl;
            std::cout << "Press 'c' to continue. ";
            while (std::cin >> answer){
                if (answer == 'c'){
                    break;
                }
                continue;
            }
        }
        simulateAttackEvent(manager.at(allAttackEvents.at(i)));
    }

    std::cout << "FINAL SCORE: " << manager.at(MANAGER_ONE).score << " - " << manager.at(MANAGER_TWO).score << std::endl;
}

void GameLogic::simulateAttackEvent(Managers& manager)
{
    double attackToShot = 0.7;
    double randomChance = static_cast<double>(std::rand()) / RAND_MAX;

    if (randomChance < attackToShot){
        if (simulateShot(manager.goalProbability) == true){
            manager.score += 1;
            std::cout << "GOAL! " << manager.name << " your team has scored." << std::endl;
            sleep(3);
        }
        else{
            std::cout << manager.name << " your forwards have missed the target again." << std::endl;
            sleep(1);
        }
    }
    else{
        std::cout << manager.name << " your team had a chance, but it lead to nothing." << std::endl;
        sleep(1);
    }
}

bool GameLogic::simulateShot(double goalProbability)
{
    double shotOutcome = static_cast<double>(std::rand()) / RAND_MAX;

    if (shotOutcome < goalProbability){
        return true;
    }

    return false;
}

int GameLogic::randomNumberGenerator(const int MAX_NUMBER)
{
    return std::rand() % MAX_NUMBER + 1;
}