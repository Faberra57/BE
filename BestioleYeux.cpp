#include "BestioleYeux.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <cmath>

using namespace std;

/*
J'utilise des angles en radians pour les calculs
*/

BestioleYeux::BestioleYeux(const double delta_min,const double delta_max,
    const double alpha_min,const double alpha_max,
    const double gamma_min,const double gamma_max,const Bestiole& bestiole) : owner(bestiole)
{
    alpha = (alpha_max - alpha_min) * ((double)rand() / RAND_MAX) + alpha_min;
    delta = (delta_max - delta_min) * ((double)rand() / RAND_MAX) + delta_min;
    gamma = (gamma_max - gamma_min) * ((double)rand() / RAND_MAX) + gamma_min;
}

std::vector<bool> BestioleYeux::detecter(const Milieu& milieu)
{
    std::vector<bool> res;
    for (int i = 0; i < milieu.getNbBestioles(); i++)
    {
        double distance = sqrt(pow(owner.getX() - milieu.getBestiole(i).getX(), 2) + pow(owner.getY()  - milieu.getBestiole(i).getY(), 2));
        double angle = std::abs(owner.getOrientation() - milieu.getBestiole(i).getOrientation());
        if (distance <= delta && angle <= alpha/2 && (double)rand() / RAND_MAX <= gamma) //alpha/2 car on prend la valeur absolue de l'angle entre les deux vecteurs vitesse
        {
            res.push_back(true);
        }
        else
        {
            res.push_back(false);
        }
    }
    return res;
}