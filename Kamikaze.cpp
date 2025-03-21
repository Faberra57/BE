#include "Kamikaze.h"
#include <iostream>
#include <cmath>
#include limits

Kamikaze::Kamkikaze(){}


void Kamikaze::Deplacer(Bestiole& B1,Milieu milieu,std::vector<Bool> detection){
    double dist_min = std::numeric_limits<double>::infinity();
    int position_bestiole_proche = 0;
    for (std::size_t i = 0; i<dectection.size();i++){
        if (detection[i]){
            Bestiole B2 = milieu.vecteur_bestioles[i];
            double tmp = (B1.position_x - B2.position_x)^2 + (B1.position_y - B2.position_y)^2
            if (tmp<dist_min){
                dist_min = tmp;
                position_bestiole_proche = i;
            }
        }
    }

    double dx = B1.position_x - milieu.vecteur_bestioles[position_bestiole_proche].position_x
    double dy = B1.position_y - milieu.vecteur_bestioles[position_bestiole_proche].position_y

    B1.orientation = std::atan2(dy,dx) * 180 / M_PI;
    B1.vitesse = B1.vitesse * 2;
}

