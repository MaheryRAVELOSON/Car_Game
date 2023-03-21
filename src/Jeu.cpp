#include "Jeu.h"
#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

using namespace std;

//_____________________________________________________________________________
Jeu::Jeu(int X, int Y)
{
    TailleX= X;
    TailleY= Y;
    Niveau = 1;
    Ptr_Voiture= new Voiture(TailleX,TailleY);
    Score_Joueur= new Score;

    S_D_L.Voiture_Joeur_Sdl= Ptr_Voiture;
    S_D_L.TailleEcran_X_sdl= TailleX;
    S_D_L.TailleEcran_Y_sdl= TailleY;
    S_D_L.Niveau_Sdl= &Niveau;

    Obs.Niveau_Obstacle = &Niveau;
    Obs.TailleEcranX_Obstacle= &TailleX;
    Obs.TailleEcranY_Obstacle= &TailleY;
    Obs.RayonVoiture= Ptr_Voiture->Voiture_Position->getRayon();
    Obs.Score_Obstacle = Score_Joueur;
    Obs.Deplacement_Obstacle= &(Ptr_Voiture->Deplacement);

    S_D_L.ObstacleSdl = &Obs;

    //Obs.Init_Obstacle();

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



    //PtrJeu->Obs.Init_Obstacle();
    for (int i=0; i<PtrJeu->Obs.TailleTab_Obstacle; i++)
    {
        cout<<endl<<"X1: "<<PtrJeu->Obs.Tab_Obstacle[i].getX1()<<
            "  X2: "<<PtrJeu->Obs.Tab_Obstacle[i].getX2()<<
            "  Y1: "<<PtrJeu->Obs.Tab_Obstacle[i].getY1()<<
            "  Y2: "<<PtrJeu->Obs.Tab_Obstacle[i].getY2()<<endl;
    }

    cout<<endl<<endl<<"mouvement verticale de: "<<endl;
    PtrJeu->Obs.Mouv_Obs_Verticale();
    for (int i=0; i<PtrJeu->Obs.TailleTab_Obstacle; i++)
    {
        cout<<endl<<"X1: "<<PtrJeu->Obs.Tab_Obstacle[i].getX1()<<
            "  X2: "<<PtrJeu->Obs.Tab_Obstacle[i].getX2()<<
            "  Y1: "<<PtrJeu->Obs.Tab_Obstacle[i].getY1()<<
            "  Y2: "<<PtrJeu->Obs.Tab_Obstacle[i].getY2()<<endl;
    }

    cout<<endl<<endl<<"--Test de Regression 'Obstacle' depuis la classe 'Jeu'--"<<endl<<endl;


    delete PtrJeu;
}
