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
        //bool * N3_Tab_Agrandissement;
        float N3_Modif_Max;
        float * N3_Tab_Etat_de_Modif;
        float N3_Taux_Modif;
        bool N3_retrecissement;
        bool N3_Premier_Boucle;
        int N3_Etat_de_Modif;
        bool N3_Pair;
        //float N3_Opposee_N3_Etat_de_Modif;
        float N3_Hauteur_Min_Obstacle;

//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise le donnée membre "Deplacement_Niveau"
         * 
         */
        Niveaux(int Nbr_Obstacle, float H_Obstacle);

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
//_____________________________________________________________________________
        /**
         * @brief Ce procédure retrecis UN obstacle donnée en paramettre
         * @param Pos: un donnée résultat de type position dont la surface qu'il
         * occupe sera retrecis
         * 
         */
        void N3_Retrecissement(Obstacle &Obs, int Indice_Pos);
//_____________________________________________________________________________
        /**
         * @brief Ce procédure agrandis UN obstacle donnée en paramettre
         * @param Pos: un donnée résultat de type position dont la surface qu'il
         * occupe sera agrandis
         * 
         */
        void N3_Agrandissement(Obstacle &Obs, int Indice_Pos);

//_____________________________________________________________________________
        void N3_Modif_Des_Coords(Obstacle &Obs, int Niveau_Joueur);

};

#endif
