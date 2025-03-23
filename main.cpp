#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <memory>
#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 20; ++i ){
      Bestiole* ptr_best = new Bestiole();
      ecosysteme.getMilieu().AjouterBestiole(ptr_best);
   }
   ecosysteme.run();


   return 0;

}
