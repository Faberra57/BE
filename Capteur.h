#ifndef CAPTEUR_
#define CAPTEUR_

#include "Milieu.h"

class Milieu; 

using namespace std;

class Capteur
{
    public:
        virtual std::vector<bool> Detecter(Milieu& monMilieu) = 0;
};



#endif

