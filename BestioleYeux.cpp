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

double angleEntreVecteurs(double Ax, double Ay, double Bx, double By) {

    // Produit scalaire
    double produitScalaire = Ax * Bx + Ay * By;

    // Normes des vecteurs
    double normeA = std::sqrt(Ax * Ax + Ay * Ay);
    double normeB = std::sqrt(Bx * Bx + By * By);

    // Vérification pour éviter une division par zéro
    if (normeA == 0 || normeB == 0) {
        return 0;  // Aucun angle défini si l'un des vecteurs est nul
    }

    // Calcul de l'angle en radians
    double cosTheta = produitScalaire / (normeA * normeB);
    
    // Sécurité pour éviter des erreurs d'arrondi
    if (cosTheta > 1) cosTheta = 1;
    if (cosTheta < -1) cosTheta = -1;

    return std::abs(std::acos(cosTheta));  // Valeur absolue de l'angle en radians
}



std::vector<bool> BestioleYeux::detecter(const Milieu& milieu)
{
    std::vector<bool> res;
    for (int i = 0; i < milieu.getNbBestioles(); i++)
    {
        double distance = sqrt(pow(owner.getX() - milieu.getBestiole(i).getX(), 2) + pow(owner.getY()  - milieu.getBestiole(i).getY(), 2));
        double angle = angleEntreVecteurs(owner.getVx(), owner.getVy(), milieu.getBestiole(i).getX() - owner.getX(), milieu.getBestiole(i).getY() - owner.getY());
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