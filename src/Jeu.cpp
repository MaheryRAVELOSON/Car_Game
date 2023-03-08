#include "Jeu.h"
#include <iostream>
#include <cassert>
#include <stdlib.h> // pour le abs
#include <math.h>

using namespace std;

//_____________________________________________________________________________
Jeu::Jeu()
{
    TailleX= 400;
    TailleY= 400;
}

//_____________________________________________________________________________
void Jeu::TestRegression()
{
    Jeu * PtrJeu= new Jeu;


    assert(PtrJeu->TailleX==400);

    (* PtrJeu).TailleY=400;
    assert((* PtrJeu).TailleY==400);

    cout<<endl<<endl<<"--Test de Regression 'Jeu' terminée--"<<endl<<endl;


    delete PtrJeu;
}
