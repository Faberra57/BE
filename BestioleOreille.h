#ifndef BESTIOLEOREILLE_
#define BESTIOLEOREILLE_

#include "Capteur.h"
#include "Milieu.h"
#include "Bestiole.h"

using namespace std;
class BestioleOreille : public Capteur
{
    public:
        BestioleOreille(const Bestiole&);
        std::vector<bool> detecter(const Milieu& monMilieu);
    private:
        const Bestiole& owner;
        double delta;
        double gamma;
};


#endif