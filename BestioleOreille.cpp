#include "BestioleOreille.h"
#include "Milieu.h"
#include "Bestiole.h"

using namespace std;

/*
J'initialise les attributs de la classe BestioleOreille avec un nombre aléatoire entre les bornes 
delta_min et delta_max et gamma_min et gamma_max.

*/

BestioleOreille::BestioleOreille(const double delta_min,const double delta_max,
    const double gamma_min,const double gamma_max,const Bestiole& bestiole) : owner(bestiole)
{
    delta = (delta_max - delta_min) * ((double)rand() / RAND_MAX) + delta_min;
    gamma = (gamma_max - gamma_min) * ((double)rand() / RAND_MAX) + gamma_min;
}

std::vector<bool> BestioleOreille::detecter(const Milieu& milieu)
{
    std::vector<bool> res;
    for (int i = 0; i < milieu.getNbBestioles(); i++)
    {
        double distance = sqrt(pow(owner.getX() - milieu.getBestiole(i).getX(), 2) + pow(owner.getY()  - milieu.getBestiole(i).getY(), 2));
        if (distance <= delta && (double)rand() / RAND_MAX <= gamma)
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