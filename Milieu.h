#ifndef MILIEU_H
#define MILIEU_H

#include <vector>
#include "UImg.h"
#include "Bestiole.h"

class Milieu: public UImg{
private:
    static const T          white[];

    int longueur;
    int largeur;
    std::vector<Bestiole*> bestioles;

public:
    Milieu(int l, int w);
    ~Milieu();

    int getLongueur() const { return longueur; };
    int getLargeur() const { return largeur; };

    void AjouterBestiole(Bestiole* b);
    void eliminerBestiole(Bestiole* b);
    std::vector<Bestiole*> getBestioles();
    void Step();
};

#endif // 
