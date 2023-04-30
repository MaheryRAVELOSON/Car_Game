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

#include <unistd.h>

#include "Position.h"
#include "Score.h"
#include "Voiture.h"

using namespace std;


//_____________________________________________________________________________
/**
 * @brief La classe obstacle contient quatres données membres: 
 * \n Un pointeur de tableau de position "Tab_Obstacle" qui contiendra les
 * coordonnées de chaque obstacles.
 * \n Un entier "Distance_Obstacle" qui contiendra la distance minimum entre deux
 * obstacle pour la voiture puisse passé.
 * \n Un entier "TailleTab_Obstacle" qui va stocker
 * la taille du tableau qu'on alloue.
 * \n un bool "passage_possible" qui passe sur true si, une fois qu'un obstacle
 * est créer, la voiture a assez de couloir pour l'éviter et peut donc passer.
 * \n Un réel "Deplacement_Obstacle" qui sera le déplacement de chaque obstacle.
 * 
 * \n !!!!REMARQUE!!!! Dans la classe Obstacle, on ne manipule plus CentreX, Y
    et le Rayon de la Position mais directement les X et Y avec leur set et get
 * 
 */
class Obstacle
{
    public:
        Position * Tab_Obstacle;
        int Distance_Obstacle;
        int TailleTab_Obstacle;
        bool passage_possible;

//_____________________________________________________________________________
        /**
         * @brief Ce constructeur alloue un tableau de Position de une ligne , et
         * de "TailleTab_Obstacle" colonne, qui sera par défaut, égale à 20 si on
         * ne lui passe pas en parametre un autre entier.
         * il initialise  le "passage_possible" à false.
         * "Distance_Obstacle" sera par défaut égale à la donnée membre "Rayon" de
         * la donnée membre classe Position de la donnée membre classe Voiture de la
         * classe Jeu.
         * le "Deplacement_Obstacle" qui sera par défaut à 0.2
         * @param TailleTab: un entier qui correspondra au nombre de case du
         * tableau de Position à alloué
         * @param RayonVoiture: un entier qui correspondra au donnée membre "rayon"
         * de la Voiture qui est lui une donné membre de la classe Jeu.
         * @param Deplacement_Voiture: un entier qui correspondra au donnée membre
         * "Deplacement" de la Voiture qui est lui une donné membre de la classe Jeu.
         */
        Obstacle(int TailleTab=20, int Largeur_Voiture=0, int Deplacement_Voiture=0);

//_____________________________________________________________________________
        /**
         * @brief cette procédure crée des coordonnées pour chaque case du tableau
         * d'obstacle.
         * @param TailleEcranX: un entier qui sera égale à la donnée membre "TailleX"
         * de la classe jeu 
         */
        void Init_Obstacle(int TailleEcranX);

//_____________________________________________________________________________
        /**
         * @brief Cette fonction verifie si chaque obstacle sont encore visible
         * dans l'écran. Sinon il donne une nouvelle coordonnée.
         * @param TailleEcranX: un entier qui sera égale à la donnée membre "TailleX"
         * de la classe jeu
         * @param TailleEcranY: un entier qui sera égale à la donnée membre "TailleY"
         * de la classe jeu
         * @return il renvoie le nombre d'obstacle qui ne sont plus visible sur
         * l'écran
         */
        int Verif_Apparition(Score &Score_Joueur, int TailleEcranX, int TailleEcranY,
        float * N3_Tab_Etat_de_Modif);

//_____________________________________________________________________________
        /**
         * @brief Ce destructeur désalloue toutes les cases mémoires allouées par
         * la donnée membre Tab_Obstacle
         * 
         */
        ~Obstacle();

//_____________________________________________________________________________
        bool Collision(Voiture &Voiture_Joueur);


};

#endif