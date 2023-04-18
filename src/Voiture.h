/**
 * @file Voiture.h
 * @author P2207683 P2003422
 * @brief Ce fichier contient l'entête de la classe Voiture
 * @version 0.1
 * @date 2023-03-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef VOITURE_H
#define VOITURE_H

#include "Position.h"
//_____________________________________________________________________________


/**
 * @brief La classe voiture contient un donnée membre Position et un donnée
 * membre Deplacement qui est une variable qui décide de combien de pixel se
 * déplace la voiture dès que l'utilisateur appuie sur une touche.
 * 
 */
class Voiture
{
    private:
    /* data */
    public:
        Position * Voiture_Position;
        int Deplacement;

//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise la position de la voiture par
         * rapport au taille de l'écran
         * 
         * @param TailleEcranX: un entier qui correspond au largeur de l'écran
         * @param TailleEcranY: un entier qui correspond au longueur de l'écran
         */
        Voiture(int TailleEcranX, int TailleEcranY); 

//_____________________________________________________________________________
        /**
         * @brief Ce déssructeur désaloue tous les allocations des données
         * membres dans le tas.
         * 
         */
        ~Voiture();

//_____________________________________________________________________________
        /**
         * @brief Cette fonction permet de déplacer la voiture vers la gauche
         * 
         */
        void Deplacer_Gauche();


//_____________________________________________________________________________
        /**
         * @brief Cette fonction permet de déplacer la voiture vers la droite
         * 
         * @param TailleEcranX: un entier qui correspond au largeur de l'écran
         */
        void Deplacer_Droite(int TailleEcranX);


//_____________________________________________________________________________
        /**
         * @brief Cette fonction permet de déplacer la voiture vers le haut. Il
         * ne sera disponible que quand le joueur arrive au niveau 2.
         * 
         * @param Niveau: un entier qui correspond au niveau actuel du joueur
         */
        void Deplacer_Haut(int Niveau);


//_____________________________________________________________________________        
       /**
         * @brief Cette fonction permet de déplacer la voiture vers le bas. Il
         * ne sera disponible que quand le joueur arrive au niveau 2.
         * 
         * @param Niveau: un entier qui correspond au niveau actuel du joueur
         * @param TailleEcranY: un entier qui correspond à la hauteur de la
         * fenétre 
         */
        void Deplacer_Bas(int Niveau , int TailleEcranY);




};




#endif