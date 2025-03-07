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
main : main.cpp Aquarium.o Bestiole.o Milieu.o
	$(CC) $(CFLAGS) -o main main.cpp Aquarium.o Bestiole.o Milieu.o $(INCLUDES) $(LDFLAGS)

Aquarium.o : Aquarium.h Aquarium.cpp
	$(CC) $(CFLAGS) -c Aquarium.cpp $(INCLUDES)

Bestiole.o : Bestiole.h Bestiole.cpp
	$(CC) $(CFLAGS) -c Bestiole.cpp $(INCLUDES)

Milieu.o : Milieu.h Milieu.cpp
	$(CC) $(CFLAGS) -c Milieu.cpp $(INCLUDES)

clean:
	rm -rf *.o main