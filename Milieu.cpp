#include "Milieu.hpp"
#include <algorithm>

Milieu::Milieu(int l, int w) : longueur(l), largeur(w) {}

Milieu::~Milieu() {
    for (auto b : bestioles) {
        delete b;
    }
}

void Milieu::AjouterBestiole(Bestiole* b) {
    bestioles.push_back(b);
}

void Milieu::eliminerBestiole(Bestiole* b) {
    bestioles.erase(std::remove(bestioles.begin(), bestioles.end(), b), bestioles.end());
    delete b;
}

void Milieu::Maj() {
    for (auto b : bestioles) {
        if (b->clonage() && b->Deplacer()) {
            
        }
    }
}
