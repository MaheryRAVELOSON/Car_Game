#include "Jeu.h"
#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

using namespace std;

//_____________________________________________________________________________
Jeu::Jeu()
{
    TailleX= 600;
    TailleY= 800;
    Niveau = 1;
    Ptr_Voiture= new Voiture(TailleX,TailleY);
    Score_Joueur= new Score;
    S_D_L.Voiture_Joeur_Sdl= Ptr_Voiture;
    S_D_L.TailleEcran_X_sdl= TailleX;
    S_D_L.TailleEcran_Y_sdl= TailleY;
    S_D_L.Niveau_Sdl= &Niveau;

}


//_____________________________________________________________________________
Jeu::~Jeu()
{
    delete  Ptr_Voiture;
    delete Score_Joueur;
}


//_____________________________________________________________________________
void Jeu::TestRegression()
{
    Jeu * PtrJeu= new Jeu;


    assert(PtrJeu->TailleX==600);

    (* PtrJeu).TailleY=400;
    assert((* PtrJeu).TailleY==400);
    
    PtrJeu->Ptr_Voiture->Deplacer_Gauche();
    assert(PtrJeu->Ptr_Voiture->Voiture_Position->getX1()==(PtrJeu->TailleX)/2 - 
    PtrJeu->Ptr_Voiture->Voiture_Position->getRayon()- 
    PtrJeu->Ptr_Voiture->Deplacement);
    

    PtrJeu->Ptr_Voiture->Deplacer_Droite(PtrJeu->TailleX);
    assert(PtrJeu->Ptr_Voiture->Voiture_Position->getX2()==(PtrJeu->TailleX)/2 + 
    PtrJeu->Ptr_Voiture->Voiture_Position->getRayon());

    
    PtrJeu->Ptr_Voiture->Deplacer_Bas(2, PtrJeu->TailleY);
    assert(PtrJeu->Ptr_Voiture->Voiture_Position->getY2()==PtrJeu->TailleY);


    PtrJeu->Ptr_Voiture->Deplacer_Haut(2);
    assert(PtrJeu->Ptr_Voiture->Voiture_Position->getY1()==PtrJeu->TailleY-
    (PtrJeu->Ptr_Voiture->Voiture_Position->getRayon()*2+PtrJeu
    ->Ptr_Voiture->Deplacement  ));


    PtrJeu->Ptr_Voiture->Deplacer_Bas(2, PtrJeu->TailleY);
    assert(PtrJeu->Ptr_Voiture->Voiture_Position->getY1()==PtrJeu->TailleY-
    (PtrJeu->Ptr_Voiture->Voiture_Position->getRayon()*2));



    cout<<endl<<endl<<"--Test de Regression 'Jeu' et 'Voiture' terminée--"<<endl<<endl;


    delete PtrJeu;
}
