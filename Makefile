# Détection du système d'exploitation
OS := $(shell uname -s)

# Compilation
CC = g++
CFLAGS = -Wall -std=c++11
LDFLAGS = -lX11 -lpthread
INCLUDES = -I .

# Options spécifiques pour macOS
ifeq ($(OS), Darwin)
    CFLAGS = -Wall -std=c++14  # Remplacement pour éviter d'avoir les deux standards
    INCLUDES += -I /opt/X11/include
    LDFLAGS += -L /opt/X11/lib
endif

# Cibles
main : main.cpp Aquarium.o Bestiole.o Milieu.o BestioleFactory.o BestioleCamouflage.o BestioleCarapace.o BestioleNageoire.o BestioleOreille.o BestioleYeux.o gregaire.o Kamikaze.o prevoyant.o Peureuse.o
	$(CC) $(CFLAGS) -o main main.cpp Aquarium.o Bestiole.o Milieu.o BestioleFactory.o BestioleCamouflage.o BestioleCarapace.o BestioleNageoire.o BestioleOreille.o BestioleYeux.o gregaire.o Kamikaze.o prevoyant.o Peureuse.o $(INCLUDES) $(LDFLAGS)
Bestiole.o : Bestiole.h Milieu.h Capteur.h Bestiole.cpp
	$(CC) $(CFLAGS) -c Bestiole.cpp $(INCLUDES)
Milieu.o : Milieu.h Milieu.cpp
	$(CC) $(CFLAGS) -c Milieu.cpp $(INCLUDES)
Aquarium.o : Aquarium.h Aquarium.cpp
	$(CC) $(CFLAGS) -c Aquarium.cpp $(INCLUDES)
BestioleFactory.o : BestioleFactory.h Bestiole.h BestioleFactory.cpp 
	$(CC) $(CFLAGS) -c BestioleFactory.cpp $(INCLUDES)
BestioleCamouflage.o : Accessoires.h Bestiole.h BestioleCamouflage.h BestioleCamouflage.cpp
	$(CC) $(CFLAGS) -c BestioleCamouflage.cpp $(INCLUDES)
BestioleCarapace.o : Accessoires.h Bestiole.h BestioleCarapace.h BestioleCarapace.cpp
	$(CC) $(CFLAGS) -c BestioleCarapace.cpp $(INCLUDES)
BestioleNageoire.o : Accessoires.h Bestiole.h BestioleNageoire.h BestioleNageoire.cpp
	$(CC) $(CFLAGS) -c BestioleNageoire.cpp $(INCLUDES)
BestioleOreille.o : Capteur.h Milieu.h Bestiole.h BestioleOreille.h BestioleOreille.cpp
	$(CC) $(CFLAGS) -c BestioleOreille.cpp $(INCLUDES)
BestioleYeux.o : Capteur.h Milieu.h Bestiole.h BestioleYeux.h BestioleYeux.cpp
	$(CC) $(CFLAGS) -c BestioleYeux.cpp $(INCLUDES)
gregaire.o : IComportement.h Milieu.h Bestiole.h gregaire.h gregaire.cpp
	$(CC) $(CFLAGS) -c gregaire.cpp $(INCLUDES)
Kamikaze.o : IComportement.h Milieu.h Bestiole.h Kamikaze.h Kamikaze.cpp
	$(CC) $(CFLAGS) -c Kamikaze.cpp $(INCLUDES)
prevoyant.o : IComportement.h Milieu.h Bestiole.h Prevoyant.h Prevoyant.cpp
	$(CC) $(CFLAGS) -c prevoyant.cpp $(INCLUDES)
Peureuse.o : IComportement.h Milieu.h Bestiole.h Peureuse.h Peureuse.cpp
	$(CC) $(CFLAGS) -c Peureuse.cpp $(INCLUDES)
clean:
	rm -rf *.o main