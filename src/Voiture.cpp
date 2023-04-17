#include "Voiture.h"
#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

using namespace std;

//_____________________________________________________________________________
Voiture::Voiture(int TailleEcranX, int TailleEcranY)
{
    
    Voiture_Position= new Position;

    int Pourcent= 10;
    Largeur= Pourcent*TailleEcranX/100;

    Pourcent=12;
    Hauteur= Pourcent*TailleEcranX/100;

    Voiture_Position->setX1((TailleEcranX/2) - (Largeur/2));
    Voiture_Position->setX2(Voiture_Position->getX1() + Largeur);

    Voiture_Position->setY2(TailleEcranY);
    Voiture_Position->setY1(TailleEcranY - Hauteur);
    

    Pourcent= 5;
    Deplacement= Pourcent*TailleEcranX/100;
    /*La voiture se déplace de "Pourcent"% à chaque fois*/
}


//_____________________________________________________________________________
Voiture::~Voiture()
{
    delete Voiture_Position;
}


//_____________________________________________________________________________
void Voiture::Deplacer_Gauche()
{

    (* Voiture_Position).setX1(Voiture_Position->getX1()-Deplacement);
    (* Voiture_Position).setX2(Voiture_Position->getX1() + Largeur);

    if (Voiture_Position->getX1()<0)
    {
        (* Voiture_Position).setX1(0);
        (* Voiture_Position).setX2(Largeur);
    }
}

//_____________________________________________________________________________
void Voiture::Deplacer_Droite(int TailleEcranX)
{

    (* Voiture_Position).setX1(Voiture_Position->getX1() + Deplacement);
    (* Voiture_Position).setX2(Voiture_Position->getX1() + Largeur);

    if (Voiture_Position->getX2()> TailleEcranX)
    {
        (* Voiture_Position).setX1(TailleEcranX - Largeur);
        (* Voiture_Position).setX2(Voiture_Position->getX1() + Largeur);
    }
}


//_____________________________________________________________________________
void Voiture::Deplacer_Haut(int Niveau)
{
    if (Niveau == 2)
    {

        (* Voiture_Position).setY1(Voiture_Position->getY1() - Deplacement);
        (* Voiture_Position).setY2(Voiture_Position->getY1() + Hauteur);

        if (Voiture_Position->getY1()<0)
        {
            (* Voiture_Position).setY1(0);
            (* Voiture_Position).setY2(Hauteur);
        }

    }

}


//_____________________________________________________________________________
void Voiture::Deplacer_Bas(int Niveau , int TailleEcranY)
{
    if (Niveau == 2)
    {
        (* Voiture_Position).setY1(Voiture_Position->getY1() + Deplacement);
        (* Voiture_Position).setY2(Voiture_Position->getY1() + Hauteur);
        
        if (Voiture_Position->getY2()>TailleEcranY)
        {
            (* Voiture_Position).setY1(TailleEcranY - Hauteur);
            (* Voiture_Position).setY2(Voiture_Position->getY1() + Hauteur);
        }

    }

}