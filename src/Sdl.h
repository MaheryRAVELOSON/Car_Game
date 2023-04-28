/**
 * @file Sdl.h
 * @author p2207683 p2003422
 * @brief 
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
 * et du score. Il a donc trois donné membre qui sont tous des pointeurs
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
        SDL_Texture* texture_R;
        Mix_Music* music;

        SDL_Color textColor;
        TTF_Font* font ;
        SDL_Texture* textTexture;
        SDL_Rect textRect;
        SDL_Surface* textSurface ;


//_____________________________________________________________________________
        /**
         * @brief Ce destructeur pointe toute les pointeur donnée membre sur
         * nullptr
         * 
         */
        Sdl();

//_____________________________________________________________________________
        /**
         * @brief Ce destructeur pointe toute les pointeur donnée membre sur
         * nullptr
         * 
         */
        ~Sdl();


//_____________________________________________________________________________
        /**
         * @brief Il fait la mis à jours de la fenêtre SDL
         * 
         * @param fenetre: un pointeur qui va contenir l'adresse memoire de la
         * fenetre SDL qui a été créée.
         * @param Rendu: un pointeur qui va contenir l'adresse memoire du rendu
         * SDL qui a été créée. 
         */
        void MAJ_SDL();

//_______________________________________________un pointeur de type classe Voiture______________________________
        /**
         * @brief Il va appeller en boucle la fonction de la mis à jour de
         * l'affichage jusqu'à ce que l'utilisateur décide d'arrêter. Il traite
         * aussi tout les évènements du clavier
         * 
         * @param fenetre: un pointeur qui va contenir l'adresse memoire de la
         * fenetre SDL qui a été créée.
         * @param Rendu: un pointeur qui va contenir l'adresse memoire du rendu
         * SDL qui a été créée.
         */
        void afficherBoucle();

//_____________________________________________________________________________
        /**
         * @brief il permet d'appeller la procedure qui initialise SDL, puis
         * la procédure qui appelle en boucle la fonction qui fait la MAJ de
         * l'écran; enfin cette fonction appelle la procedure qui fait les
         * désallocation necessaire fait par les variables SDL
         */
        void afficher();
};



#endif