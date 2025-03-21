#ifndef ICOMP
#define ICOMP

#include "Bestiole.h"


class IComportement{
    public : 
        virtual void Deplacer()=0;
        virtual ~IComportement(){};

};
#endif