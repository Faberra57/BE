#include "Kamikaze.h"
#include <iostream>
#include <cmath>

void Kamikaze::Deplacer(Bestiole& B1,Milieu& milieu,std::vector<Bool> detection){
    std::vector<Bool> detection = B1.Detecter(); //définir la méthode detecter qui renvoi la détéction via des bool de toutes les bestioles de l'aquarium
    double dist_min = std::numeric_limits<double>::infinity();
    int position_bestiole_proche = 0;
    for (std::size_t i = 0; i< detection.size();i++){
        if (detection[i]){
            Bestiole B2 = milieu.vecteur_bestioles[i]; //besoin d'une méthode qui récupère la i-ème bestiole de l'aquarium
            double tmp = (B1.get_x() - B2.get_x())^2 + (B1.get_y() - B2.get_y())^2 ; 
            if (tmp<dist_min){
                dist_min = tmp;
                position_bestiole_proche = i;
            }
        }
    }

    double dx = B1.get_x() - milieu.vecteur_bestioles[position_bestiole_proche].get_x();
    double dy = B1.get_y() - milieu.vecteur_bestioles[position_bestiole_proche].get_y();

    B1.setOrientation(std::atan2(dy,dx) * 180 / M_PI);
    B1.setVitesse(B1.getVitesse();
}

