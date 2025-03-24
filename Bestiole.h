#ifndef BESTIOLE_H
#define BESTIOLE_H

#include "UImg.h"
#include "Capteur.h"
#include "IComportement.h"


#include <iostream>

using namespace std;

class Milieu;

class Bestiole {
    private :
    static const double     AFF_SIZE;
    static const double     MAX_VITESSE;
    static const double     LIMITE_VUE;

    static int              next;

private:
    int id;
    double vitesse;
    double position_x;
    double position_y;
    double orientation;
    double taille;
    int age;
    int age_limite;
    bool estVivant;
    double resistance;
    double detectabilite;
    std::vector<Capteur*> Capteurs; //premier élément : Yeux, deuxième : Oreilles

    double            cumulX, cumulY;

    T               * couleur;

    IComportement* comportement;


public:
    Bestiole();
    Bestiole(int id, double v, double x, double y, double o, double t, int a_lim, bool vivant, double res, double detect , int comportement);
    Bestiole( const Bestiole & b );
    ~Bestiole() = default;

    void mort();         
    Bestiole* clonage();  
    void Bouge(int larg_max,int longueur_max);     
    void Percussion(Bestiole* autre);
    double get_x() const;
    double get_y() const;
    double getOrientation() const;
    double getVitesse() const;
    void setOrientation(double o);
    void setVitesse(double v);
    void setDetectabilite(double phi);

    std::vector<bool> Detection(Milieu& monMilieu);


    void action( Milieu & monMilieu );
    void draw( UImg & support );
  
};

#endif // 
