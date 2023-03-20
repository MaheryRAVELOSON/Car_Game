/**
 * @file Jeu.h
 * @author P2207683 P2003422
 * @brief Ce fichier contient l'entête de la classe Jeu
 * @version 0.1
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef JEU_H
#define Jeu_H
#include "Voiture.h"
#include "Score.h"
#include "Sdl.h"
#include "Obstacle.h"

/**
 * @brief La classe Jeu va mettre en relation toutes les classes nécessaires 
 * pour le jeu. 
 * Il contient une donnée membre TailleX et TailleY qui correspondent à la 
 * taille de l'écran de l'affichage , et une variable de type classe Voiture.
 */
class Jeu
{
    public:
        int TailleX, TailleY, Niveau;
        Voiture * Ptr_Voiture;
        Score * Score_Joueur;
        Sdl S_D_L;
        Obstacle Obs;
        

//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise les données membres "TailleX" & 
         * "TailleY" par défaut à 600*800 si on ne donne pas de paramettre
         * lors de son appelle;
         */
        Jeu(int X=600, int Y=800);

//_____________________________________________________________________________
        /**
         * @brief Ce déstructeur Ddésalloue les allocations alloués par la
         *  donnée membre "Ptr_Voiture"
         */
        ~Jeu();        


//_____________________________________________________________________________
        /**
         * @brief Cette fonction teste si les données membres ont  bien été
         * initialisés à 400.
         */
        void TestRegression();
};
//_____________________________________________________________________________

#endif
