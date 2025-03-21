#pragma once
#include "Comportement.h"
#include "Bestiole.h"
#include "Milieu.h"

class Prevoyant : public Comportement {
public:
    Prevoyant();
    virtual ~Prevoyant();

    void deplacer(Bestiole & b, Milieu & env) override;
};
