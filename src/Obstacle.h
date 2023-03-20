/**
 * @file Obstacle.h
 * @author p2207683 p2003422
 * @brief ce fichier contient l'entête de la classe Obstacle
 * @version 0.1
 * @date 2023-03-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

#include "Position.h"

using namespace std;


//_____________________________________________________________________________
/**
 * @brief La classe obstacle contient quatres données membre: 
 * \n Un pointeur de tableau de position "Tab_Obstacle" qui contiendra les
 * coordonnées de chaque obstacles.
 * \n Un pointeur d'entier "Niveau_Obstacle" qui pointera vers le donnée
 * membres "Niveau" de la classe Jeu.
 * \n Un pointeur d'entier "TailleEcranX_Obstacle" qui pointera vers le donnée
 * membres "TailleX" de la classe Jeu.
 * \n Un pointeur d'entier "Distance_Obstacle" qui pointera vers le donnée
 * membres "Rayon" de la donnée membre classe Position de la donnée membre
 * classe Voiture de la classe Jeu.
 * \n Un pointeur d'entier "Score_Obstacle" qui pointera vers le donnée
 * membres "Score_Joueur" de la classe Jeu.
 * 
 */
class Obstacle
{
    public:
        Position * Tab_Obstacle;
        int * Niveau_Obstacle;
        int * TailleEcranX_Obstacle;
        int * Distance_Obstacle;
        int * Score_Obstacle;
        int TailleTab_Obstacle;

//_____________________________________________________________________________
        /**
         * @brief Ce constructeur pointe le "Niveau_Obstacle", 
         * "TailleEcranX_Obstacle", "Distance_Obstacle" et "Score_Obstacle" à
         * nullptr et alloue un tableau de Position de une ligne , et par
         * défaut, de 20 colonne si on ne lui passe pas en paramettre une autre
         * entier.
         * 
         * @param TailleTab: un entier qui correspondra au nombre de case du
         * tableau de Position à alloué
         */
        Obstacle(int TailleTab=20);

//_____________________________________________________________________________
        void Init_Obstacle();

//_____________________________________________________________________________
        void Mouv_Obs_Verticale();

//_____________________________________________________________________________
        void Verif_Apparition();

//_____________________________________________________________________________
        void TestRegression();

//_____________________________________________________________________________
        /**
         * @brief Ce destructeur désalloue toute les cases mémoires alloué par
         * la donnée membre Tab_Obstacle
         * 
         */
        ~Obstacle();


};

#endif