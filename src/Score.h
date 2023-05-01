/**
 * @file Score.h
 * @author P2207683 P2003422
 * @brief Ce fichier contient l'entête de la classe Score
 * @version 0.2
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SCORE_H
#define SCORE_H

/**
 * @brief La classe Score contient deux données membres publics:
 * \n "score": un int qui s'incrémente à chaque fois qu'un obstacle
 * arrive en bas de l'écran.
 * \n "score_Majoree": un int qui s'incrémente en même temps que la
 * "score" mais qu'on remet à 0 dès qu'il est plus grand ou égale à 3.
 * Il sert à augmenter les déplacements/vitesse des obstacle tout les 
 * 3 obstacles passé dès qu'on est au niveau 3 du jeu.
 * 
 */
class Score
{
    public:
        int score;
        int score_Majoree;

//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise les données membres "score" et 
         * "score_Majoree" à 0;
         * 
         */
        Score();


//_____________________________________________________________________________
        /**
         * @brief Cette fonction teste si la donnée membre score a bien été
         * initialisé à 0
         * 
         */
        void TestRegression();
};
//_____________________________________________________________________________

#endif
