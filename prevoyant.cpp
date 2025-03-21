#include "Prevoyant.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <vector>
#include <cmath>

Prevoyant::Prevoyant() {}
Prevoyant::~Prevoyant() {}

void Prevoyant::deplacer(Bestiole & b, Milieu & env) {
    std::vector<Bestiole*> toutesB = env.getBestioles();

    std::vector<bool> bestiolesDetectables = b.detection(env);

    const double tempsProjection = 5.0;
    const double seuilCollision = 30.0;

    double future_x = b.getPositionX() + std::cos(b.getOrientation()) * b.getVitesse() * tempsProjection;
    double future_y = b.getPositionY() + std::sin(b.getOrientation()) * b.getVitesse() * tempsProjection;

    double evasion_x = 0.0, evasion_y = 0.0;

    for (size_t i = 0; i < toutesB.size(); ++i) {
        if (!bestiolesDetectables[i] || toutesB[i] == &b) continue;  // On ignore les non-détectées et soi-même

        Bestiole* voisin = toutesB[i];

        double voisin_future_x = voisin->getPositionX() + std::cos(voisin->getOrientation()) * voisin->getVitesse() * tempsProjection;
        double voisin_future_y = voisin->getPositionY() + std::sin(voisin->getOrientation()) * voisin->getVitesse() * tempsProjection;

        double dist_x = future_x - voisin_future_x;
        double dist_y = future_y - voisin_future_y;
        double distance = std::sqrt(dist_x * dist_x + dist_y * dist_y);

        if (distance < seuilCollision) {
            evasion_x += dist_x / distance; // Normalisation du vecteur
            evasion_y += dist_y / distance;
        }
    }

    if (evasion_x != 0 || evasion_y != 0) {
        double nouvelleOrientation = std::atan2(-evasion_x, evasion_y); // Rotation de +90°
        b.setOrientation(nouvelleOrientation);
    }

}
