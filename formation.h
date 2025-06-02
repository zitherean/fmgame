#ifndef FORMATION_H
#define FORMATION_H

    class FourFourTwo{
        public:
            FourFourTwo();
            ~FourFourTwo();            
            void displayFormation();
            const double ATTACK = 4.0;
            const double DEFENCE = 3.0;
            const double TRANSITION = 2.0;
    };

    class FourFiveOne{
        public:
            FourFiveOne();
            ~FourFiveOne();            
            void displayFormation();
            const double ATTACK = 2.5;
            const double DEFENCE = 2.0;
            const double TRANSITION = 4.5;
    };

    class ThreeFiveTwo{
        public:
            ThreeFiveTwo();
            ~ThreeFiveTwo();            
            void displayFormation();
            const double ATTACK = 1.5;
            const double DEFENCE = 4.5;
            const double TRANSITION = 3.0;
    };

#endif