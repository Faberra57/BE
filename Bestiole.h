#ifndef BESTIOLE_H
#define BESTIOLE_H

class Bestiole {
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

public:
    Bestiole(int id, double v, double x, double y, double o, double t, int a_lim, bool vivant, double res, double detect);
    ~Bestiole() = default;

    void mort();         
    Bestiole* clonage();  
    void Deplacer();     
    void Percussion(Bestiole* autre);  
};

#endif // 
