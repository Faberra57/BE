#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "BestioleFactory.h"


#include <memory>
#include <iostream>

using namespace std;


int main()
{
<<<<<<< HEAD
   int nbBestioles = 20;
=======
   int nbBestioles = 30;
>>>>>>> 8c97d83da87caacef57e8c10ecae2da5d4d67002
   Aquarium       ecosysteme( 640, 480, 30 );
   BestioleFactory* factory = new BestioleFactory();
   for ( int i = 1; i <= nbBestioles; ++i ){
      Bestiole* ptr_best = factory->CreerBestiole();
      ecosysteme.getMilieu().AjouterBestiole(ptr_best);
   }
   ecosysteme.run();


   return 0;

}
