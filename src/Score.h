/**
 * @file Score.cpp
 * @author P2207683 P2003422
 * @brief Cette fichier contient l'entête de la classe Score
 * @version 0.1
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SCORE_H
#define SCORE_H

/**
 * @brief La classe Score ne contient qu'un seul donnée membre publique "score"
 * qui est un entier qui contiendra le temps écoulé en seconde depuis le
 * lancement du jeu.
 * 
 */
class Score
{
    public:
        int score;

//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise la donnée membre "score" à 0;
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
