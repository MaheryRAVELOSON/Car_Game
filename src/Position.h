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
class Position
{
    private:
        int X1;
        int Y1;
        int X2;
        int Y2;
        int CentreX;
        int CentreY;
        int Rayon; //distance entre un pair de XY et le centre
    public:
//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise tout les donnée membres à 0.
         * 
         */
        Position();

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre Rayon
         * 
         * @param n : un int qui contient la nouvelle valeur de Rayon.
         */
        void setRayon(int n);

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
         * membre CentreX
         * 
         * @param n : un int qui contient la nouvelle valeur de CentreX.
         */
        void setCentreX(int n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre CentreY
         * 
         * @param n : un int qui contient la nouvelle valeur de CentreY.
         */
        void setCentreY(int n);
//_____________________________________________________________________________
        /**
        * @brief cette fonction renvoie la valeur de la donnée membre X1
        * @return X1: entier : la fonction retourne la valeur du donnée membre 
        * X1
        */
        int getX1();
//_____________________________________________________________________________
        /**
        * @brief cette fonction renvoie la valeur de la donnée membre X2
        * @return X2: entier : la fonction retourne la valeur du donnée membre 
        * X2
        */
        int getX2();
//_____________________________________________________________________________
        /**
        * @brief cette fonction renvoie la valeur de la donnée membre Y1
        * @return Y1: entier : la fonction retourne la valeur du donnée membre 
        * Y1
        */
        int getY1();
//_____________________________________________________________________________
        /**
        * @brief cette fonction renvoie la valeur de la donnée membre Y2
        * @return Y2: entier : la fonction retourne la valeur du donnée membre 
        * Y2
        */
        int getY2();

//_____________________________________________________________________________
        /**
         * @brief cette fonction renvoie la valeur de la donnée membre CentreX
         * 
         * @return CentreY: entier : la fonction retourne la valeur du donnée
         * membre CentreX
         */
        int getCentreX();

//_____________________________________________________________________________
        /**
         * @brief cette fonction renvoie la valeur de la donnée membre CentreY
         * 
         * @return CentreY: entier : la fonction retourne la valeur du donnée
         * membre CentreY
         */
        int getCentreY();

//_____________________________________________________________________________
        /**
         * @brief cette fonction renvoie la valeur de la donnée membre Rayon
         * 
         * @return Rayon: entier : la fonction retourne la valeur du donnée
         * membre Rayon
         */
        int getRayon();

};
//_____________________________________________________________________________

#endif
