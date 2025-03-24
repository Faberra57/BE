#include "Kamikaze.h"
#include "Bestiole.h"
#include "Milieu.h"

#include <iostream>
#include <cmath>

#include <fstream>
#include "json.hpp"

Kamikaze::Kamikaze(){}

Kamikaze::~Kamikaze(){}

void Kamikaze::Deplacer(Bestiole& B1,Milieu& milieu){
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

    double dist_min = std::numeric_limits<double>::infinity();
    int position_bestiole_proche = 0;
    for (std::size_t i = 0; i< best_detectés.size();i++){
        if (best_detectés[i]){
            Bestiole* B2 = best_aq[i]; 
            double tmp = pow((B1.get_x() - (*B2).get_x()),2) + pow((B1.get_y() - (*B2).get_y()),2) ; 
            if (tmp<dist_min){
                dist_min = tmp;
                position_bestiole_proche = i;
            }
        }
    }

    double dx = B1.get_x() - (*best_aq[position_bestiole_proche]).get_x();
    double dy = B1.get_y() - (*best_aq[position_bestiole_proche]).get_y();

    if (dx != 0 || dy!= 0 ){
        B1.setOrientation(std::atan2(dy,dx) * 180 / M_PI);
        int multiplicateur = j["Kamikaze"]["multiplicateur_vit_kamikaze"];
        B1.setVitesse(B1.getVitesse() * multiplicateur);
    }
}

