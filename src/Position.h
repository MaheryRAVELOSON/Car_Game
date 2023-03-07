/**
 * @file Position.h
 * @author P2207683 P2003422
 * @brief Ce fichier contient l'entête de la classe Position
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef POSITION_H
#define POSITION_H
//_____________________________________________________________________________
/**
 * @brief Cette classe contient les coordoné d'une position et les fonctions
 * membre qui permettent de les manipuler
 * 
 */
class Postion
{
    private:
        int X1;
        int Y1;
        int X2;
        int Y2;
        int Centre;
    public:
//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise tout les donnée membres à 0.
         * 
         */
        Postion();
//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre X1
         * 
         * @param n : un int qui contient la nouvelle valeur de X1.
         */
        void setX1(int n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre Y1
         * 
         * @param n : un int qui contient la nouvelle valeur de Y1.
         */
        void setY1(int n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre X2
         * 
         * @param n : un int qui contient la nouvelle valeur de X2.
         */
        void setX2(int n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre Y2
         * 
         * @param n : un int qui contient la nouvelle valeur de Y2.
         */
        void setY2(int n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre Centre
         * 
         * @param n : un int qui contient la nouvelle valeur de Centre.
         */
        void setCentre(int n);
//_____________________________________________________________________________
        /**
        * @brief cette fonction erenvoie la valeur de la donnée membre X1
        * @return X1: entier : la fonction retourne la valeur du donnée membre 
        * X1
        */
        int getX1();
//_____________________________________________________________________________
        /**
        * @brief cette fonction erenvoie la valeur de la donnée membre X2
        * @return X2: entier : la fonction retourne la valeur du donnée membre 
        * X2
        */
        int getX2();
//_____________________________________________________________________________
        /**
        * @brief cette fonction erenvoie la valeur de la donnée membre Y1
        * @return Y1: entier : la fonction retourne la valeur du donnée membre 
        * Y1
        */
        int getY1();
//_____________________________________________________________________________
        /**
        * @brief cette fonction erenvoie la valeur de la donnée membre Y2
        * @return Y2: entier : la fonction retourne la valeur du donnée membre 
        * Y2
        */
        int getY2();

};
//_____________________________________________________________________________

#endif
