#include "Bestiole.h"

#include "Milieu.h"

#include "Capteur.h"

#include <cstdlib>
#include <cmath>
#include <vector>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;

#include <cmath>
#include <iostream>

Bestiole::Bestiole(int id, double v, double x, double y, double o, double t, int a_lim, bool vivant, double res, double detect)
    : id(id), vitesse(v), position_x(x), position_y(y), orientation(o), taille(t), age(0),
      age_limite(a_lim), estVivant(vivant), resistance(res), detectabilite(detect), cumulX(0),cumulY(0) {
        couleur = new T[ 3 ];
        couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
        couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
        couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
        std::vector<Capteur*> Capteurs(2, nullptr);
      }

void Bestiole::mort() {
    if (age >= age_limite || resistance <= 0) {
        estVivant = false;
    }
}

Bestiole* Bestiole::clonage() {
    return new Bestiole(*this);
}

void Bestiole::Bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos(orientation)*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = position_x + dx + cx;
   ny = position_y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      position_x = static_cast<int>( nx );
      cumulX += nx - position_x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      position_y = static_cast<int>( ny );
      cumulY += ny - position_y;
   }

}

void Bestiole::Percussion(Bestiole* autre) {
    if (std::abs(position_x - autre->position_x) < 1e-3 &
        std::abs(position_y - autre->position_y) < 1e-3) {

        std::cout << " Collision détectée entre Bestiole #" << id
                  << " et Bestiole " << autre->id << std::endl;

        // réduction de résistance
        resistance -= 10;
        autre->resistance -= 10;
    }
}

double Bestiole::get_x(){
    return (*this).position_x;
}
double Bestiole::get_y(){
    return (*this).position_y;
}
double Bestiole::getVitesse(){
    return (*this).vitesse;
}
double Bestiole::getOrientation(){
    return (*this).orientation;
}
void Bestiole::setOrientation(double o){
    (*this).orientation = o;
}
void Bestiole::setVitesse(double v){
    (*this).vitesse = v;
}

void Bestiole::action( Milieu& monMilieu )
{

   Bouge(monMilieu.getLargeur(), monMilieu.getLongueur());

}


void Bestiole::draw( UImg & support )
{

   double         xt = position_x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = position_y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( position_x, position_y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}

std::vector<bool> Bestiole::Detection(Milieu& monMilieu){
    std::vector<Bestiole*> listeBestiole = monMilieu.getBestioles();
    std::vector<Capteur*> listeCapteurs = Capteurs;

    std::vector<bool> boolDetection(listeBestiole.size(),false);

    for (Capteur* capt:listeCapteurs){
        if (capt!=nullptr){
            std::vector<bool> detection = capt->detecter(monMilieu);
            for (size_t i = 0; i < boolDetection.size(); ++i) {
                if (!boolDetection[i] && detection[i]) {
                    boolDetection[i] = true;
                }
            }
        }
    }

    return boolDetection;
}
