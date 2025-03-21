#ifndef MILIEU_H
#define MILIEU_H

#include <vector>
#include "Bestiole.hpp"

class Milieu {
private:
    int longueur;
    int largeur;
    std::vector<Bestiole*> bestioles;

public:
    Milieu(int l, int w);
    ~Milieu();

    void AjouterBestiole(Bestiole* b);
    void eliminerBestiole(Bestiole* b);
    void Maj();
};

#endif // 
