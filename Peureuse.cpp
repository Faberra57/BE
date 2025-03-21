#include "Peureuse.h"
#include <iostream>
#include <cmath>

#include <fstream>
#include "json.hpp"

Peureuse::Peureuse(){}


void Peureuse::Deplacer(Bestiole& B1,Milieu& milieu){
    std::vector<Bool> best_detectés = B1.detection(milieu);
    std::vector<Bestiole> best_aq = milieu.getVectBest();

    std::ifstream inputFile("param.json");
    if (!inputFile.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier!" << std::endl;
        return;
    }
    nlohmann::json j;
    inputFile >> j;

    double seuil = j["Peureuse"]["seuil"]; // seuil à définir dans le JSON, sert à établir le nombre maximal de bestioles environnates détécté au bout duquel la la bestiole Peureuse fuit
    int nb_bestiole_proches = 0;
    double Fx = 0;
    double Fy = 0;
    for (std::size_t i = 0; i< best_detectés.size();i++){
        if (best_detectés[i]){
            nb_bestiole_proches++;
            Fx = Fx + (B1.get_x() - best_aq[i].get_x());
            Fy = Fy + (B1.get_y() - best_aq[i].get_y());
        }
    }
    Fx = Fx / nb_bestiole_proches;
    Fy = Fy / nb_bestiole_proches;
    if (nb_bestiole_proches>seuil){
        if (Fx != 0 || Fy!= 0 ){
            B1.setOrientation(std::atan2(Fy,Fx) * 180 / M_PI + 180);
            B1.setVitesse(B1.getVitesse() * j["Peureuse"]["multiplicateur_vit_peureuse"]); //multiplicateur à définir dans le JSON
    }
}
}

//vecteur detection obtenu via une méthode qu'on implemente sur la classe bestiole
//tout mettre en privé pour les attributs, rajouter des setteurs/getteurs