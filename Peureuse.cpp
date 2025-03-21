#include "Peureuse.h"
#include <iostream>
#include <cmath>

Peureuse::Peureuse(){}


void Peureuse::Deplacer(Bestiole& B1,Milieu& milieu){
    std::vector<Bool> detection = B1.Detecter();
    double seuil = 10; // seuil à définir en général
    int nb_bestiole_proches = 0;
    double Fx = 0;
    double Fy = 0;
    for (std::size_t i = 0; i< detection.size();i++){
        if (detection[i]){
            nb_bestiole_proches++;
            Fx = Fx + (B1.get_x() - detection[i].get_x());
            Fy = Fy + (B1.get_y() - detection[i].get_y());
        }
    }
    if (nb_bestiole_proches>seuil){
        B1.setOrientation(std::atan2(Fy,Fx) * 180 / M_PI + 180);
        B1.setVitesse(B1.getVitesse() * 2); //multiplicateur à définir en amont
    }
}

//vecteur detection obtenu via une méthode qu'on implemente sur la classe bestiole
//tout mettre en privé pour les attributs, rajouter des setteurs/getteurs