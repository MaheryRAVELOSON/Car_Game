#include "Voiture.h"
#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

using namespace std;

//_____________________________________________________________________________
Voiture::Voiture(int TailleEcranX, int TailleExranY)
{
    
    Voiture_Position= new Position;
    int Pourcent= 10;
    int R= Pourcent*TailleEcranX/100;
    Voiture_Position->setRayon(R);
    /* la voiture sera un forme de carré dont chaque coté sera de longeur
    "Pourcent"%*2 de la largeur de l'écran" */

    Pourcent= 5;
    Deplacement= Pourcent*TailleExranX/100;
    /*La voiture se déplace de "Pourcent"% à chaque fois*/

    Voiture_Position->setCentreX(TailleEcranX/2);
    Voiture_Position->setCentreY(TailleExranY-R);
    /*On itialise la position de la voiture Toute en bas au centre de la
    fenetre*/
}


//_____________________________________________________________________________
Voiture::~Voiture()
{
    delete Voiture_Position;
}


//_____________________________________________________________________________
void Voiture::Deplacer_Gauche()
{
    (* Voiture_Position).setCentreX(Voiture_Position->getCentreX-
    Deplacement);
    /*le setCentreX modifie automatiquement le X1 et X2*/

    if (Voiture_Position->getX1()<0)
    {
        Voiture_Position->setCentreX(Voiture_Position->getRayon());
    }
}

//_____________________________________________________________________________
void Voiture::Deplacer_Droite(int TailleEcranX)
{
    (* Voiture_Position).setCentreX(Voiture_Position->getCentreX-
    Deplacement);
    /*le setCentreX modifie automatiquement le X1 et X2*/

    if (Voiture_Position->getX1()> TailleEcranX)
    {
        Voiture_Position->setCentreX(TailleEcranX - Voiture_Position->getRayon());
    }
}