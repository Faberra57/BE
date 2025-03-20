#ifndef BESTIOLEOREILLE_
#define BESTIOLEOREILLE_

#include "Capteur.h"
#include "Milieu.h"
#include "Bestiole.h"
using namespace std;
class BestioleOreille : public Capteur
{
    public:
        BestioleOreille(const double delta_min,const double delta_max,
                const double gamma_min,const double gamma_max,const Bestiole&);
        std::vector<bool> detecter(const Milieu&) override;
    private:
        const Bestiole& owner;
        double delta;
        double gamma;
};


#endif