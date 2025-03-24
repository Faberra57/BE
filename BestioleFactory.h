#ifndef BESTIOLEFACTORY_H
#define BESTIOLEFACTORY_H

#include "Bestiole.h"
#include <map>
#include <string>

class BestioleFactory {
private:
    int id_counter = 0;  // Compteur d'identifiant pour les bestioles
    // Paramètres de la simulation
    int RESISTANCE_MAX;
    int REDUCTION_RESISTANCE;
    double PROBA_GRÉGAIRE;
    double PROBA_KAMIKAZE;
    double PROBA_PEUREUSE;
    double PROBA_PRÉVOYANTE;
    double PROBA_MULTIPLE;
    double PROBA_OREILLE;
    double PROBA_YEUX;
    double PROBA_NAGEOIRE;
    double PROBA_CARAPACE;
    double PROBA_CAMOUFLAGE;
    int VITESSE_MAX;
    int AGE_MAX;
    double TAILLE;
    int DETECTABILITE_MAX;

public:
    BestioleFactory();  
    ~BestioleFactory() = default;
    
    Bestiole* CreerBestiole();  // Crée une nouvelle bestiole
};

#endif // 
