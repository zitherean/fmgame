#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "managers.h"

    class GameLogic{
        public:
            void goalProbabilityTraits(std::vector<Managers>& manager);
            void goalProbabilityFormation(std::vector<Managers>& manager);
            void chanceInfluenceTraits(std::vector<Managers>& manager, const int MANAGER_NUMBER);
            void chanceInfluenceFormation(std::vector<Managers>& manager, const int MANAGER_NUMBER);
            void chanceInfluenceGoalProbability(std::vector<Managers>& manager, const int MANAGER_NUMBER);
            void setAttackEvents(std::vector<Managers>& manager);
            void simulateMatch(std::vector<Managers>& manager);

        private:
            int randomNumberGenerator(const int MAX_NUMBER);
            void simulateAttackEvent(Managers& manager);
            bool simulateShot(double goalProbability);
            const int MANAGER_ONE = 0;
            const int MANAGER_TWO = 1;
            const int MAX_ATTACK_EVENTS = 30;
            const int MAX_ATTACK = 5;
            const int NUM_TRAITS = 5;
            const int NUM_FORMATION_ATTRIBUTES = 3;
            const int INFLUENCE_VALUE_TRAITS = 1;
            const double INFLUENCE_VALUE_FORMATION = 0.5;

    };

#endif