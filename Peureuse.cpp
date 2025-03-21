#include "Peureuse.h"
#include <iostream>
#include <cmath>
#include limits

Peureuse::Peureuse(){}


void Peureuse::Deplacer(Bestiole& B1,Milieu milieu,std::vector<Bool> detection){
    double seuil = 10;
    int nb_bestiole_proches = 0;
    double Fx = 0;
    double Fy = 0;
    for (std::size_t i = 0; i<dectection.size();i++){
        if (detection[i]){
            nb_bestioles_proches++;
            Fx = Fx + (B1.position_x - detection[i].position_x);
            Fy = Fy + (B1.position_y - detection[i].position_y);
        }
    }
    if (nb_bestioles_proches>seuil){
        B1.orientation = std::atan2(Fy,Fx) * 180 / M_PI + 180;
        B1.vitesse = B1.vitesse * 2;
    }
}

//vecteur detection obtenu via une méthode qu'on implemente sur la classe bestiole
//tout mettre en privé pour les attributs, rajouter des setteurs/getteurs