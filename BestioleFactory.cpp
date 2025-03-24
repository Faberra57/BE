#include "BestioleFactory.h"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

#include <cstdlib>   // rand()
#include <iostream>

BestioleFactory::BestioleFactory() {
    id_counter = 0;

    std::ifstream inputFile("param.json");
    if (!inputFile.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier!" << std::endl;
        return;
    }
    nlohmann::json j;
    inputFile >> j;
    RESISTANCE_MAX = j["Simulation"]["RESISTANCE_MAX"];
    REDUCTION_RESISTANCE = j["Simulation"]["REDUCTION_RESISTANCE"];
    PROBA_GRÉGAIRE = j["Simulation"]["PROBA_GRÉGAIRE"];
    PROBA_KAMIKAZE = j["Simulation"]["PROBA_KAMIKAZE"];
    PROBA_PEUREUSE = j["Simulation"]["PROBA_PEUREUSE"];
    PROBA_PRÉVOYANTE = j["Simulation"]["PROBA_PRÉVOYANTE"];
    PROBA_MULTIPLE = j["Simulation"]["PROBA_MULTIPLE"];
    PROBA_OREILLE = j["Simulation"]["PROBA_OREILLE"];
    PROBA_YEUX = j["Simulation"]["PROBA_YEUX"];
    PROBA_NAGEOIRE = j["Simulation"]["PROBA_NAGEOIRE"];
    PROBA_CARAPACE = j["Simulation"]["PROBA_CARAPACE"];
    PROBA_CAMOUFLAGE = j["Simulation"]["PROBA_CAMOUFLAGE"];
    VITESSE_MAX = j["Simulation"]["VITESSE_MAX"];
    AGE_MAX = j["Simulation"]["AGE_MAX"];
    TAILLE = j["Simulation"]["TAILLE"];
    DETECTABILITE_MAX = j["Simulation"]["DETECTABILITE_MAX"];
}

Bestiole* BestioleFactory::CreerBestiole() {
    int id = id_counter++;
    double vitesse = (rand() % VITESSE_MAX);
    double x = rand() % 100;
    double y = rand() % 100;
    double orientation = (rand() % 360) * 3.14159 / 180;
    double taille = TAILLE;
    int age_limite = rand() % AGE_MAX;
    double resistance = (rand() % RESISTANCE_MAX);
    double detectabilite = (rand() % DETECTABILITE_MAX);

    return new Bestiole(id, vitesse, x, y, orientation, taille, age_limite, resistance, detectabilite);
}
