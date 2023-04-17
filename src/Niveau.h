#ifndef NIVEAU_H
#define NIVEAU_H

#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

#include <unistd.h>

#include "Obstacle.h"

using namespace std;

class Niveaux
{
    public:
        float Deplacement_Niveau;
//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise le donnée membre "Deplacement_Niveau"
         * 
         */
        Niveaux();
//_____________________________________________________________________________
        /**
         * @brief Ce procédure bouge toute les obstacle verticalement vers le
         * bas
         * 
         */
        void Mouv_Verticale(Obstacle &Obs);
};

#endif
