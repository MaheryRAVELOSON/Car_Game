/**
 * @file Sdl.h
 * @author p2207683 p2003422
 * @brief Ce fichier contient l'entête de la classe Jeu
 * @version 0.1
 * @date 2023-03-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SDL_H
#define SDL_H

#include <SDL.h>
#include "Voiture.h"
#include "Obstacle.h"
#include <stdlib.h>     /* abs */
#include <iostream>
#include <cassert>
#include <fstream>

#include <SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "Jeu.h"

using namespace std;


//_____________________________________________________________________________________
/**
 * @brief Cette classe s'occupe de l'affiche de la voiture, des obstacle
 * et du score.
 * \n "texture_V" et "texture_V2" sont des données membres de type pointeur de
 * SDL_Texture qui sont utilisé pour afficher les deux images de la voiture.
 * \n "texture_Obs" est un donnée membre de type pointeur de SDL_Texture qui est utilisé
 * pour afficher l'image pour les obstacles.
 * \n "texture_R0", "texture_R1", "texture_R2", "texture_R3" ont des données membres de
 * type pointeur de SDL_Texture qui sont utilisé pour afficher les quatres images de la route.
 * \n "Indice_Texture_R": un int qui se balade entre 0 inclus et 3 inclus et qui décide
 * quelle image de la route on affiche sur l'écran pour avoir un effet de route qui défile.
 * 
 */
class Sdl
{
    public:
        Jeu JEU;

        SDL_Window *fenetre;
        SDL_Renderer *Rendu;
        SDL_Surface *surface;

        SDL_Texture* texture_V;
        SDL_Texture* texture_V2;
        SDL_Texture* texture_Obs;
        SDL_Texture* texture_R0;
        SDL_Texture* texture_R1;
        SDL_Texture* texture_R2;
        SDL_Texture* texture_R3;
        int Indice_Texture_R;
        Mix_Music* music;

        SDL_Color textColor;
        TTF_Font* font ;
        SDL_Texture* textTexture;
        SDL_Rect textRect;
        SDL_Surface* textSurface ;


//_____________________________________________________________________________
        /**
         * @brief Ce constructeur initialise toute les donnée membres de la classe
         * SDL autre que le donnée membre "JEU"
         * 
         */
        Sdl();

//_____________________________________________________________________________
        /**
         * @brief Ce destructeur désalloue toute les mémoire alloué par les
         * données membres de type pointeur.
         * \n Remarque: à part les données membres "JEU", "textColor", "textRect"
         * toute les autres données membre de la classe SDL sont de type pointeur.
         * 
         */
        ~Sdl();


//_____________________________________________________________________________
        /**
         * @brief Il fait la mis à jours de la fenêtre SDL
         */
        void MAJ_SDL();

//_____________________________________________________________________________
        /**
         * @brief Il va appeller en boucle la fonction de la mis à jour de
         * l'affichage jusqu'à ce que l'utilisateur décide de fermer la fenêtre
         * du jeu. Il traite
         * aussi tout les évènements du clavier

         */
        void afficherBoucle();

//_____________________________________________________________________________
        /**
         * @brief cettre procédure ne fait qu'appeller la procédure "afficherBoucle"
         */
        void afficher();
};



#endif