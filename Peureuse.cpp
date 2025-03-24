#include "Peureuse.h"
#include <iostream>
#include <cmath>

#include <fstream>
#include "json.hpp"

Peureuse::Peureuse(){}


void Peureuse::Deplacer(Bestiole& B1,Milieu& milieu){
    std::vector<bool> best_detectés = B1.Detection(milieu);
    std::vector<Bestiole*> best_aq = milieu.getBestioles();

    std::ifstream inputFile("param.json");
    if (!inputFile.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier!" << std::endl;
        return;
    }
    nlohmann::json j;
    inputFile >> j;

    double seuil = j["Peureuse"]["seuil"]; 
    int nb_bestiole_proches = 0;
    double Fx = 0;
    double Fy = 0;
    for (std::size_t i = 0; i< best_detectés.size();i++){
        if (best_detectés[i]){
            nb_bestiole_proches++;
            Fx = Fx + (B1.get_x() - (*best_aq[i]).get_x());
            Fy = Fy + (B1.get_y() - (*best_aq[i]).get_y());
        }
    }
    Fx = Fx / nb_bestiole_proches;
    Fy = Fy / nb_bestiole_proches;
    if (nb_bestiole_proches>seuil){
        if (Fx != 0 || Fy!= 0 ){
            B1.setOrientation(std::atan2(Fy,Fx) * 180 / M_PI + 180);
            B1.setVitesse(B1.getVitesse() * j["Peureuse"]["multiplicateur_vit_peureuse"]); 
    }
}
}
