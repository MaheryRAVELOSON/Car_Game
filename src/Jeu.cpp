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
    //Score_Joueur= new Score;
    Score_Joueur.score=0;

    Obs= new Obstacle(20, Ptr_Voiture->Voiture_Position->Largeur, Ptr_Voiture->Deplacement);


    Obs->Init_Obstacle(TailleX);

    Niv = new Niveaux(Obs->TailleTab_Obstacle);

}


//_____________________________________________________________________________
Jeu::~Jeu()
{
    delete  Ptr_Voiture;
    //delete Score_Joueur;
    delete Obs;

    delete Niv;
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
    PtrJeu->Ptr_Voiture->Deplacement - (PtrJeu->Ptr_Voiture->Voiture_Position->Largeur/2));
    

    PtrJeu->Ptr_Voiture->Deplacer_Droite(PtrJeu->TailleX);
    assert(PtrJeu->Ptr_Voiture->Voiture_Position->getX2()==(PtrJeu->TailleX)/2 + 
    (PtrJeu->Ptr_Voiture->Voiture_Position->Largeur)/2);

    
    PtrJeu->Ptr_Voiture->Deplacer_Bas(2, PtrJeu->TailleY);
    assert(PtrJeu->Ptr_Voiture->Voiture_Position->getY2()==PtrJeu->TailleY);


    PtrJeu->Ptr_Voiture->Deplacer_Haut(2);
    assert(PtrJeu->Ptr_Voiture->Voiture_Position->getY1()==PtrJeu->TailleY-
    (PtrJeu->Ptr_Voiture->Voiture_Position->Hauteur + PtrJeu->Ptr_Voiture->Deplacement  ));


    PtrJeu->Ptr_Voiture->Deplacer_Bas(2, PtrJeu->TailleY);
    assert(PtrJeu->Ptr_Voiture->Voiture_Position->getY1()==PtrJeu->TailleY-
    (PtrJeu->Ptr_Voiture->Voiture_Position->Hauteur));



    cout<<endl<<endl<<"--Test de Regression 'Jeu' et 'Voiture' terminée--"<<endl<<endl;



    //PtrJeu->Obs.Init_Obstacle();
    for (int i=0; i<PtrJeu->Obs->TailleTab_Obstacle; i++)
    {
        cout<<endl<<"X1: "<<PtrJeu->Obs->Tab_Obstacle[i].getX1()<<
            "  X2: "<<PtrJeu->Obs->Tab_Obstacle[i].getX2()<<
            "  Y1: "<<PtrJeu->Obs->Tab_Obstacle[i].getY1()<<
            "  Y2: "<<PtrJeu->Obs->Tab_Obstacle[i].getY2()<<endl;
    }

    
    cout<<endl<<endl<<"mouvement verticale de: "<<endl;
    PtrJeu->Niv->N1_Mouv_Verticale((* PtrJeu->Obs));
    for (int i=0; i<PtrJeu->Obs->TailleTab_Obstacle; i++)
    {
        cout<<endl<<"X1: "<<PtrJeu->Obs->Tab_Obstacle[i].getX1()<<
            "  X2: "<<PtrJeu->Obs->Tab_Obstacle[i].getX2()<<
            "  Y1: "<<PtrJeu->Obs->Tab_Obstacle[i].getY1()<<
            "  Y2: "<<PtrJeu->Obs->Tab_Obstacle[i].getY2()<<endl;
    }

    cout<<endl<<endl<<"--Test de Regression 'Obstacle' depuis la classe 'Jeu'--"<<endl<<endl;


    delete PtrJeu;
}
