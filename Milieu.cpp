#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

Milieu::Milieu(int l, int w) : UImg( l, w, 1, 3 ),longueur(w), largeur(l),bestioles(){}

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

void Milieu::Step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole*>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
   {
      (*it)->action(*this);
      (*it)->draw(*this);
   }

}

std::vector<Bestiole*> Milieu::getBestioles() const{
    return (*this).bestioles;
}
