#ifndef CAPTEUR_
#define CAPTEUR_

#include "Milieu.h"
using namespace std;

class Capteur
{
    public:
        virtual std::vector<bool> detecter(const Milieu&) = 0;
};



#endif

