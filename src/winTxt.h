/**
 * @file winTxt.h
 * @author p2207683 p2003422
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef WINTXT_H
#define WINTXT_H


/**
 * @brief Cette classe permet de stocker des caractères dans un tableau en 2D
 * alloué. Il a 3 donnée membre deux entiers dimx et dimy qui correspond à la
 * taille du tableau; puis une pointeur de tableau de caractère qui va allouer
 * un tableau de taille dimx*dimy
 * 
 */
class WinTXT
{
private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief heuteur
    char* win;      //!< \brief stocke le contenu de la fen�tre dans un tableau 1D mais on y accede en 2D

public:

//_____________________________________________________________________________    
        /**
         * @brief Ce constructeur permet d'allouer, à travers le donné membre "win"
         * qui est de type pointeur, un tableau de caractère (de
         * 1D mais qu'on manipule comme un 2D) de dx ligne et dy colonne.
         * 
         * @param dx: un entier qui correspondra au nombre de ligne du tableau
         * @param dy: un entier qui correspondra au nombr de colonne de chaque
         * ligne du tableau.
         */
        WinTXT (int dx, int dy);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure permet d'éffacer la fentre du jeu dans le
         * terminal donc de remplir tout les cases du pointeur de tableau de
         * caractère par un ESPACE. pour cela il appelle la procedure "print"
         * 
         * @param c: un char à laquelle va corréspondre chaque case de toute le
         * tableau de caractère: par défaut il contient un ESPACE si on appelle
         * la procédure sans paramètre.
         */
        void clear (char c=' ');

//_____________________________________________________________________________
        /**
         * @brief cette procédure permet de modifié le contenu d'une case
         * d'indice donnée
         * 
         * @param x: un entier: la ligne du tableau
         * @param y: un entier: la colonne du tableau 
         * @param c: un char: le nouveau caractère avec laquelle on va remplacé
         * l'ancien.
         */
        void print (int x, int y, char c);

//_____________________________________________________________________________
    void print (int x, int y, char* c);
//_____________________________________________________________________________
    void draw (int x=0, int y=0);
//_____________________________________________________________________________
    void pause();
//_____________________________________________________________________________
    char getCh();

};


//_____________________________________________________________________________
/**
 * @brief Cette fonction permet d'effacer le terminal
 * 
 */
void termClear ();

#endif
