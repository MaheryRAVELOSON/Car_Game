/**
 * @file Niveau.h
 * @author P2207683 P2003422
 * @brief Ce fichier contient l'entête de la classe Niveau
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef NIVEAU_H
#define NIVEAU_H

#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

#include <unistd.h>

#include "Obstacle.h"

using namespace std;

/**
 * @brief La classe Niveau s'occupe TOUTE les mouvements qu'on appliques
 * à chaque obstacle, que se soit une déplacement verticale ou horizontale
 * ou le zoom/dezoom.
 * \n "N1_Deplacement": un float qu'on ajoute à chaque Y1 et Y2 de toutes
 * les obstacle pour qu'ils déscende vers le bas;
 * \n "N2_Deplacement": un float qu'on ajoute/enlèves à chaque X1 et X2 de toutes
 * les obstacle pour qu'ils se déplacent soit à gauche, soit à droite.
 * Remarque, à l'initialisation, deux obstacle qui se suivent ne se déplace pas
 * dans la même sens horizontalement.
 * \n "Total_Obstacle": un entier qui correspond au nombre d'obstacle total
 * \n "N2_Tab_Direction": un pointeur de tableau d'entier. il contiendra une
 * fois sur deux soit 1 soit -1. Toutes les obstacles qui a la même indice que
 * les cases qui contiennent 1 se déplacerent vers la droite; les autres iront
 * à gauche à l'initialisation.
 * \n "N3_Taux_Modif": un float constante avec laquelle on va multiplier la variable
 * "N3_Etat_de_Modif" pour gérer l'agrandissement et le retrecissement: pour deux
 * obstacle successif, l'un va grandir et l'autre va retrecir. Par défaut il est
 * égale à "N3_Modif_Max"
 * \n Remarque: la taille minimal de toute les obstacle est la taille initial
 * des obstacle. la taille maximale est "N3_Modif_Max" * "N3_Taux_Modif"
 * \n "N3_Tab_Etat_de_Modif": un pointeur de tableau de float dont chaque
 * case contient le nombre de pixel qu'on a rajouté à chaque obstacle par
 * rapport à la taille initiale des obstacles: soit "N3_Etat_de_Modif" * "N3_Taux_Modif".
 * Remarque: tout les obstacles ont tous la même hauteur initial.
 * \n "N3_retrecissement": un booléen. Si True alors "N3_Etat_de_Modif" va
 * décrémenter de "N3_Modif_Max" vers 0. Sinon il va de 0 à "N3_Modif_Max". Par défaut,
 * il est true. A chaque fois que "N3_Etat_de_Modif" est égale à 0 ou à "N3_Modif_Max",
 * on a fini une cycle alors on change sa contenu par son opposé
 * \n "N3_Premier_Boucle": un boulean qui est initialisé à true qui sera ensuite mis à
 * false durant tout le long du jeu: il sert à executer un bout de code qu'une seule 
 * fois durant tout le jeux: lors de la toute première retrecissement.
 * \n "N3_Etat_de_Modif": un entier qui se balade entre 0 inclus et "N3_Modif_Max" inclus
 * \n "N3_Pair": un bollean par défaut égale à true. Si il est true, alors on
 * agrandit toute les obstacle dont la case est d'indice paire et on rétrecis tout
 * les autres. A chaque fois que "N3_Etat_de_Modif" est égale à 0 ou à "N3_Modif_Max",
 * on a fini une cycle alors on change sa contenu par son opposé.
 * \n "N3_Hauteur_Min_Obstacle": un float qui contient la hauteur initial des obstacles
 * lors du lancement du jeu. Remarque: toute les obstacle ont tous la même hauteurs
 * initial.
 */
class Niveaux
{
    public:
        float N1_Deplacement;
        float N2_Deplacement;
        int Total_Obstacle;
        int * N2_Tab_Direction;
        float N3_Modif_Max;
        float * N3_Tab_Etat_de_Modif;
        float N3_Taux_Modif;
        bool N3_retrecissement;
        bool N3_Premier_Boucle;
        int N3_Etat_de_Modif;
        bool N3_Pair;
        float N3_Hauteur_Min_Obstacle;

//_____________________________________________________________________________        
        /**
         * @brief Ce constructeur initialise les données membres de la classe Niveau
         * 
         * @param Nbr_Obstacle: un entier qui correspond au nombre d'obstacle totale
         * @param H_Obstacle: un float qui correspond à la hauteur initial d'obstacle
         */
        Niveaux(int Nbr_Obstacle, float H_Obstacle);

//_____________________________________________________________________________
        /**
         * @brief Ce destructeur désalloue les mémoire loué par les données membres
         * "N2_Tab_Direction", "N3_Tab_Etat_de_Modif".
         * 
         */
        ~Niveaux();
//_____________________________________________________________________________
        /**
         * @brief Ce procédure bouge toute les obstacle verticalement vers le
         * bas
         * 
         * @param Obs: un donnée resultat de type classe Obstacle.
         */
        void N1_Mouv_Verticale(Obstacle &Obs);

//_____________________________________________________________________________
        /**
         * @brief Ce procédure bouge toute les obstacle horizontalement vers
         * la gauche/droite
         * 
         * @param Obs: un donnée resultat de type classe Obstacle.
         * @param TailleEcranX: un int: la largeur de la fenêtre du jeu
         * @param Niveau_Joueur: un int: le niveau actuelle du joueur dans le
         * jeu.
         */
        void N2_Mouv_Horizontale(Obstacle &Obs, int TailleEcranX, int Niveau_Joueur);
//_____________________________________________________________________________
        /**
         * @brief Ce procédure retrecis UN obstacle dont l'indice de la case est 
         * donnée en paramettre
         * 
         * @param Obs: un donnée resultat de type classe Obstacle.
         * @param Indice_Pos: un entier qui correspond à l'indice de la
         * case contenant l'obstacle dont on veut modifier la taille.
         */
        void N3_Retrecissement(Obstacle &Obs, int Indice_Pos);
//_____________________________________________________________________________
        /**
         * @brief Ce procédure agrandis UN obstacle dont l'indice de la case est 
         * donnée en paramettre
         * 
         * @param Obs: un donnée resultat de type classe Obstacle.
         * @param Indice_Pos: un entier qui correspond à l'indice de la
         * case contenant l'obstacle dont on veut modifier la taille.
         */
        void N3_Agrandissement(Obstacle &Obs, int Indice_Pos);

//_____________________________________________________________________________
        /**
         * @brief Cette procedure appelle les procedures "N3_Agrandissement" et
         * "N3_Retrecissement" en fonction des donnée membre "N3_retrecissement"
         * et "N3_Pair" dont les contenus seront modifié dans cette procedure.
         * cette procédure incrémente/décremente aussi la donnée membre
         * "N3_Etat_de_Modif"
         * 
         * @param Obs: un donnée resultat de type classe Obstacle.
         * @param Niveau_Joueur: un entier qui correspond au niveau actuelle
         * du joueur dans le jeu.
         */
        void N3_Modif_Des_Coords(Obstacle &Obs, int Niveau_Joueur);

};

#endif
