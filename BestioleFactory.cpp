#include "BestioleFactory.h"
#include <cstdlib>   // rand()
#include <iostream>

BestioleFactory::BestioleFactory() {
    
}

Bestiole* BestioleFactory::CreerBestiole() {
    int id = rand() % 1000;  
    double vitesse = (rand() % 100);
    double x = rand() % 100;
    double y = rand() % 100;
    double orientation = (rand() % 360) * 3.14159 / 180;
    double taille = 5.0;
    int age_limite = 100;
    bool vivant = true;
    double resistance = (rand() % 50);
    double detectabilite = (rand() % 30);

    return new Bestiole(id, vitesse, x, y, orientation, taille, age_limite, vivant, resistance, detectabilite);
}
