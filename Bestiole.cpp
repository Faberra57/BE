#include "Bestiole.hpp"
#include <cmath>
#include <iostream>

Bestiole::Bestiole(int id, double v, double x, double y, double o, double t, int a_lim, bool vivant, double res, double detect)
    : id(id), vitesse(v), position_x(x), position_y(y), orientation(o), taille(t), age(0),
      age_limite(a_lim), estVivant(vivant), resistance(res), detectabilite(detect) {}

void Bestiole::mort() {
    if (age >= age_limite || resistance <= 0) {
        estVivant = false;
    }
}

Bestiole* Bestiole::clonage() {
    return new Bestiole(*this);
}

void virtual Bestiole::Deplacer() {
    position_x += vitesse * cos(orientation);
    position_y += vitesse * sin(orientation);
}

void Bestiole::Percussion(Bestiole* autre) {
 

    
    if (std::abs(position_x - autre->position_x) < 1e-3 &
        std::abs(position_y - autre->position_y) < 1e-3) {

        std::cout << " Collision détectée entre Bestiole #" << id
                  << " et Bestiole " << autre->id << std::endl;

        // réduction de résistance
        resistance -= 10;
        autre->resistance -= 10;

        
        
     
    }
}
