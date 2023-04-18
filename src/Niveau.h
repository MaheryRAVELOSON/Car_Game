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
        float N1_Deplacement;
        float N2_Deplacement;
        int Total_Obstacle;
        int * N2_Tab_Direction;
//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise le donnée membre "Deplacement_Niveau"
         * 
         */
        Niveaux(int Nbr_Obstacle);

//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise le donnée membre "Deplacement_Niveau"
         * 
         */
        ~Niveaux();
//_____________________________________________________________________________
        /**
         * @brief Ce procédure bouge toute les obstacle verticalement vers le
         * bas
         * 
         */
        void N1_Mouv_Verticale(Obstacle &Obs);

//_____________________________________________________________________________
        /**
         * @brief Ce procédure bouge toute les obstacle verticalement vers le
         * bas
         * 
         */
        void N2_Mouv_Horizontale(Obstacle &Obs, int TailleEcranX, int Niveau_Joueur);
};

#endif
