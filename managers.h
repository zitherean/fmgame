#ifndef MANAGERS_H
#define MANAGERS_H

#include "formation.h"
#include <vector>
#include <string>

    class Managers{
        public:
            void createManagers(std::vector<Managers>& manager);
            void chooseTraits(std::vector<Managers>& manager);
            void chooseFormation(std::vector<Managers>& manager);
            void setChance(std::vector<Managers>& manager);
            std::string name;
            int leadership = 1;
            int communication = 1;
            int decisions = 1;
            int motivation = 1;
            int passion = 1;
            int chance;
            int attackEvents;
            int score;
            double goalProbability;
            double formationAttack;
            double formationDefence;
            double formationTransition;
            
        private:
            const int MAX_PLAYERS = 2;
            const int MAX_PLAYER_TRAIT_POINTS = 30;
            const int MAX_POINTS_TRAIT = 10;
            FourFourTwo fourFourTwo;
            FourFiveOne fourFiveOne;
            ThreeFiveTwo threeFiveTwo;
    };


#endif