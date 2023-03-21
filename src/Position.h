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
        float X1;
        float Y1;
        float X2;
        float Y2;
        float CentreX;
        float CentreY;
        float Rayon; //distance entre un pair de XY et le centre
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
        void setRayon(float n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre X1
         * 
         * @param n : un int qui contient la nouvelle valeur de X1.
         */
        void setX1(float n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre Y1
         * 
         * @param n : un int qui contient la nouvelle valeur de Y1.
         */
        void setY1(float n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre X2
         * 
         * @param n : un int qui contient la nouvelle valeur de X2.
         */
        void setX2(float n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre Y2
         * 
         * @param n : un int qui contient la nouvelle valeur de Y2.
         */
        void setY2(float n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre CentreX
         * 
         * @param n : un int qui contient la nouvelle valeur de CentreX.
         */
        void setCentreX(float n);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet de modifier la valeur de la donnée
         * membre CentreY
         * 
         * @param n : un int qui contient la nouvelle valeur de CentreY.
         */
        void setCentreY(float n);
//_____________________________________________________________________________
        /**
        * @brief cette fonction renvoie la valeur de la donnée membre X1
        * @return X1: entier : la fonction retourne la valeur du donnée membre 
        * X1
        */
        float getX1();
//_____________________________________________________________________________
        /**
        * @brief cette fonction renvoie la valeur de la donnée membre X2
        * @return X2: entier : la fonction retourne la valeur du donnée membre 
        * X2
        */
        float getX2();
//_____________________________________________________________________________
        /**
        * @brief cette fonction renvoie la valeur de la donnée membre Y1
        * @return Y1: entier : la fonction retourne la valeur du donnée membre 
        * Y1
        */
        float getY1();
//_____________________________________________________________________________
        /**
        * @brief cette fonction renvoie la valeur de la donnée membre Y2
        * @return Y2: entier : la fonction retourne la valeur du donnée membre 
        * Y2
        */
        float getY2();

//_____________________________________________________________________________
        /**
         * @brief cette fonction renvoie la valeur de la donnée membre CentreX
         * 
         * @return CentreY: entier : la fonction retourne la valeur du donnée
         * membre CentreX
         */
        float getCentreX();

//_____________________________________________________________________________
        /**
         * @brief cette fonction renvoie la valeur de la donnée membre CentreY
         * 
         * @return CentreY: entier : la fonction retourne la valeur du donnée
         * membre CentreY
         */
        float getCentreY();

//_____________________________________________________________________________
        /**
         * @brief cette fonction renvoie la valeur de la donnée membre Rayon
         * 
         * @return Rayon: entier : la fonction retourne la valeur du donnée
         * membre Rayon
         */
        float getRayon();

//_____________________________________________________________________________
        /**
         * @brief Cette procédure teste le maximum de fonction membre de la
         * classe Position.
         * 
         */
        void TestRegression();

};
//_____________________________________________________________________________

#endif
