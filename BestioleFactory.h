#ifndef BESTIOLEFACTORY_H
#define BESTIOLEFACTORY_H

#include "Bestiole.h"
#include <map>
#include <string>

class BestioleFactory {
private:
    std::map<std::string, double> liste_taux;  // Probabilité de chaque type de bestiole

public:
    BestioleFactory();  
    ~BestioleFactory() = default;
    
    Bestiole* CreerBestiole();  // Crée une nouvelle bestiole
};

#endif // 
