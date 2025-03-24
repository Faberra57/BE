#ifndef BESTIOLEYEUX_
#define BESTIOLEYEUX_

#include "Capteur.h"
#include "Milieu.h"
#include "Bestiole.h"

using namespace std;
class BestioleYeux : public Capteur
{
    public:
        BestioleYeux(const Bestiole&);
        std::vector<bool> detecter(const Milieu& monMilieu);
    private:
        const Bestiole& owner;
        double alpha;
        double delta;
        double gamma;
};


#endif