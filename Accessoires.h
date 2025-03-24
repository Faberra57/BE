#ifndef _ACCESS_
#define _ACCESS_

#include <iostream>

// Interface Accessoire qui déclare uniquement la méthode setParam
class Accessoires {
public:
    virtual ~Accessoires() {}
    virtual void setParam(float vitesse, float boost_max) = 0;
};

#endif