#ifndef KAMIKAZE
#define KAMIKAZE

#include "IComportement.h"
#include "Bestiole.h"
#include "Milieu.h"


class Kamikaze{
    public :
        void Deplacer(Bestiole& Bestiole, Milieu& milieu);
};

#endif