#pragma once
#include "Comportement.h"
#include "Bestiole.h"
#include "Milieu.h"

class Gregaire : public Comportement {
public:
    Gregaire();
    virtual ~Gregaire();

    void deplacer(Bestiole & b, Milieu & env) override;
};
